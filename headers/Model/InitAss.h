//
// Created by Simone on 2019-08-19.
//

#ifndef SRC_INITASS_H
#define SRC_INITASS_H

#include <string>
#include "Variable.h"

namespace Modeling {

	class Module;

	class Expression;

	class Unit;

	class Type;

	class InitAss final {
		friend void Variable::addInitAss(std::shared_ptr<Expression> &val);

		friend void Variable::setInitAss(std::shared_ptr<Expression> &val);

	private:
		std::shared_ptr<Expression> val;
		const std::shared_ptr<Module> mod;
		const std::shared_ptr<Variable> var;

		void setInitialAss(std::shared_ptr<Expression> e);

	public:
		InitAss(std::shared_ptr<Expression> val, std::shared_ptr<Module> mod, std::shared_ptr<Variable> v);

		const std::weak_ptr<Expression> getValInitialAss();

		const std::weak_ptr<Module> getModule();

		const std::weak_ptr<Variable> getVariable();

		friend bool operator==(const InitAss &l1, const InitAss &l2);

		friend bool operator!=(const InitAss &l1, const InitAss &l2);

	};

}

#endif //SRC_INITASS_H