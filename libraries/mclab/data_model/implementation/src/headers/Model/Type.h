//
// Created by Simone on 2019-08-17.
//

#ifndef SRC_TYPE_H
#define SRC_TYPE_H

#include <string>

namespace Modeling {

	class Type {
	protected:
		std::string name;
	public:
		virtual ~Type() = 0;

		explicit Type(std::string name);

		std::string getName();

		void setName(std::string n);

		friend bool operator==(const Type &t1, const Type &t2);

		friend bool operator!=(const Type &t1, const Type &t2);
	};

}

#endif //SRC_TYPE_H
