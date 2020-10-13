//
// Created by Simone on 2019-08-17.
//

#include "Model/Parameter.h"
#include "ParameterException.cpp"

namespace Modeling {

	Parameter::Parameter(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type)
			: Variable(std::move(name), unit, type) {
	}

	Parameter::Parameter(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in)
			: Variable(std::move(name), unit, type, in) {
	}

	Parameter::Parameter(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in, bool out)
			: Variable(std::move(name), unit, type, in, out) {
	}

	Parameter::Parameter(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in, bool out,
						 bool st) : Parameter(std::move(name), unit, type, in, out) {
		staticParam = st;
	}

	bool Parameter::isStatic() {
		return staticParam;
	}

}
