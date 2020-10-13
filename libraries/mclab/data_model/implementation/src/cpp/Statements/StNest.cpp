//
// Created by Simone on 02/09/2019.
//

#include "Statements/StNest.h"
#include "Statements/Statement.h"
#include "Statements/NestedStatement.h"

namespace Statements {

	const std::weak_ptr<Statement> StNest::getStatement() const {
		return this->getRoleY();
	}

	const std::weak_ptr<NestedStatement> StNest::getNestedStatement() const {
		return this->getRoleX();
	}

	StNest::StNest(std::shared_ptr<NestedStatement> nest, std::shared_ptr<Statement> st)
			: SingleOwnerAssociationLink(std::move(nest), std::move(st)) {
	}

}
