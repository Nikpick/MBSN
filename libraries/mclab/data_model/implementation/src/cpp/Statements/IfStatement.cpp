//
// Created by Simone on 2019-08-18.
//

#include "Statements/IfStatement.h"
#include "Model/Expression.h"
#include "Model/Type.h"
#include "Statements/ThenStatem.h"
#include "Statements/ElseStatem.h"
#include "StatementOwnerException.cpp"
#include "ConditionTypeException.cpp"
#include "ElseStatException.cpp"
#include "ElseAlreadyInException.cpp"
#include "ElseOnlyWithThenException.cpp"
#include "NoStatementException.cpp"

namespace Statements {

	IfStatement::IfStatement(std::shared_ptr<Modeling::Expression> c, std::shared_ptr<Statement> stat)
			: NestedStatement(), condIfSt(std::move(c)) {
		if (condIfSt->getType().lock()->getName() != "Boolean")
			throw ConditionTypeException();
		else if (stat->getOwner().lock() != nullptr)
			throw StatementOwnerException();
		else {
			stat->setOwner(std::dynamic_pointer_cast<StatementOwner>(std::make_shared<IfStatement>(*this)));
			auto link = std::make_shared<ThenStatem>(std::make_shared<IfStatement>(*this), std::move(stat));
			this->OrderedAssociationRole<ThenStatem, 1, 1>::addLink(link);
		}
	}

	IfStatement::IfStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Modeling::Expression> c,
							 std::shared_ptr<Statement> stat) : IfStatement(std::move(c), std::move(stat)) {
		setOwner(std::move(own));
	}

	IfStatement::IfStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Modeling::Expression> c,
							 std::shared_ptr<Statement> then, std::shared_ptr<Statement> els)
			: IfStatement(std::move(c), std::move(then), std::move(els)) {
		setOwner(std::move(own));
	}

	IfStatement::IfStatement(std::shared_ptr<Modeling::Expression> c, std::shared_ptr<Statement> then,
							 std::shared_ptr<Statement> els) : IfStatement(std::move(c), std::move(then)) {
		addElseStatement(std::move(els));
	}

	const std::weak_ptr<Modeling::Expression> IfStatement::getCondition() const {
		return condIfSt;
	}

	void IfStatement::addElseStatement(std::shared_ptr<Statement> stat) {
		if (stat->getOwner().lock() != nullptr)
			throw StatementOwnerException();
		else {
			stat->setOwner(std::dynamic_pointer_cast<StatementOwner>(std::make_shared<IfStatement>(*this)));
			auto link = std::make_shared<ElseStatem>(std::make_shared<IfStatement>(*this), std::move(stat));
			this->OrderedAssociationRole<ElseStatem, 0, 1>::addLink(link);
		}
	}

	const std::weak_ptr<Statement> IfStatement::getElse() const {
		return this->OrderedAssociationRole<ElseStatem, 0, 1>::countLinks() != 0
			   ? this->OrderedAssociationRole<ElseStatem, 0, 1>::getLink(0).lock()->getStatement()
			   : throw NoStatementException();
	}

	const std::weak_ptr<Statement> IfStatement::getThen() const {
		return this->OrderedAssociationRole<ThenStatem, 1, 1>::getLink(0).lock()->getStatement();
	}

}
