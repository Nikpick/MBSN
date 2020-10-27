//
// Created by Simone on 02/09/2019.
//

#ifndef MODELS_TRANSLATOR_STNEST_H
#define MODELS_TRANSLATOR_STNEST_H


#include "SingleOwnerAssociationLink.h"

namespace Statements {

	class Statement;

	class NestedStatement;

	class StNest : protected SingleOwnerAssociationLink<NestedStatement, Statement> {

	public:
		const std::weak_ptr<Statement> getStatement() const;

		const std::weak_ptr<NestedStatement> getNestedStatement() const;

		StNest(std::shared_ptr<NestedStatement> nest, std::shared_ptr<Statement> st);

	};

}

#endif //MODELS_TRANSLATOR_STNEST_H
