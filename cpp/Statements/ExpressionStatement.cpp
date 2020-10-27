//
// Created by Simone on 2019-08-18.
//

#include "Statements/ExpressionStatement.h"

namespace Statements {

	ExpressionStatement::ExpressionStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Modeling::Expression> e)
			: Statement(std::move(own)), expr(std::move(e)) {
	}

	ExpressionStatement::ExpressionStatement(std::shared_ptr<Modeling::Expression> e) : Statement(), expr(std::move(e)) {
	}

	const std::weak_ptr<Modeling::Expression> ExpressionStatement::getExpression() {
		return expr;
	}

	void ExpressionStatement::setExpression(std::shared_ptr<Modeling::Expression> &ex) {
		expr = ex;
	}

}
