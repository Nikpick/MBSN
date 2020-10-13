//
// Created by Simone on 2019-08-17.
//

#include "Model/Variable.h"
#include "Model/InitAss.h"
#include "Model/Expression.h"
#include "InitAssException.cpp"
#include "InitAssVarException.cpp"
#include "InitAssTypeException.cpp"
#include "VarInAnotherModuleException.cpp"

namespace Modeling {

	void Variable::setModule(std::shared_ptr<Module> module) {
		if (mod != nullptr)
			throw VarInAnotherModuleException();
		else {
			mod = std::move(module);
			auto ptr = shared_from_this();
			mod->addVariable(ptr);
		}
	}

	Variable::~Variable() = default;

	std::string Variable::getName() {
		return name;
	}

	void Variable::setName(std::string n) {
		name = std::move(n);
	}

	const std::weak_ptr<Unit> Variable::getUnit() {
		return unit;
	}

	void Variable::setUnit(std::shared_ptr<Unit> &u) {
		unit = u;
	}

	const std::weak_ptr<Type> Variable::getType() {
		return type;
	}

	void Variable::setType(std::shared_ptr<Type> &t) {
		type = t;
	}

	void Variable::removeVar() {
		auto ptr = shared_from_this();
		mod->removeVariable(ptr);
		this->~Variable();
	}

	const std::weak_ptr<Module> Variable::getModule() {
		return mod;
	}

	void Variable::addInitAss(std::shared_ptr<Expression> &val) {
		/*if (this->getType().lock().get() != val->getType().lock().get())
			throw InitAssTypeException();
		else */
		if (init != nullptr)
			throw InitAssException();
		else {
			init = std::make_shared<InitAss>(val, mod, shared_from_this());
			mod->addInitAss(init);
		}
	}

	void Variable::setInitAss(std::shared_ptr<Expression> &val) {
		if (init != nullptr)
			init->setInitialAss(val);
		else
			addInitAss(val);
	}

	void Variable::removeInitAss(std::shared_ptr<InitAss> &i) {
		if (i->getVariable().lock() == shared_from_this()) {
			mod->removeInitAss(i);
			init = nullptr;
			i->~InitAss();
		} else
			throw InitAssVarException(this->getName());
	}

	const std::weak_ptr<InitAss> Variable::getInitAss() {
		return init;
	}

	bool operator==(const Variable &v1, const Variable &v2) {
		return v1.name == v2.name and v1.mod == v2.mod and v1.type == v2.type;
	}

	bool operator!=(const Variable &v1, const Variable &v2) {
		return !(v1 == v2);
	}

	Variable::Variable(std::string name, std::shared_ptr<Unit> &u, std::shared_ptr<Type> &t)
			: name(std::move(name)), unit(u), type(t) {
	}

	Variable::Variable(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in)
			: Variable(std::move(name), unit, type) {
		input = in;
	}

	Variable::Variable(std::string name, std::shared_ptr<Unit> &unit, std::shared_ptr<Type> &type, bool in, bool out)
			: Variable(std::move(name), unit, type, in) {
		output = out;
	}

	bool Variable::isOutput() {
		return output;
	}

	bool Variable::isInput() {
		return input;
	}

	void Variable::addInitialAss(std::string initAss) {
		initialAss = std::move(initAss);
	}

	const std::string Variable::getInitialAss() {
		return initialAss.empty() ? throw "No initial assignment for this variable." : initialAss;
	}

}
