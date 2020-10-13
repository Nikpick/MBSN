//
// Created by Simone on 04/09/2019.
//

#ifndef MODELS_TRANSLATOR_ELSESTATEM_H
#define MODELS_TRANSLATOR_ELSESTATEM_H

#include "SingleOwnerAssociationLink.h"
#include "StNest.h"

namespace Statements {

	class Statement;

	class IfStatement;

	class ElseStatem : protected SingleOwnerAssociationLink<IfStatement, Statement>, public StNest {
	public:
		ElseStatem(std::shared_ptr<IfStatement> ifst, std::shared_ptr<Statement> st);
	};

}

#endif //MODELS_TRANSLATOR_ELSESTATEM_H
