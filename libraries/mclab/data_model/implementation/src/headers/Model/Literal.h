//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_LITERAL_H
#define SRC_LITERAL_H

#include <string>
#include "Expression.h"

namespace Modeling {

	class Literal : public Expression {
	private:
		const std::string value;
	public:
		explicit Literal(std::shared_ptr<Type> type, std::string val);

		std::string getValue();
	};

}
#endif //SRC_LITERAL_H
