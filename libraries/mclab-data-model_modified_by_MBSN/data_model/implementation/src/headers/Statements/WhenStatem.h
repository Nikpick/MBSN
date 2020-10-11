//
// Created by Simone on 03/09/2019.
//

#ifndef MODELS_TRANSLATOR_WHENSTATEM_H
#define MODELS_TRANSLATOR_WHENSTATEM_H

#include "SingleOwnerAssociationLink.h"
#include "StNest.h"

namespace Modeling {
	class Expression;
}

namespace Statements {
	class Statement;

	class WhenStatement;

	class WhenStatem : protected SingleOwnerAssociationLink<WhenStatement, Statement>, public StNest {
	private:
		std::shared_ptr<Modeling::Expression> cond;
	public:
		WhenStatem(std::shared_ptr<Statement> st, std::shared_ptr<WhenStatement> wh, std::shared_ptr<Modeling::Expression> &cond);

		const std::shared_ptr<Modeling::Expression> getCondition() const;

		void setCondition(std::shared_ptr<Modeling::Expression> c);
	};
}


#endif //MODELS_TRANSLATOR_WHENSTATEM_H
