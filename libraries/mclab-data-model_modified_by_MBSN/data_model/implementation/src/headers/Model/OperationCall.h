//
// Created by Simone on 2019-08-19.
//

#ifndef SRC_OPERATIONCALL_H
#define SRC_OPERATIONCALL_H

#include <unordered_set>
#include "Expression.h"

namespace Modeling {

	class Operation;

	class Arg;

	class OperationArg;

	class OperationCall : public Expression, public std::enable_shared_from_this<OperationCall> {
	private:
		std::shared_ptr<Operation> refers;
		std::unordered_set<std::shared_ptr<Arg>> args;
	public:
		OperationCall(std::shared_ptr<Type> t, std::shared_ptr<Operation> op);

		const std::weak_ptr<Operation> getOperationRef();

		void addArg(const std::shared_ptr<OperationArg> &a, std::shared_ptr<Expression> &v);

		void removeArg(std::shared_ptr<Arg> &l);

		const std::unordered_set<std::shared_ptr<Arg>> getArgs();

		friend bool operator==(const OperationCall &o1, const OperationCall &o2);

		friend bool operator!=(const OperationCall &o1, const OperationCall &o2);
	};

}

#endif //SRC_OPERATIONCALL_H
