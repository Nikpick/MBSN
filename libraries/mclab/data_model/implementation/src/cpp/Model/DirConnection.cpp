//
// Created by Simone on 2019-08-18.
//

#include "Model/DirConnection.h"
#include "Model/Module.h"
#include "Model/Variable.h"
#include "EqualsVarInConnException.cpp"
#include "TypeVarInConnException.cpp"
#include "VarNotInModuleException.cpp"

namespace Modeling {

	DirConnection::DirConnection(std::shared_ptr<Variable> &in, std::shared_ptr<Variable> &out)
			: Connection(), connInVar(in), connOutVar(out) {
		if (in == out)
			throw EqualsVarInConnException();
		else if (in->getType().lock()->getName() != out->getType().lock()->getName())
			throw TypeVarInConnException();
	}

	const std::weak_ptr<Variable> DirConnection::getInVar() {
		return connInVar;
	}

	const std::weak_ptr<Variable> DirConnection::getOutVar() {
		return connOutVar;
	}

	void DirConnection::setInVar(std::shared_ptr<Variable> &var) {
		if (var->getType().lock()->getName() != connOutVar->getType().lock()->getName())
			throw TypeVarInConnException();
		else
			connInVar = var;
	}

	void DirConnection::setOutVar(std::shared_ptr<Variable> &var) {
		if (var->getType().lock()->getName() != connInVar->getType().lock()->getName())
			throw TypeVarInConnException();
		else
			connOutVar = var;
	}

}
