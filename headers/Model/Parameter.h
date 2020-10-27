//
// Created by Simone on 2019-08-17.
//

#ifndef SRC_PARAMETER_H
#define SRC_PARAMETER_H

#include <string>
#include "Variable.h"

namespace Modeling {

	class Unit;

	class Type;

	class Module;

	class Parameter : public Variable {
	private:
		bool staticParam = false;
	public:
		Parameter(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type);

		Parameter(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in);

		Parameter(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in, bool out);

		Parameter(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in, bool out,
				  bool st);

		bool isStatic();

	};

}

#endif //SRC_PARAMETER_H
