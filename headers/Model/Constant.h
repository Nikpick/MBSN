//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_CONSTANT_H
#define SRC_CONSTANT_H

#include <string>
#include "Expression.h"

namespace Modeling {

	class Type;

	class Constant : public Expression {
	private:
		std::string name;
	public:
		Constant(std::shared_ptr<Type> type, std::string name);

		std::string getName();

		void setName(std::string n);

		friend bool operator==(const Constant &c1, const Constant &c2);

		friend bool operator!=(const Constant &c1, const Constant &c2);
	};

}

#endif //SRC_CONSTANT_H
