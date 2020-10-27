//
// Created by Simone on 2019-08-17.
//

#include "Model/BaseType.h"
#include "BaseTypeException.cpp"

namespace Modeling {

	BaseType::BaseType(const std::string &n) : Type(n) {
		if ((n.compare("Boolean")) != 0 and (n.compare("Real")) != 0 and (n.compare("Integer")) != 0 and
			(n.compare("String")) != 0)
			throw BaseTypeException(n);
		else
			name = n;
	}

}
