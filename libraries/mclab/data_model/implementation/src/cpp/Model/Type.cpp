//
// Created by Simone on 2019-08-17.
//

#include "Model/Type.h"

namespace Modeling {

	Type::~Type() = default;

	Type::Type(std::string name) : name(std::move(name)) {
	}

	std::string Type::getName() {
		return name;
	}

	bool operator==(const Type &t1, const Type &t2) {
		return t1.name == t2.name;
	}

	bool operator!=(const Type &t1, const Type &t2) {
		return !(t1 == t2);
	}

	void Type::setName(std::string n) {
		name = std::move(n);
	}

}
