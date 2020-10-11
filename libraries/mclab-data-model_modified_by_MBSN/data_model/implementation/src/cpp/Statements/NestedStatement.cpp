//
// Created by Simone on 2019-08-18.
//

#include "Statements/NestedStatement.h"
#include "Statements/StNest.h"
#include "NotInvolvedInLinkException.cpp"
#include "NoStatementException.cpp"

namespace Statements {

	NestedStatement::NestedStatement(std::shared_ptr<StatementOwner> own) : Statement(std::move(own)) {
	}

	NestedStatement::NestedStatement() : Statement() {
	}

	const std::set<std::shared_ptr<Statement>> NestedStatement::getStatements() const {
		if (NestedStatement::countLinks() == 0)
			throw NoStatementException();
		else {
			std::set<std::shared_ptr<Statement>> res;
			for (unsigned int i = 0; i < this->countLinks(); ++i)
				res.insert(this->getLink(i).lock()->getStatement().lock());
			return res;
		}
	}

	void NestedStatement::addStatement(std::shared_ptr<StNest> &stat) {
		this->OrderedAssociationRole<StNest, 0, N>::addLink(stat);
	}

}
