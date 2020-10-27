//
// Created by Simone on 2019-08-22.
//

#include "Model/Operation.h"
#include "Model/OperationArg.h"
#include "Model/Type.h"

namespace Modeling {

	Operation::Operation(std::string n, std::shared_ptr<Type> type, std::string symbol)
			: name(std::move(n)), ret(std::move(type)), symbol(std::move(symbol)) {
	}

	Operation::~Operation() = default;

	std::string Operation::getSymbol() {
		return symbol;
	}

	void Operation::setSymbol(std::string sym) {
		symbol = sym;
	}

	std::string Operation::getName() {
		return name;
	}

	void Operation::setName(std::string n) {
		name = std::move(n);
	}

	const std::weak_ptr<Type> Operation::getReturnType() {
		return ret;
	}

	void Operation::setReturnType(std::shared_ptr<Type> &t) {
		ret = t;
	}

	void Operation::addArgument(std::shared_ptr<OperationArg> &a) {
		args.push_back(a);
	}

	void Operation::removeArgument(std::shared_ptr<OperationArg> &a) {
		args.erase(std::remove(args.begin(), args.end(), a), args.end());
	}

	const std::vector<std::shared_ptr<OperationArg>> Operation::getArguments() {
		return args;
	}

	bool operator==(const Operation &op, const Operation &op2) {
		return op.name == op2.name and op.args == op2.args and op.ret == op2.ret;
	}

	bool operator!=(const Operation &op, const Operation &op2) {
		return !(op == op2);
	}

}
