//
// Created by Simone on 2019-08-17.
//

#include "Model/Unit.h"
#include "NoIDException.cpp"

namespace Modeling {

	Unit::Unit(std::string name) : name(std::move(name)) {
	}

	std::string Unit::getName() {
		return name;
	}


	bool operator==(const Unit &u1, const Unit &u2) {
		return u1.name == u2.name;
	}

	bool operator!=(const Unit &u1, const Unit &u2) {
		return !(u1 == u2);
	}

}
