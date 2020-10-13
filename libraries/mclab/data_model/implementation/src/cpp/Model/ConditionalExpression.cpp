//
// Created by Simone on 2019-08-18.
//

#include "Model/ConditionalExpression.h"
#include "Model/Type.h"
#include "ConditionTypeException.cpp"
#include "CondExpressionException.cpp"

namespace Modeling {

	ConditionalExpression::ConditionalExpression(std::shared_ptr<Type> type, std::shared_ptr<Expression> elseCond,
												 std::shared_ptr<Expression> then, std::shared_ptr<Expression> cond)
			: Expression(std::move(type)), elseCondExpr(std::move(elseCond)), thenCondExpr(std::move(then)), condExpr(std::move(cond)) {
		if (cond->getType().lock()->getName() != "Boolean")
			throw ConditionTypeException();
		else if (elseCond->getType().lock()->getName() != then->getType().lock()->getName() and
				 elseCond->getType().lock()->getName() != type->getName() and
				 then->getType().lock()->getName() != type->getName())
			throw CondExpressionException();
	}

	const std::weak_ptr<Expression> ConditionalExpression::getElse() {
		return elseCondExpr;
	}

	void ConditionalExpression::setElse(std::shared_ptr<Expression> &el) {
		if (el->getType().lock()->getName() != thenCondExpr->getType().lock()->getName() and
			el->getType().lock()->getName() != type->getName())
			throw CondExpressionException();
		else
			elseCondExpr = el;
	}

	const std::weak_ptr<Expression> ConditionalExpression::getThen() {
		return thenCondExpr;
	}

	void ConditionalExpression::setThen(std::shared_ptr<Expression> &th) {
		if (th->getType().lock()->getName() != elseCondExpr->getType().lock()->getName() and
			th->getType().lock()->getName() != type->getName())
			throw CondExpressionException();
		else
			thenCondExpr = th;
	}

	const std::weak_ptr<Expression> ConditionalExpression::getCond() {
		return condExpr;
	}

	void ConditionalExpression::setCond(std::shared_ptr<Expression> &cond) {
		if (cond->getType().lock()->getName() != "Boolean")
			throw ConditionTypeException();
		else
			condExpr = cond;
	}

	bool operator==(const ConditionalExpression &e1, const ConditionalExpression &e2) {
		return e1.condExpr == e2.condExpr and e1.elseCondExpr == e2.elseCondExpr and e1.thenCondExpr == e2.thenCondExpr;
	}

	bool operator!=(const ConditionalExpression &e1, const ConditionalExpression &e2) {
		return !(e1 == e2);
	}

}
