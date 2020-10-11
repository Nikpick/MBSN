//
// Created by Simone on 2019-08-17.
//

#include "Model/Species.h"

namespace Modeling {

	Species::Species(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type)
			: Variable(std::move(name), unit, type) {
	}

	Species::Species(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in)
			: Variable(std::move(name), unit, type, in) {
	}

	Species::Species(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in, bool out)
			: Variable(std::move(name), unit, type, in, out) {
	}

}
