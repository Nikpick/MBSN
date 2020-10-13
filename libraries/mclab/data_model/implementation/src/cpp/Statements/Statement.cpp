//
// Created by Simone on 2019-08-18.
//

#include "Statements/Statement.h"
#include "Statements/StatementOwner.h"
#include "NullPointerException.cpp"
#include "NotInvolvedInLinkException.cpp"
#include "StatementWithOwnerException.cpp"

namespace Statements {

	Statement::Statement(std::shared_ptr<StatementOwner> own) {
		if (!own)
			throw NullPointerException();
		this->owner = std::move(own);
	}

	const std::weak_ptr<StatementOwner> Statement::getOwner() {
		return owner;
	}

	void Statement::setOwner(std::shared_ptr<StatementOwner> own) {
		if (owner != nullptr)
			throw StatementWithOwnerException();
		else
			owner = std::move(own);
	}

}
