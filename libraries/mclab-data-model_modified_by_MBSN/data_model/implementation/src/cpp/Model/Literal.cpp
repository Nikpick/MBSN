//
// Created by Simone on 2019-08-18.
//

#include "Model/Literal.h"
#include "Model/Type.h"
#include "LiteralException.cpp"
#include <regex>

namespace Modeling {

	Literal::Literal(std::shared_ptr<Type> type, std::string val) : Expression(std::move(type)), value(std::move(val)) {
		std::regex realVal(R"(((\+|-)?[[:digit:]]+)(\.(([[:digit:]]+)?))?((e|E)((\+|-)?)[[:digit:]]+)?)");
		std::regex intVal(R"((\+|-)?[[:digit:]]+)");
		if (!((this->type->getName() == "Boolean" and (this->value == "true" or value == "false")) or
			  (this->type->getName() == "Real" and regex_match(value, realVal)) or
			  (this->type->getName() == "Integer" and regex_match(value, intVal))))
			throw LiteralException();
	}

	std::string Literal::getValue() {
		return value;
	}

}
