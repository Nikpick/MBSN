//
// Created by Simone on 2019-08-19.
//

#include "Model/Arg.h"

namespace Modeling {

	Arg::Arg(const std::shared_ptr<OperationArg> arg, std::shared_ptr<OperationCall>  opc, const std::shared_ptr<Expression> actualArg) : arg(arg), opCall(std::move(opc)), actualArg(std::move(actualArg)) {
	}

	const std::weak_ptr<OperationArg> Arg::getArgument() {
	    return arg;
	}

	const std::weak_ptr<OperationCall> Arg::getOperation() {
	    return opCall;
	}

	const std::weak_ptr<Expression> Arg::getActualArg() {
	    return actualArg;
	}

	void Arg::setActualArg(std::shared_ptr<Expression>& v) {
	    actualArg = v;
	}

	bool operator==(const Arg& a1, const Arg& a2) {
	    return &a1.opCall == &a2.opCall and a1.arg == a2.arg;
	}

	bool operator!=(const Arg &a1, const Arg &a2) {
	    return !(a1 == a2);
	}

}
