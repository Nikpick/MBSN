//
// Created by Simone on 18/09/2019.
//

#include "Parser.h"
#include <sbml/SBMLTypes.h>
#include <regex>
#include "../cpp/Model/Species.h"
#include "../cpp/Model/DirConnection.h"
#include "../utils/exceptions/NoTypeFoundException.cpp"
#include "../utils/exceptions/NoUnitFoundException.cpp"
#include "../utils/exceptions/NoModuleFoundException.cpp"
#include "../utils/exceptions/NoVariableFoundException.cpp"
#include "../utils/exceptions/NoModuleConnectionException.cpp"
#include "../utils/exceptions/NotSupportedException.cpp"
#include <iostream>

Parser::Parser(const std::string& filepath) {
    std::cout << "Start parsing..." << std::endl;
    parse_file(filepath);
    std::cout << "Parsing Finished!" << std::endl;
}

std::shared_ptr<Modeling::Unit> Parser::find_unit(const std::string& id) {
	if (Parser::units.find(id) != Parser::units.end())
		return Parser::units.find(id)->second;
	else
		return Parser::units.find("0")->second;
		//throw NoUnitFoundException();
}

std::shared_ptr<Modeling::Type> Parser::find_basetype(const std::string& typeVal) {
	std::shared_ptr<Modeling::Type> type;
	if (typeVal == "double")
		type = real;
	else if(typeVal == "integer")
		type = integer;
	else if (typeVal == "bool")
		type = boolean;
	else if (typeVal == "string")
		type = stringa;
	else
		throw NoTypeFoundException();
	return type;
}

void Parser::get_units_from_phml(const xmlpp::Node* node) {
    if (node->get_name() == "unit") {
		units.insert(std::make_pair(dynamic_cast<const xmlpp::Element*>(node)->get_attribute("unit-id")->get_value(), std::make_shared<Modeling::Unit>(std::regex_replace(std::string(dynamic_cast<const xmlpp::TextNode*>(node->get_first_child("name")->get_first_child("text"))->get_content()), std::regex(R"(_|-| )"), ""))));
    }
}

void Parser::get_modules_from_phml(const xmlpp::Node *node, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules) {
    if (node->get_name() == "module") {
    	std::shared_ptr<Modeling::Module> mod;
    	if (node->get_first_child("property")->get_first_child("capsulation") and dynamic_cast<const xmlpp::Element*>(node->get_first_child("property")->get_first_child("capsulation"))->get_attribute("state")->get_value() == "true") {
    		capsules[dynamic_cast<const xmlpp::Element*>(node->get_first_child("property")->get_first_child("capsulation")->get_first_child("capsulated-by"))->get_attribute("module-id")->get_value()].insert(dynamic_cast<const xmlpp::Element*>(node)->get_attribute("module-id")->get_value());
    	}
    	if (dynamic_cast<const xmlpp::Element*>(node)->get_attribute("type")->get_value() == "functional-unit") {
    		mod = create_module("class_", node, modules);
    	}
    	else if (dynamic_cast<const xmlpp::Element*>(node)->get_attribute("type")->get_value() == "capsule" or dynamic_cast<const xmlpp::Element*>(node)->get_attribute("type")->get_value() == "container")
    		mod = create_module("capsule_", node, modules);
    	modules.insert(std::make_pair(dynamic_cast<const xmlpp::Element*>(node)->get_attribute("module-id")->get_value(), mod));
	}
}

std::string Parser::buildStringMathMl(const xmlpp::Node *var) {
	std::string xml;
	xmlpp::Document math;
	math.create_root_node_by_import(var);
	xml =  math.write_to_string();
	xml = std::regex_replace(xml, std::regex("m:"), "");
	std::regex der(R"((^|\r?\n)*<diff\/>(^|\r?\n|.)*<\/bvar>)");
	xml = std::regex_replace(xml, der, "<csymbol>der</csymbol>");
	std::regex delay(R"((^|\r?\n)*<csymbol>(^|\r?\n)*Delay(^|\r?\n)*</csymbol>(^|\r?\n)*)");
	xml = std::regex_replace(xml, delay, "<csymbol>delay</csymbol>");
	return xml;
}

std::string Parser::mathMl2String(const std::string& xml, bool conditional) {
	ASTNode* ast = readMathMLFromString(xml.c_str());
	std::string result = SBML_formulaToL3String(ast);
	if (!conditional)
		result = std::regex_replace(result, std::regex("=="), "=");
	result = std::regex_replace(result, std::regex("!="), "<>");
	result = std::regex_replace(result, std::regex("&&"), "and");
	result = std::regex_replace(result, std::regex(R"(\|\|)"), "or");
	result = std::regex_replace(result, std::regex(R"(ln\()"), "log(");
	result = std::regex_replace(result, std::regex(R"(\ (-[0-9]+\.*[0-9]*(e(\+|-)*[0-9]*)*)))"), R"( ($1))");
	result = std::regex_replace(result, std::regex(R"(\^(-[0-9]+\.*[0-9]*))"), R"( ^($1))");
	return result;
}

void Parser::unsupported_constructs(const xmlpp::Node *var) {
	if (dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "assign" and dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("sub-type")->get_value() == "timeseries")
		throw NotSupportedException("timeseries construct");
	else if ( dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "assign" and dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("sub-type")->get_value() == "bridge")
		throw NotSupportedException("bridge construct");
	else if (dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "func-expression")
		throw NotSupportedException("func-expression construct");
	else if (dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "morphology")
		throw NotSupportedException("morphology construct");
	else if (dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "graph")
		throw NotSupportedException("graph construct");
	else if (dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "loop")
		throw NotSupportedException("loop construct");
	else if (dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "pde")
		throw NotSupportedException("partial differential equation ");
	else if (var->get_name() == "extra-implementation" and dynamic_cast<const xmlpp::Element *>(var)->get_attribute("type")->get_value() == "multiple-input-assignment")
		throw NotSupportedException("multiple-input-assignment construct");
}

std::string Parser::get_implementation(const xmlpp::Node *var, bool extra_implementation = false) {
	std::string result;
	unsupported_constructs(var);
	if (dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "ae" or dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "ode" or dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "dde") {
		result = mathMl2String(buildStringMathMl(var->get_first_child("definition")->get_first_child("math")));
	} else if (dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "conditional") {
		std::vector<const xmlpp::Node*> children;
		for (const auto& child : var->get_first_child("definition")->get_first_child("case-set")->get_children()) {
			if (!dynamic_cast<const xmlpp::TextNode*>(child))
				children.push_back(child);
		}
		if (extra_implementation)
			result = "when ";
		else
			result = "if ";
		result = result + mathMl2String(buildStringMathMl(var->get_first_child("definition")->get_first_child("case-set")->get_first_child("case")->get_first_child("condition")->get_first_child("math")), true) + " then\n";
		result = result + "\t" + get_implementation_in_conditional(children[0]) + ";\n";
		if (children.size() > 1) {
			if (extra_implementation)
				result = result + "\telsewhen not(" + mathMl2String(buildStringMathMl(var->get_first_child("definition")->get_first_child("case-set")->get_first_child("case")->get_first_child("condition")->get_first_child("math")), true) + ") then\n";
			else
				result = result + "\telse\n";
			result = result + "\t" + get_implementation_in_conditional(children[1]) + ";\n";
		}
		if (extra_implementation)
			result = result + "\tend when";
		else
			result = result + "\tend if";
	}
	return result;
}

std::string Parser::get_implementation_in_conditional(const xmlpp::Node *var) {
	std::string result;
	unsupported_constructs(var);
	if (dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "ae" or dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "ode" or dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "ode") {
		result = mathMl2String(buildStringMathMl(var->get_first_child("definition")->get_first_child("math")));
		if (var->get_parent()->get_name() == "extra-implementation" or var->get_parent()->get_parent()->get_parent()->get_name() == "extra-implementation") {
			result = "reinit(" + std::string(result.substr(0,result.rfind('='))) + "," + std::string(result.substr(result.rfind('=') + 1)) + ")";
		}
	} else if (dynamic_cast<const xmlpp::Element *>(var->get_first_child("definition"))->get_attribute("type")->get_value() == "conditional") {
		std::vector<const xmlpp::Node*> children;
		for (const auto& child : var->get_first_child("definition")->get_first_child("case-set")->get_children()) {
			if (!dynamic_cast<const xmlpp::TextNode*>(child))
				children.push_back(child);
		}
		result = "if " + mathMl2String(buildStringMathMl(var->get_first_child("definition")->get_first_child("case-set")->get_first_child("case")->get_first_child("condition")->get_first_child("math")), true) + " then\n";
		result = result + "\t" + get_implementation_in_conditional(children[0]) + ";\n";
		if (children.size() > 1) {
			result = result + "\telse\n" + "\t" + get_implementation_in_conditional(children[1]) + ";\n";
		}
		result = result + "\tend if";
	}
	return result;
}

void Parser::get_variable_from_phml(const xmlpp::Node *var, std::shared_ptr<Modeling::Module> &mod) {
	std::shared_ptr<Modeling::Variable> variable;
	if (var->get_name() == "physical-quantity") {
		auto physical_quantity_type =  dynamic_cast<const xmlpp::Element*>(var)->get_attribute("type")->get_value();
		if (physical_quantity_type == "morphology")
			throw NotSupportedException("morphology type constuct");
		auto unit = find_unit(dynamic_cast<const xmlpp::Element *>(var->get_first_child("value-type-set")->get_first_child("value-type"))->get_attribute("unit-id")->get_value());
		auto type = find_basetype(dynamic_cast<const xmlpp::Element *>(var->get_first_child("value-type-set")->get_first_child("value-type"))->get_attribute("precision")->get_value());
		bool inp = (dynamic_cast<const xmlpp::Element*>(var->get_first_child("implementation")->get_first_child("definition"))->get_attribute("format") and dynamic_cast<const xmlpp::Element*>(var->get_first_child("implementation")->get_first_child("definition"))->get_attribute("format")->get_value() == "reference" and dynamic_cast<const xmlpp::Element*>(var->get_first_child("implementation")->get_first_child("definition"))->get_attribute("type")->get_value() == "assign" and dynamic_cast<const xmlpp::Element*>(var->get_first_child("implementation")->get_first_child("definition"))->get_attribute("sub-type")->get_value() == "port");
		bool out = false;
		std::string port_id;
		if (inp)
			port_id = dynamic_cast<const xmlpp::Element *>(var->get_first_child("implementation")->get_first_child("definition")->get_first_child("reference"))->get_attribute("port-id")->get_value();
		else {
			if (var->get_parent()->get_parent()->get_first_child("port-set")) {
				for (auto port : var->get_parent()->get_parent()->get_first_child("port-set")->get_children())
					if (port->get_name() == "port" and
						dynamic_cast<const xmlpp::Element *>(port)->get_attribute("direction")->get_value() == "out" and
						dynamic_cast<const xmlpp::Element *>(port)->get_attribute("ref-physical-quantity-id")->get_value() ==
						dynamic_cast<const xmlpp::Element *>(var)->get_attribute("physical-quantity-id")->get_value()) {
						out = true;
						port_id = dynamic_cast<const xmlpp::Element *>(port)->get_attribute("port-id")->get_value();
					}
			}
		}
		std::string var_name = dynamic_cast<const xmlpp::TextNode*>(var->get_first_child("name")->get_first_child("text"))->get_content();
		std::replace(var_name.begin(), var_name.end(), ' ', '_');
		std::replace(var_name.begin(), var_name.end(), '-', '_');
		if (physical_quantity_type == "variable-parameter")
			variable = std::make_shared<Modeling::Parameter>(var_name, unit, type, inp, out);
		else if (physical_quantity_type == "static-parameter")
			variable = std::make_shared<Modeling::Parameter>(var_name, unit, type, inp, out, true);
		else if (physical_quantity_type == "state")
			variable = std::make_shared<Modeling::Species>(var_name, unit, type, inp, out);
		variable->setModule(mod);
		if (std::dynamic_pointer_cast<Modeling::Species>(variable)) {
			variable->addInitialAss(get_implementation(var->get_first_child("initial-value")));
		}

		if (std::dynamic_pointer_cast<Modeling::Parameter>(variable) and std::dynamic_pointer_cast<Modeling::Parameter>(variable)->isStatic()) {
			variable->addInitialAss(get_implementation(var->get_first_child("implementation")));
		}
		else {
			std::string res = get_implementation(var->get_first_child("implementation"));
			if (!res.empty())
				mod->addExpression(res);
		}
		if (var->get_first_child("implementation")->get_first_child("extra-implementation")) {
			std::string res = get_implementation(var->get_first_child("implementation")->get_first_child("extra-implementation"), true);
			if (!res.empty())
				mod->addExpression(res);
		}
		vars.insert(std::make_pair(variable, port_id));
	}
}

bool Parser::existing_module(const std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules, const std::string& module_name) {
	for (const auto& module : modules)
		if (module.second->getName() == module_name)
			return true;
	return false;
}

std::shared_ptr<Modeling::Module> Parser::create_module(const std::string& namePrefix, const xmlpp::Node *node, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules) {
	std::string module_name = std::string(namePrefix + dynamic_cast<const xmlpp::TextNode *>(node->get_first_child("property")->get_first_child("name")->get_first_child("text"))->get_content());
	module_name = std::regex_replace(module_name, std::regex(R"(\+)"), "");
	module_name = std::regex_replace(module_name, std::regex(R"(\.)"), "");
	if (existing_module(modules, module_name)) {
		module_name = std::string(module_name + "_" + std::to_string(i));
		i += 1;
	}
	std::replace(module_name.begin(), module_name.end(), ' ', '_');
	std::replace(module_name.begin(), module_name.end(), '-', '_');
	auto mod = std::make_shared<Modeling::Module>(module_name);
	std::shared_ptr<Modeling::Variable> variable;
	if (dynamic_cast<const xmlpp::Element*>(node)->get_attribute("type")->get_value() == "functional-unit") {
		for (auto var : node->get_first_child("physical-quantity-set")->get_children()) {
			get_variable_from_phml(var, mod);
		}
	}
	else if (dynamic_cast<const xmlpp::Element*>(node)->get_attribute("type")->get_value() == "capsule" and node->get_first_child("port-set") and node->get_first_child("port-set")->get_children().size() != 1) {
		for (auto var : node->get_first_child("port-set")->get_children()) {
			auto unit = find_unit("0");
			auto type = std::dynamic_pointer_cast<Modeling::Type>(real);
			if (var->get_name() == "port") {
				if (dynamic_cast<const xmlpp::Element*>(var)->get_attribute("direction")->get_value() == "in")
					variable = std::make_shared<Modeling::Parameter>(std::string("port_" + dynamic_cast<const xmlpp::Element*>(var)->get_attribute("port-id")->get_value()), unit, type, true);
				else if (dynamic_cast<const xmlpp::Element*>(var)->get_attribute("direction")->get_value() == "out")
					variable = std::make_shared<Modeling::Parameter>(std::string("port_" + dynamic_cast<const xmlpp::Element*>(var)->get_attribute("port-id")->get_value()), unit, type, false, true);
				variable->setModule(mod);
				vars.insert(std::make_pair(variable, dynamic_cast<const xmlpp::Element*>(var)->get_attribute("port-id")->get_value()));
			}
		}
	}
	return mod;
}

std::shared_ptr<Modeling::Module> Parser::find_module(const std::string& id, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules) {
	if (modules[id])
		return modules[id];
	else
		throw NoModuleFoundException();
}

std::shared_ptr<Modeling::Variable> Parser::find_variable(const std::string &port_id, const std::string &module_id, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules) {
	for (const auto& var : vars)
		if (var.first->getModule().lock() == find_module(module_id, modules) and var.second == port_id)
			return var.first;
	throw NoVariableFoundException();
}

std::string Parser::get_module_connection(const std::string& mod_in, const std::string& mod_out) {
	for (const auto& capsule : capsules)
		if (capsule.second.find(mod_in) != capsule.second.end() and capsule.second.find(mod_out) != capsule.second.end())
			return capsule.first;
	throw NoModuleConnectionException();
}

bool Parser::isCapsulated(const std::string& mod_id) {
	for (const auto& capsule : capsules)
		if (capsule.second.find(mod_id) != capsule.second.end())
			return true;
	return false;
}

bool Parser::find_variable_in_vars(const std::unordered_set<std::shared_ptr<Modeling::Variable>>& vars, const std::shared_ptr<Modeling::Variable>& var) {
	for (const auto& v : vars)
		if (v->getName() == var->getName() and v->getType().lock() == var->getType().lock())
			return true;
		/*else if (v->getName() == var->getName())
			var->setName(std::string(var->getName() + std::to_string(1)));*/
	return false;
}

void Parser::get_connection_from_phml(const xmlpp::Node *node, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>> &modules) {
	if (node->get_name() == "edge") {
		std::shared_ptr<Modeling::Variable> in_var;
		std::shared_ptr<Modeling::Variable> out_var;
		std::shared_ptr<Modeling::Module> mod;
		if (dynamic_cast<const xmlpp::Element *>(node)->get_attribute("type")->get_value() == "capsular") {
			mod = find_module(dynamic_cast<const xmlpp::Element *>(node->get_first_child("head"))->get_attribute("module-id")->get_value(), modules);
			std::shared_ptr<Modeling::Type> class_mod = find_module(dynamic_cast<const xmlpp::Element *>(node->get_first_child("tail"))->get_attribute("module-id")->get_value(), modules);
			auto unit = find_unit("0");
			auto var = std::make_shared<Modeling::Parameter>(std::string("elem_" + class_mod->getName()), unit, class_mod);
			if (!find_variable_in_vars(mod->getVars(), var))
				var->setModule(mod);
		} else if (dynamic_cast<const xmlpp::Element *>(node)->get_attribute("type")->get_value() == "functional") {
			if (isCapsulated(dynamic_cast<const xmlpp::Element *>(node->get_first_child("tail"))->get_attribute("module-id")->get_value())) {
				mod = find_module(get_module_connection(dynamic_cast<const xmlpp::Element *>(node->get_first_child("tail"))->get_attribute("module-id")->get_value(), dynamic_cast<const xmlpp::Element *>(node->get_first_child("head"))->get_attribute("module-id")->get_value()), modules);
				in_var = find_variable(dynamic_cast<const xmlpp::Element *>(node->get_first_child("tail"))->get_attribute("port-id")->get_value(), dynamic_cast<const xmlpp::Element *>(node->get_first_child("tail"))->get_attribute("module-id")->get_value(), modules);
				out_var = find_variable(dynamic_cast<const xmlpp::Element *>(node->get_first_child("head"))->get_attribute("port-id")->get_value(), dynamic_cast<const xmlpp::Element *>(node->get_first_child("head"))->get_attribute("module-id")->get_value(), modules);
			} else {
				auto unit = find_unit("0");
				mod = modules["system"];
				std::shared_ptr<Modeling::Type> in_cap_type = find_module(dynamic_cast<const xmlpp::Element *>(node->get_first_child("tail"))->get_attribute("module-id")->get_value(), modules);
				std::shared_ptr<Modeling::Variable> in_cap = std::make_shared<Modeling::Parameter>(std::string("elem_" + in_cap_type->getName()), unit, in_cap_type);
				if (!find_variable_in_vars(mod->getVars(), in_cap))
					in_cap->setModule(mod);
				std::shared_ptr<Modeling::Type> out_cap_type = find_module(dynamic_cast<const xmlpp::Element *>(node->get_first_child("head"))->get_attribute("module-id")->get_value(), modules);
				std::shared_ptr<Modeling::Variable> out_cap = std::make_shared<Modeling::Parameter>(std::string("elem_" + out_cap_type->getName()), unit, out_cap_type);
				if (!find_variable_in_vars(mod->getVars(), out_cap))
					out_cap->setModule(mod);
				in_var = find_variable(dynamic_cast<const xmlpp::Element *>(node->get_first_child("tail"))->get_attribute("port-id")->get_value(), dynamic_cast<const xmlpp::Element *>(node->get_first_child("tail"))->get_attribute("module-id")->get_value(), modules);
				out_var = find_variable(dynamic_cast<const xmlpp::Element *>(node->get_first_child("head"))->get_attribute("port-id")->get_value(), dynamic_cast<const xmlpp::Element *>(node->get_first_child("head"))->get_attribute("module-id")->get_value(), modules);
			}
			std::shared_ptr<Modeling::DirConnection> conn = std::make_shared<Modeling::DirConnection>(in_var, out_var);
			conn->setModule(mod);
		} else if (dynamic_cast<const xmlpp::Element*>(node)->get_attribute("type")->get_value() == "forwarding") {
			in_var = find_variable(dynamic_cast<const xmlpp::Element *>(node->get_first_child("tail"))->get_attribute("port-id")->get_value(), dynamic_cast<const xmlpp::Element *>(node->get_first_child("tail"))->get_attribute("module-id")->get_value(), modules);
			out_var = find_variable(dynamic_cast<const xmlpp::Element *>(node->get_first_child("head"))->get_attribute("port-id")->get_value(), dynamic_cast<const xmlpp::Element *>(node->get_first_child("head"))->get_attribute("module-id")->get_value(), modules);
			if (in_var->isInput())
				mod = in_var->getModule().lock();
			else if (in_var->isOutput()) {
				mod = out_var->getModule().lock();
			}
			std::shared_ptr<Modeling::DirConnection> conn = std::make_shared<Modeling::DirConnection>(in_var, out_var);
			conn->setModule(mod);
		}
	}
}

void Parser::visit_tree(const xmlpp::Node *node, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules) {
    const auto nodeContent = dynamic_cast<const xmlpp::ContentNode*>(node);
    const auto nodeText = dynamic_cast<const xmlpp::TextNode*>(node);

    if(nodeText && nodeText->is_white_space())
        return ;

    const auto nodename = node->get_name();
    if (nodename == "numerical-configuration") {
		method = (node->get_first_child("algorithm") and node->get_first_child("algorithm")->get_first_child("integration")) ? dynamic_cast<const xmlpp::Element*>(node->get_first_child("algorithm")->get_first_child("integration"))->get_attribute("name")->get_value() : "euler";
		stopTime = node->get_first_child("simulation-time-span") ? dynamic_cast<const xmlpp::TextNode*>(node->get_first_child("simulation-time-span")->get_first_child("text"))->get_content() : "100";
    }
    else if (nodename == "unit") {
    	get_units_from_phml(node);
	}
    else if (nodename == "module") {
		get_modules_from_phml(node, modules);
	}
    else if (nodename == "template-set" and !node->get_children().empty())
    	throw NotSupportedException("template construct");
    else if (nodename == "edge-set") {
		auto unit = find_unit("0");
		for (const auto& capsule : capsules) {
			auto cap = find_module(capsule.first, modules);
			for (const auto& class_var : capsule.second) {
				std::shared_ptr<Modeling::Type> class_caps = find_module(class_var, modules);
				std::shared_ptr<Modeling::Variable> var = std::make_shared<Modeling::Parameter>(std::string("elem_" + class_caps->getName()), unit, class_caps);
				var->setModule(cap);
			}
		}
    }
    else if (nodename == "edge")
    	get_connection_from_phml(node, modules);
	if(!nodeContent) {
        for(const auto& child : node->get_children()) {
            visit_tree(child, modules);
        }
    }
}
