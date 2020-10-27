//
// Created by Simone on 03/09/2019.
//

#include "Statements/ForStatem.h"
#include "Statements/ForStatement.h"
#include "Statements/Statement.h"

namespace Statements {

	ForStatem::ForStatem(std::shared_ptr<ForStatement> f, std::shared_ptr<Statement> st)
			: SingleOwnerAssociationLink<ForStatement, Statement>::SingleOwnerAssociationLink(f, st), StNest(std::dynamic_pointer_cast<NestedStatement>(f), st) {
	}

}
