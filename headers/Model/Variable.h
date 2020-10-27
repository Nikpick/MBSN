//
// Created by Simone on 2019-08-17.
//

#ifndef SRC_VARIABLE_H
#define SRC_VARIABLE_H

#include <string>
#include "Module.h"

namespace Modeling {

	class Unit;

	class Type;

	class Module;

	class InitAss;

	class Expression;

	class Variable : public std::enable_shared_from_this<Variable> {
	protected:
		std::string name;
		std::shared_ptr<Unit> unit;
		std::shared_ptr<Type> type;
		std::shared_ptr<Module> mod = nullptr;
		std::shared_ptr<InitAss> init = nullptr;
		std::string initialAss = "";
		bool output = false;
		bool input = false;
	public:
		virtual ~Variable() = 0;

		Variable(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type);

		Variable(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool input);

		Variable(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool input, bool out);

		void setModule(std::shared_ptr<Module> module);

		void addInitialAss(std::string initAss);

		const std::string getInitialAss();

		std::string getName();

		void setName(std::string name);

		const std::weak_ptr<Unit> getUnit();

		void setUnit(std::shared_ptr<Unit> &u);

		const std::weak_ptr<Type> getType();

		void setType(std::shared_ptr<Type> &t);

		const std::weak_ptr<Module> getModule();

		const std::weak_ptr<InitAss> getInitAss();

		void addInitAss(std::shared_ptr<Expression> &val);

		void setInitAss(std::shared_ptr<Expression> &val);

		void removeInitAss(std::shared_ptr<InitAss> &i);

		void removeVar();

		bool isOutput();

		bool isInput();

		friend bool operator==(const Variable &v1, const Variable &v2);

		friend bool operator!=(const Variable &v1, const Variable &v2);
	};

}

#endif //SRC_VARIABLE_H
