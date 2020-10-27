//
// Created by Simone on 2019-08-18.
//

#include "Model/BuiltInOp.h"
#include "Model/Type.h"
#include <iostream>

namespace Modeling {

	BuiltInOp::BuiltInOp(std::string n, std::shared_ptr<Type> t, std::string symbol)
			: Operation(std::move(n), std::move(t), std::move(symbol)) {
	}

}
