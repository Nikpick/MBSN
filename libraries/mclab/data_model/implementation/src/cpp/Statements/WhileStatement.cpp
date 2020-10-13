//
// Created by Simone on 2019-08-18.
//

#include "Statements/WhileStatement.h"
#include "Model/Type.h"
#include "Model/Expression.h"
#include "Statements/WhileStatem.h"
#include "StatementOwnerException.cpp"
#include "StatInBlockException.cpp"
#include "IterationStatException.cpp"
#include "WhileCondTypeException.cpp"
#include "RemoveStatException.cpp"

namespace Statements {

	WhileStatement::WhileStatement(std::shared_ptr<Modeling::Expression> c, std::shared_ptr<Statement> stat)
			: NestedStatement(), whileCond(std::move(c)) {
		if (whileCond->getType().lock()->getName() != "Boolean")
			throw WhileCondTypeException();
		else if (stat->getOwner().lock() != nullptr)
			throw StatementOwnerException();
		else {
			stat->setOwner(std::dynamic_pointer_cast<StatementOwner>(std::make_shared<WhileStatement>(*this)));
			auto link = std::dynamic_pointer_cast<WhileStatem>(std::make_shared<WhileStatem>(std::make_shared<WhileStatement>(*this), std::move(stat)));
			this->OrderedAssociationRole<WhileStatem, 1, 1>::addLink(std::move(link));
		}
	}

	WhileStatement::WhileStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Modeling::Expression> c,
								   std::shared_ptr<Statement> stat) : WhileStatement(std::move(c), std::move(stat)) {
		setOwner(std::move(own));
	}

	const std::weak_ptr<Modeling::Expression> WhileStatement::getWhilecond() const {
		return whileCond;
	}

	const std::weak_ptr<Statement> WhileStatement::getStatement() const {
		return this->OrderedAssociationRole<WhileStatem, 1, 1>::getLink(0).lock()->getStatement();
	}

}
