//
// Created by Simone on 2019-08-18.
//

#include "Model/Constant.h"

namespace Modeling {

	Constant::Constant(std::shared_ptr<Type> type, std::string name)
			: Expression(std::move(type)), name(std::move(name)) {
	}

	std::string Constant::getName() {
		return name;
	}

	void Constant::setName(std::string n) {
		name = std::move(n);
	}

	bool operator==(const Constant &c1, const Constant &c2) {
		return c1.name == c2.name;
	}

	bool operator!=(const Constant &c1, const Constant &c2) {
		return !(c1 == c2);
	}

}
