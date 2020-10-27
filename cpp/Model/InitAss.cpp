//
// Created by Simone on 2019-08-19.
//

#include "Model/InitAss.h"
#include "Model/Module.h"
#include "VarNotInModuleException.cpp"

namespace Modeling {

	InitAss::InitAss(std::shared_ptr<Expression> val, std::shared_ptr<Module> mod, std::shared_ptr<Variable> v)
			: val(std::move(val)), mod(std::move(mod)), var(std::move(v)) {
		if (this->mod->getVars().count(var) == 0)
			throw VarNotInModuleException(var->getName());
	}

	const std::weak_ptr<Expression> InitAss::getValInitialAss() {
		return val;

	}

	void InitAss::setInitialAss(std::shared_ptr<Expression> e) {
		val = std::move(e);
	}

	const std::weak_ptr<Variable> InitAss::getVariable() {
		return var;
	}

	const std::weak_ptr<Module> InitAss::getModule() {
		return mod;
	}

	bool operator==(const InitAss &l1, const InitAss &l2) {
		return l1.var == l2.var and l1.mod == l2.mod;
	}

	bool operator!=(const InitAss &l1, const InitAss &l2) {
		return !(l1 == l2);
	}

}
