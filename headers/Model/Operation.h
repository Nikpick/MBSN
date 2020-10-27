//
// Created by Simone on 2019-08-22.
//

#ifndef SRC_OPERATION_H
#define SRC_OPERATION_H

#include <string>
#include <unordered_map>
#include <vector>

namespace Modeling {

	class Type;

	class OperationArg;

	class Operation {
		friend class OperationArg;

	protected:
		std::vector<std::shared_ptr<OperationArg>> args;
		std::string name;
		std::string symbol;
		std::shared_ptr<Type> ret;

		Operation(std::string n, std::shared_ptr<Type> type, std::string symbol);

		void addArgument(std::shared_ptr<OperationArg> &a);

		void removeArgument(std::shared_ptr<OperationArg> &a);

	public:
		virtual ~Operation() = 0;

		std::string getSymbol();

		void setSymbol(std::string sym);

		void setName(std::string n);

		const std::weak_ptr<Type> getReturnType();

		void setReturnType(std::shared_ptr<Type> &t);

		const std::vector<std::shared_ptr<OperationArg>> getArguments();

		friend bool operator==(const Operation &op, const Operation &op2);

		friend bool operator!=(const Operation &op, const Operation &op2);

		std::string getName();
	};

}

#endif //SRC_OPERATION_H
