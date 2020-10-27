//
// Created by Simone on 2019-08-17.
//

#ifndef SRC_BASETYPE_H
#define SRC_BASETYPE_H

#include <string>
#include "Type.h"

namespace Modeling {

	class BaseType : public Type {
	public:
		explicit BaseType(const std::string &n);
	};

}
#endif //SRC_BASETYPE_H
