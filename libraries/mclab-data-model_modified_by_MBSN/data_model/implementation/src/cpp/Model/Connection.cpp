//
// Created by Simone on 2019-08-18.
//

#include "Model/Connection.h"
#include "Model/Module.h"

namespace Modeling {

	Connection::Connection() = default;

	Connection::~Connection() = default;

	const std::weak_ptr<Module> Connection::getModule() {
		return mod;
	}

	void Connection::removeConnection() {
		auto ptr = shared_from_this();
		mod->removeConnection(ptr);
		this->~Connection();
	}

	void Connection::setModule(std::shared_ptr<Module> mod) {
		auto ptr = shared_from_this();
		mod->addConnection(ptr);
	}

}
