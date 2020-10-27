//
// Created by Simone on 03/09/2019.
//

#include "Statements/WhenStatem.h"
#include "Statements/NestedStatement.h"
#include "Statements/WhenStatement.h"

namespace Statements {

	WhenStatem::WhenStatem(std::shared_ptr<Statement> st, std::shared_ptr<WhenStatement> wh,
						   std::shared_ptr<Modeling::Expression> &cond)
			: SingleOwnerAssociationLink<WhenStatement, Statement>::SingleOwnerAssociationLink(wh, st), StNest(std::dynamic_pointer_cast<NestedStatement>(wh), st), cond(std::move(cond)) {
	}

	const std::shared_ptr<Modeling::Expression> WhenStatem::getCondition() const {
		return cond;
	}

	void WhenStatem::setCondition(std::shared_ptr<Modeling::Expression> c) {
		cond = std::move(c);
	}

}
