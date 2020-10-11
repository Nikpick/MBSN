//
// Created by Simone on 2019-08-19.
//

#include "Model/OperationCall.h"
#include "Model/UserDefOp.h"
#include "Model/Module.h"
#include "Model/Arg.h"
#include "OperationTypeException.cpp"
#include "OpNotInModException.cpp"

namespace Modeling {

	OperationCall::OperationCall(std::shared_ptr<Type> t, std::shared_ptr<Operation> op)
			: Expression(std::move(t)), refers(std::move(op)) {
		if (refers->getReturnType().lock() != getType().lock())
			throw OperationTypeException();
		else if (std::dynamic_pointer_cast<UserDefOp>(refers).get() and
				 std::dynamic_pointer_cast<UserDefOp>(refers).get()->getModule().lock()->getModExpr().count(shared_from_this()) ==
				 0)
			throw OpNotInModException(op->getName());
	}

	const std::weak_ptr<Operation> OperationCall::getOperationRef() {
		return refers;
	}

	void OperationCall::addArg(const std::shared_ptr<OperationArg> &a, std::shared_ptr<Expression> &v) {
		args.insert(std::make_shared<Arg>(a, shared_from_this(), std::move(v)));
	}

	void OperationCall::removeArg(std::shared_ptr<Arg> &l) {
		args.erase(l);
	}

	const std::unordered_set<std::shared_ptr<Arg>> OperationCall::getArgs() {
		return args;
	}

	bool operator==(const OperationCall &o1, const OperationCall &o2) {
		return o1.args == o2.args and o1.refers == o2.refers;
	}

	bool operator!=(const OperationCall &o1, const OperationCall &o2) {
		return !(o1 == o2);
	}

}
