//
// Created by Simone on 2019-08-17.
//

#ifndef SRC_UNIT_H
#define SRC_UNIT_H

#include <string>

namespace Modeling {

	class Unit {
	private:
		std::string name;
	public:
		explicit Unit(std::string name);

		std::string getName();

		friend bool operator==(const Unit &u1, const Unit &u2);

		friend bool operator!=(const Unit &u1, const Unit &u2);
	};

}

#endif //SRC_UNIT_H
