//
// Created by Simone on 2019-08-18.
//

#include "Model/Expression.h"
#include "Model/Type.h"

namespace Modeling {

	Expression::Expression(std::shared_ptr<Type> type) : type(std::move(type)) {
	}

	Expression::~Expression() = default;

	bool Expression::isConstraint() {
		return type->getName() == "Boolean";
	}

	const std::weak_ptr<Type> Expression::getType() {
		return type;
	}

}
