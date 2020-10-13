//
// Created by Simone on 2019-08-18.
//

#include "Model/UserDefOp.h"
#include "Model/Module.h"
#include "Statements/Statement.h"
#include "StatementOwnerException.cpp"
#include "DefInOperationException.cpp"

namespace Modeling {

	UserDefOp::UserDefOp(std::string n, std::shared_ptr<Type> t, std::shared_ptr<Module> mod, std::string symbol)
			: Operation(std::move(n), std::move(t), std::move(symbol)), mod(std::move(mod)) {
		auto ptr = shared_from_this();
		mod->addOperation(ptr);
	}

	void UserDefOp::removeOperation() {
		auto ptr = shared_from_this();
		mod->removeOperation(ptr);
		this->~UserDefOp();
	}

	void UserDefOp::addStatement(std::shared_ptr<Statements::Statement> &stat) {
		if (stat->getOwner().lock().get() != this)
			throw StatementOwnerException();
		else if (def != nullptr)
			throw DefInOperationException();
		else
			def = stat;
	}

	const std::weak_ptr<Module> UserDefOp::getModule() {
		return mod;
	}

	const std::weak_ptr<Statements::Statement> UserDefOp::getDefinition() {
		return def;
	}

}
