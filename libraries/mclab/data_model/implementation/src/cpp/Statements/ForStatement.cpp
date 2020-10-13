//
// Created by Simone on 2019-08-18.
//

#include "Statements/ForStatement.h"
#include "Model/Expression.h"
#include "Model/Type.h"
#include "Statements/ForStatem.h"
#include "ForIndexException.cpp"
#include "StatementOwnerException.cpp"
#include "StatInBlockException.cpp"
#include "IterationStatException.cpp"
#include "RemoveStatException.cpp"

namespace Statements {

	ForStatement::ForStatement(std::shared_ptr<Modeling::Expression> b, std::shared_ptr<Modeling::Expression> s,
							   std::shared_ptr<Modeling::Expression> u, std::shared_ptr<Statement> stat)
			: NestedStatement(), begin(std::move(b)), step(std::move(s)), upTo(std::move(u)) {
		if (begin->getType().lock()->getName() != "Real" and begin->getType().lock()->getName() != "Integer" and
			step->getType().lock()->getName() != "Real" and step->getType().lock()->getName() != "Integer" and
			upTo->getType().lock()->getName() != "Real" and upTo->getType().lock()->getName() != "Integer")
			throw ForIndexException();
		else if (stat->getOwner().lock() != nullptr)
			throw StatementOwnerException();
		else {
			stat->setOwner(std::dynamic_pointer_cast<StatementOwner>(std::make_shared<ForStatement>(*this)));
			auto link = std::dynamic_pointer_cast<ForStatem>(std::make_shared<ForStatem>(std::make_shared<ForStatement>(*this), std::move(stat)));
			this->OrderedAssociationRole<ForStatem, 1, 1>::addLink(link);
		}
	}

	ForStatement::ForStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Modeling::Expression> b,
							   std::shared_ptr<Modeling::Expression> s, std::shared_ptr<Modeling::Expression> u,
							   std::shared_ptr<Statement> stat)
			: ForStatement(std::move(b), std::move(s), std::move(u), std::move(stat)) {
		setOwner(std::move(own));
	}

	const std::shared_ptr<Modeling::Expression> ForStatement::getBegin() const {
		return begin;
	}

	const std::shared_ptr<Modeling::Expression> ForStatement::getStep() const {
		return step;
	}

	const std::shared_ptr<Modeling::Expression> ForStatement::getUpTo() const {
		return upTo;
	}

	const std::weak_ptr<Statement> ForStatement::getStatement() const {
		return this->OrderedAssociationRole<ForStatem, 1, 1>::getLink(0).lock()->getStatement();
	}

}
