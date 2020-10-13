//
// Created by Simone on 2019-08-18.
//

#include "Statements/Block.h"
#include "Statements/StNest.h"
#include "StatementOwnerException.cpp"
#include "StatInBlockException.cpp"

namespace Statements {

	Block::Block(std::shared_ptr<StatementOwner> own) : NestedStatement(std::move(own)) {
	}

	void Block::addStatem(std::shared_ptr<Statement> stat) {
		auto link = std::make_shared<StNest>(shared_from_this(), stat);
		this->addStatement(link);
	}

}
