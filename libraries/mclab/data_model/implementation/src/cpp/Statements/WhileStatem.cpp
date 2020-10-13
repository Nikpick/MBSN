//
// Created by Simone on 03/09/2019.
//

#include "Statements/WhileStatem.h"
#include "Statements/NestedStatement.h"
#include "Statements/WhileStatement.h"

namespace Statements {

	WhileStatem::WhileStatem(std::shared_ptr<WhileStatement> wh, std::shared_ptr<Statement> st)
			: SingleOwnerAssociationLink<WhileStatement, Statement>::SingleOwnerAssociationLink(wh, st), StNest(std::dynamic_pointer_cast<NestedStatement>(wh), st) {
	}

}
