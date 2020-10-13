//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_CONDITIONALEXPRESSION_H
#define SRC_CONDITIONALEXPRESSION_H

#include "Expression.h"

namespace Modeling {
	class Type;

	class ConditionalExpression : public Expression {
	private:
		std::shared_ptr<Expression> elseCondExpr;
		std::shared_ptr<Expression> thenCondExpr;
		std::shared_ptr<Expression> condExpr;
	public:
		ConditionalExpression(std::shared_ptr<Type> type, std::shared_ptr<Expression> elseCond,
							  std::shared_ptr<Expression> then, std::shared_ptr<Expression> cond);

		const std::weak_ptr<Expression> getElse();

		void setElse(std::shared_ptr<Expression> &el);

		const std::weak_ptr<Expression> getThen();

		void setThen(std::shared_ptr<Expression> &th);

		const std::weak_ptr<Expression> getCond();

		void setCond(std::shared_ptr<Expression> &cond);

		friend bool operator==(const ConditionalExpression &e1, const ConditionalExpression &e2);

		friend bool operator!=(const ConditionalExpression &e1, const ConditionalExpression &e2);
	};

}

#endif //SRC_CONDITIONALEXPRESSION_H
