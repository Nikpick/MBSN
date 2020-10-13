//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_EXPRESSION_H
#define SRC_EXPRESSION_H

#include <memory>

namespace Modeling {

	class Type;

	class Expression {
	protected:
		std::shared_ptr<Type> type;
	public:
		virtual ~Expression() = 0;

		explicit Expression(std::shared_ptr<Type> type);

		Expression() = default;

		const std::weak_ptr<Type> getType();

		bool isConstraint();
	};

}

#endif //SRC_EXPRESSION_H
