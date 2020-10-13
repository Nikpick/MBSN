//
// Created by Simone on 2019-08-18.
//

#include "Model/ExprVar.h"
#include "Model/Variable.h"
#include "Model/Module.h"
#include "VarNotInModuleException.cpp"

namespace Modeling {

	/*ExprVar::ExprVar(std::shared_ptr<Type> type, std::shared_ptr<Variable> var) : Expression(std::move(type)), var(std::move(var)) {
		if (this->var->getModule().lock() == nullptr)
			throw VarNotInModuleException(this->var->getName());
		else {
			std::shared_ptr<Expression> ptr = std::make_shared<ExprVar>(*this);
			this->var->getModule().lock()->addModExpr(ptr);
		}
	}*/

	ExprVar::ExprVar(std::string var) : Expression(), var(std::move(var)) {

	}

	std::string ExprVar::getVariable() {
		return var;
	}

	/*const std::weak_ptr<Variable> ExprVar::getVariable() {
		return var;
	}*/

	bool operator==(const ExprVar &v1, const ExprVar &v2) {
		return v1.var == v2.var;
	}

	bool operator!=(const ExprVar &v1, const ExprVar &v2) {
		return !(v1 == v2);
	}

}