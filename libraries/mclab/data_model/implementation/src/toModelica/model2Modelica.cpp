//
// Created by Simone on 08/10/2019.
//

#include "model2Modelica.h"
#include <iostream>
#include <fstream>
#include <Model/Species.h>
#include <Model/Parameter.h>
#include <Model/Unit.h>
#include <Model/DirConnection.h>
#include <memory>
#include <algorithm>

model2Modelica::model2Modelica(const std::string& filepath, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>> modules, const std::string& stopTime, const std::string& method) : stopTime(stopTime), method(method) {

	std::cout << "Generating Modelica files..." << std::endl;

	std::string modelName;

	unsigned int caps = 0;
	for (auto const& mod : modules) {
		std::size_t found = mod.second->getName().find("capsule_");
		if (found != std::string::npos) {
			caps += 1;
			modelName = mod.second->getName();
		}
	}

	if (!modules["system"]->getVars().empty()) {
		modelName = "system";
	} else {
		modules.erase("system");
		if (caps != 1)
			modelName = "model_name";
	}

	std::vector<std::pair<std::string, std::shared_ptr<Modeling::Module>>> mods(modules.begin(), modules.end());
	std::sort(mods.begin(), mods.end());

	std::ofstream run;
	run.open(std::string(filepath.substr(0,filepath.rfind('/')) + "/" + "run.mos"));
	run << "loadModel(Modelica);\ngetErrorString();\n\n";

	unsigned int copies = 1;

	for (const auto& module : mods) {
		std::unordered_set<std::shared_ptr<Modeling::Species>> species;
		std::ofstream modelica_file;
		std::string modelica_file_name = module.second->getName();
		modelica_file.open (std::string(filepath.substr(0,filepath.rfind('/')) + "/" + modelica_file_name + ".mo"));
		modelica_file << "class " << modelica_file_name << "\n";
		for (const auto& var : module.second->getVars()) {
			modelica_file << "\t";
			if (var->isInput())
				modelica_file << "input ";
			else if (std::dynamic_pointer_cast<Modeling::Parameter>(var) and std::dynamic_pointer_cast<Modeling::Parameter>(var)->isStatic())
				modelica_file << "parameter ";
			modelica_file <<  var->getType().lock()->getName() << " " << var->getName();
			if (var->getUnit().lock()->getName() == "dimensionless") {
				if (isBaseType(var))
					modelica_file << "(unit=\"\")";
			} else
				modelica_file << "(unit=\"" << var->getUnit().lock()->getName() << "\")";
			if (std::dynamic_pointer_cast<Modeling::Parameter>(var) and std::dynamic_pointer_cast<Modeling::Parameter>(var)->isStatic())
				modelica_file << " " << var->getInitialAss().substr(var->getInitialAss().rfind('='));
			modelica_file << ";\n";
			if (std::dynamic_pointer_cast<Modeling::Species>(var)) {
				species.insert(std::dynamic_pointer_cast<Modeling::Species>(var));
			}
		}
		modelica_file << "initial equation\n";
		for (const auto& spec : species) {
			modelica_file << "\t" << spec->getInitialAss() << ";\n";
		}

		if (!module.second->getConnections().empty()) {
			for (const auto &conn : module.second->getConnections()) {
				std::string expr;
				if (std::dynamic_pointer_cast<Modeling::DirConnection>(conn)->getInVar().lock()->getModule().lock()->getName() ==
				module.second->getName())
					expr = std::dynamic_pointer_cast<Modeling::DirConnection>(conn)->getInVar().lock()->getName();
				else
					expr = "elem_" +
							std::dynamic_pointer_cast<Modeling::DirConnection>(conn)->getInVar().lock()->getModule().lock()->getName() +
							"." +
							std::dynamic_pointer_cast<Modeling::DirConnection>(conn)->getInVar().lock()->getName();
				expr += " = ";
				if (std::dynamic_pointer_cast<Modeling::DirConnection>(conn)->getOutVar().lock()->getModule().lock()->getName() ==
				module.second->getName())
					expr += std::dynamic_pointer_cast<Modeling::DirConnection>(conn)->getOutVar().lock()->getName();
				else
					expr += "elem_" +
							std::dynamic_pointer_cast<Modeling::DirConnection>(conn)->getOutVar().lock()->getModule().lock()->getName() +
							"." +
							std::dynamic_pointer_cast<Modeling::DirConnection>(conn)->getOutVar().lock()->getName();
				module.second->addExpression(expr);
			}
		}

		modelica_file << "\nequation\n";
		for (const auto& expr : module.second->getExpression()) {
			modelica_file << "\t" << expr <<  ";\n";
		}

		modelica_file << "\nend " << modelica_file_name << ";\n";
		modelica_file.close();
		run << "loadFile(\"" << module.second->getName() << ".mo" << "\");\ngetErrorString();\n\n";
		copies = copies;
	}

	std::ofstream makefile;
	makefile.open (std::string(filepath.substr(0,filepath.rfind('/')) + "/" + "Makefile"));
	makefile << "start:\n\tomc run.mos\n\nclean:\n\tfind . ! -name \"Makefile\" -and ! -name \"*.mo*\" ! -name \"*.phml\" ! -name \"*.csv\" -delete";
	makefile.close();
	std::string numberOfIntervals = stopTime + "000";
	run << "simulate(" << modelName << ", stopTime=" << stopTime << ", method=\"" << method << "\", numberOfIntervals=" << numberOfIntervals << ", outputFormat=\"csv\");\ngetErrorString();";
	run.close();

	std::cout << "Modelica files have been generated." << std::endl;
}

bool model2Modelica::isBaseType(const std::shared_ptr<Modeling::Variable>& var) {
	return var->getType().lock()->getName() == "Real" or var->getType().lock()->getName() == "Integer" or var->getType().lock()->getName() == "Boolean" or var->getType().lock()->getName() == "String";
}
