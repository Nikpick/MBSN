//
// Created by Simone on 2019-08-18.
//

#include "Statements/WhenStatement.h"
#include "Model/Expression.h"
#include "Model/Type.h"
#include "Statements/WhenStatem.h"
#include "StatemInWhenException.cpp"
#include "StatNotInWhenException.cpp"
#include "StatementOwnerException.cpp"
#include "ConditionTypeException.cpp"

namespace Statements {

	WhenStatement::WhenStatement(std::shared_ptr<Statement> stat, std::shared_ptr<Modeling::Expression> cond)
			: NestedStatement() {
		addStatement(stat, std::move(cond));
	}

	WhenStatement::WhenStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Statement> stat,
								 std::shared_ptr<Modeling::Expression> cond) : WhenStatement(std::move(stat), std::move(cond)) {
		setOwner(std::move(own));
	}

	void WhenStatement::addStatement(std::shared_ptr<Statement> &stat, std::shared_ptr<Modeling::Expression> cond) {
		if (cond->getType().lock()->getName() != "Boolean")
			throw ConditionTypeException();
		else if (stat->getOwner().lock() != nullptr)
			throw StatementOwnerException();
		else {
			if (findCondition(cond))
				throw StatemInWhenException();
			else {
				stat->setOwner(std::dynamic_pointer_cast<StatementOwner>(std::make_shared<WhenStatement>(*this)));
				auto link = std::dynamic_pointer_cast<WhenStatem>(std::make_shared<WhenStatem>(stat, std::make_shared<WhenStatement>(*this), cond));
				this->OrderedAssociationRole<WhenStatem, 0, N>::addLink(link);
			}
		}
	}

	bool WhenStatement::findCondition(std::shared_ptr<Modeling::Expression> &cond) {
		bool found = false;
		for (unsigned int i = 0; i < this->OrderedAssociationRole<WhenStatem, 0, N>::countLinks(); i++) {
			if (this->OrderedAssociationRole<WhenStatem, 0, N>::getLink(i).lock()->getCondition() == cond)
				found = true;
		}
		return found;
	}

	void WhenStatement::setWhenCondition(std::shared_ptr<WhenStatem> &st, std::shared_ptr<Modeling::Expression> c) {
		if (findCondition(c))
			throw StatemInWhenException();
		else
			st->setCondition(c);
	}

	const std::map<std::shared_ptr<Modeling::Expression>, std::shared_ptr<Statement>> WhenStatement::getStatements() const {
		std::map<std::shared_ptr<Modeling::Expression>, std::shared_ptr<Statement>> res;
		for (unsigned int i = 0; i < this->OrderedAssociationRole<WhenStatem, 0, N>::countLinks(); ++i)
			res.insert(std::make_pair(OrderedAssociationRole<WhenStatem, 0, N>::getLink(i).lock()->getCondition(), OrderedAssociationRole<WhenStatem, 0, N>::getLink(i).lock()->getStatement().lock()));
		return res;
	}

}
