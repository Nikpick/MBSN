//
// Created by Simone on 2019-08-18.
//

#include "Statements/Break.h"

namespace Statements {

	Break::Break(std::shared_ptr<StatementOwner> own) : Statement(std::move(own)) {
	}

	Break::Break() : Statement() {
	}

}
