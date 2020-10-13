//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_USERDEFOP_H
#define SRC_USERDEFOP_H

#include <memory>
#include "Operation.h"
#include "Statements/StatementOwner.h"

namespace Modeling {

	class Module;

	class UserDefOp : public Operation, public Statements::StatementOwner, std::enable_shared_from_this<UserDefOp> {
	private:
		std::shared_ptr<Module> mod;
		std::shared_ptr<Statements::Statement> def = nullptr;

		void addStatement(std::shared_ptr<Statements::Statement> &stat);

	public:
		UserDefOp(std::string n, std::shared_ptr<Type> t, std::shared_ptr<Module> mod, std::string symbol);

		void removeOperation();

		const std::weak_ptr<Module> getModule();

		const std::weak_ptr<Statements::Statement> getDefinition();
	};

}

#endif //SRC_USERDEFOP_H
