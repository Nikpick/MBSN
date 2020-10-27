//
// Created by Simone on 2019-08-18.
//

#include "Model/OperationArg.h"
#include "Model/Operation.h"
#include "ArgumentInOtherFunctionException.cpp"

namespace Modeling {

	OperationArg::OperationArg(std::string n, std::shared_ptr<Type> t) : name(std::move(n)), type(std::move(t)) {
	}

	void OperationArg::setOperation(std::shared_ptr<Operation> operation) {
		if (op != nullptr)
			throw ArgumentInOtherFunctionException();
		else {
			op = std::move(operation);
			auto ptr = shared_from_this();
			op->addArgument(ptr);
		}
	}

	std::string OperationArg::getName() {
		return name;
	}

	void OperationArg::setName(std::string n) {
		name = n;
	}

	const std::weak_ptr<Type> OperationArg::getType() {
		return type;
	}

	void OperationArg::setType(std::shared_ptr<Type> &t) {
		type = t;
	}

	const std::weak_ptr<Operation> OperationArg::getOperation() {
		return op;
	}

	void OperationArg::removeArgument() {
		auto ptr = shared_from_this();
		op->removeArgument(ptr);
		this->~OperationArg();
	}

	bool operator==(const OperationArg &o1, const OperationArg &o2) {
		return o1.name == o2.name and o1.type == o2.type and o1.op == o2.op;
	}

	bool operator!=(const OperationArg &o1, const OperationArg &o2) {
		return !(o1 == o2);
	}

}
