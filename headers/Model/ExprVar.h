//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_EXPRVAR_H
#define SRC_EXPRVAR_H

#include "Expression.h"
#include "Module.h"
#include <memory>
#include <string>

namespace Modeling {

	class Variable;

	class ExprVar : public Expression, public std::enable_shared_from_this<ExprVar> {
	private:
		std::string var;
		//    std::shared_ptr<Variable> var;
	public:
		//ExprVar(std::shared_ptr<Type> type, std::shared_ptr<Variable> var);
		explicit ExprVar(std::string var);

		//const std::weak_ptr<Variable> getVariable();
		std::string getVariable();

		friend bool operator==(const ExprVar &v1, const ExprVar &v2);

		friend bool operator!=(const ExprVar &v1, const ExprVar &v2);
	};

}

#endif //SRC_EXPRVAR_H
