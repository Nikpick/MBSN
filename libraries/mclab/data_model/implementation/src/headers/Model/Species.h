//
// Created by Simone on 2019-08-17.
//

#ifndef SRC_SPECIES_H
#define SRC_SPECIES_H

#include <string>
#include "Variable.h"

namespace Modeling {

	class Unit;

	class Type;

	class Module;

	class Species : public Variable {
	public:
		Species(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type);

		Species(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in);

		Species(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in, bool out);
	};

}

#endif //SRC_SPECIES_H
