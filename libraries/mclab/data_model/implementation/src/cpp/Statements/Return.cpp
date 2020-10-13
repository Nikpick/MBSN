//
// Created by Simone on 2019-08-18.
//

#include "Statements/Return.h"

namespace Statements {

	Return::Return(std::shared_ptr<StatementOwner> own) : Statement(std::move(own)) {
	}

	Return::Return() : Statement() {
	}

}
