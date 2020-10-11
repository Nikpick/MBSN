//
// Created by Simone on 18/09/2019.
//

#ifndef SRC_PARSER_H
#define SRC_PARSER_H

#include <string>
#include <libxml++/libxml++.h>
#include <Model/Unit.h>
#include <Model/Module.h>
#include <Model/BaseType.h>
#include <Model/BuiltInOp.h>
#include <Model/Parameter.h>

class Parser : public xmlpp::DomParser {
private:
	unsigned int i = 1;
	std::unordered_map<std::shared_ptr<Modeling::Variable>, std::string> vars;
	std::unordered_map<std::string, std::shared_ptr<Modeling::Unit>> units;
	std::unordered_map<std::string, std::unordered_set<std::string>> capsules;
	std::shared_ptr<Modeling::BaseType> real = std::make_shared<Modeling::BaseType>("Real");
	std::shared_ptr<Modeling::BaseType> boolean = std::make_shared<Modeling::BaseType>("Boolean");
	std::shared_ptr<Modeling::BaseType> integer = std::make_shared<Modeling::BaseType>("Integer");
	std::shared_ptr<Modeling::BaseType> stringa = std::make_shared<Modeling::BaseType>("String");
	std::shared_ptr<Modeling::Type> find_basetype(const std::string& typeVal);
	std::shared_ptr<Modeling::Unit> find_unit(const std::string& id);
	void get_units_from_phml(const xmlpp::Node* node);
	void get_modules_from_phml(const xmlpp::Node* node, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules);
	static std::shared_ptr<Modeling::Module> find_module(const std::string& id, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules);
	std::shared_ptr<Modeling::Module> create_module(const std::string& prefixName, const xmlpp::Node* node, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules);
	static bool existing_module(const std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules, const std::string& module_name);
	std::shared_ptr<Modeling::Variable> find_variable(const std::string& port_id, const std::string& module_id, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules);
	void get_variable_from_phml(const xmlpp::Node* var, std::shared_ptr<Modeling::Module>& mod);
	std::string get_module_connection(const std::string& mod_in, const std::string& mod_out);
	bool isCapsulated(const std::string& mod_id);
	void get_connection_from_phml(const xmlpp::Node* node, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules);
	static bool find_variable_in_vars(const std::unordered_set<std::shared_ptr<Modeling::Variable>>& vars, const std::shared_ptr<Modeling::Variable>& var);
	static std::string buildStringMathMl(const xmlpp::Node* var);
	static std::string mathMl2String(const std::string& xml, bool conditional = false);
	static void unsupported_constructs(const xmlpp::Node* var);
	static std::string get_implementation(const xmlpp::Node* var, bool extra_implementation);
	static std::string get_implementation_in_conditional(const xmlpp::Node* var);
public:
	std::string method;
	std::string stopTime;
    explicit Parser(const std::string& filepath);
    void visit_tree(const xmlpp::Node* node, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>>& modules);
};

#endif //SRC_PARSER_H