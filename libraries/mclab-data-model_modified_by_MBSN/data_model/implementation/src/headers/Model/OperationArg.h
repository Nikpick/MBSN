//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_OPERATIONARG_H
#define SRC_OPERATIONARG_H

#include <string>
#include <memory>

namespace Modeling {

	class Type;

	class Operation;

	class OperationArg : public std::enable_shared_from_this<OperationArg> {
	private:
		std::string name;
		std::shared_ptr<Type> type;
		std::shared_ptr<Operation> op = nullptr;
	public:
		OperationArg(std::string n, std::shared_ptr<Type> t);

		void setOperation(std::shared_ptr<Operation> operation);

		std::string getName();

		void setName(std::string name);

		const std::weak_ptr<Type> getType();

		void setType(std::shared_ptr<Type> &t);

		const std::weak_ptr<Operation> getOperation();

		void removeArgument();

		friend bool operator==(const OperationArg &o1, const OperationArg &o2);

		friend bool operator!=(const OperationArg &o1, const OperationArg &o2);
	};

}

#endif //SRC_OPERATIONARG_H
