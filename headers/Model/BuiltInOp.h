//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_BUILTINOP_H
#define SRC_BUILTINOP_H

#include "Operation.h"

namespace Modeling {

	class Type;

	class BuiltInOp : public Operation {
	public:
		BuiltInOp(std::string n, std::shared_ptr<Type> t, std::string symbol);
	};

}

#endif //SRC_BUILTINOP_H
