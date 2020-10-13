//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_EXPRESSIONSTATEMENT_H
#define SRC_EXPRESSIONSTATEMENT_H

#include "Statement.h"

namespace Modeling {
	class Expression;
}

namespace Statements {

	class ExpressionStatement : public Statement {
	private:
		std::shared_ptr<Modeling::Expression> expr;
	public:
		ExpressionStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Modeling::Expression> e);

		explicit ExpressionStatement(std::shared_ptr<Modeling::Expression> e);

		const std::weak_ptr<Modeling::Expression> getExpression();

		void setExpression(std::shared_ptr<Modeling::Expression> &ex);
	};

}

#endif //SRC_EXPRESSIONSTATEMENT_H
