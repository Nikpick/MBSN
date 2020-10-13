//
// Created by Simone on 04/09/2019.
//

#include "Statements/ThenStatem.h"
#include "Statements/NestedStatement.h"
#include "Statements/IfStatement.h"

namespace Statements {

	ThenStatem::ThenStatem(std::shared_ptr<IfStatement> ifst, std::shared_ptr<Statement> st)
			: SingleOwnerAssociationLink<IfStatement, Statement>::SingleOwnerAssociationLink(ifst, st), StNest(std::dynamic_pointer_cast<NestedStatement>(ifst), st) {
	}

}
