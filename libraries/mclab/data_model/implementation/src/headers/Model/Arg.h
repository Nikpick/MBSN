//
// Created by Simone on 2019-08-19.
//

#ifndef SRC_ARG_H
#define SRC_ARG_H

#include <memory>

namespace Modeling {

	class OperationCall;

	class OperationArg;

	class Expression;

	class Arg final {
	private:
		const std::shared_ptr<OperationArg> arg;
		const std::shared_ptr<OperationCall> opCall;
		std::shared_ptr<Expression> actualArg;
	public:
		Arg(const std::shared_ptr<OperationArg> arg, const std::shared_ptr<OperationCall> opc,
			std::shared_ptr<Expression> actualArg);

		const std::weak_ptr<OperationArg> getArgument();

		const std::weak_ptr<OperationCall> getOperation();

		const std::weak_ptr<Expression> getActualArg();

		void setActualArg(std::shared_ptr<Expression> &v);

		friend bool operator==(const Arg &a1, const Arg &a2);

		friend bool operator!=(const Arg &a1, const Arg &a2);

	};

}

#endif //SRC_ARG_H
