

#ifndef SRC_PARSER_H
#define SRC_PARSER_H

#include <string>

class Moduling : public setModule {
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

    unordered_map<std::shared_ptr<Modeling::Variable>, std::string> vars;
    unordered_map<std::string, std::shared_ptr<Modeling::Unit>> units;
    unordered_map<std::string, std::unordered_set<std::string>> capsules;
    shared_ptr<Modeling::BaseType> real = std::make_shared<Modeling::BaseType>("Real");
    shared_ptr<Modeling::BaseType> boolean = std::make_shared<Modeling::BaseType>("Boolean");
    shared_ptr<Modeling::BaseType> integer = std::make_shared<Modeling::BaseType>("Integer");
    shared_ptr<Modeling::BaseType> stringa = std::make_shared<Modeling::BaseType>("String");
};

#endif //SRC_PARSER_H