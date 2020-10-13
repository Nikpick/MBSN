//
// Created by Simone on 03/09/2019.
//

#ifndef MODELS_TRANSLATOR_FORSTATEM_H
#define MODELS_TRANSLATOR_FORSTATEM_H

#include "SingleOwnerAssociationLink.h"
#include "StNest.h"

namespace Statements {

	class Statement;

	class ForStatement;

	class ForStatem : protected SingleOwnerAssociationLink<ForStatement, Statement>, public StNest {
	public:
		ForStatem(std::shared_ptr<ForStatement> f, std::shared_ptr<Statement> st);
	};

}

#endif //MODELS_TRANSLATOR_FORSTATEM_H
