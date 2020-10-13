//
// Created by Simone on 03/09/2019.
//

#ifndef MODELS_TRANSLATOR_WHILESTATEM_H
#define MODELS_TRANSLATOR_WHILESTATEM_H

#include "SingleOwnerAssociationLink.h"
#include "StNest.h"

namespace Statements {

	class Statement;

	class WhileStatement;

	class WhileStatem : protected SingleOwnerAssociationLink<WhileStatement, Statement>, public StNest {

	public:
		WhileStatem(std::shared_ptr<WhileStatement> wh, std::shared_ptr<Statement> st);
	};

}

#endif //MODELS_TRANSLATOR_WHILESTATEM_H
