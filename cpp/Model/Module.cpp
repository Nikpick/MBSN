//
// Created by Simone on 2019-08-17.
//

#include "Model/Module.h"

#include <utility>
#include "Model/Variable.h"
#include "Model/UserDefOp.h"
#include "Statements/Statement.h"
#include "AlgSectionException.cpp"
#include "AlreadyInModException.cpp"
#include "StatementOwnerException.cpp"
#include "AlgorithmStatException.cpp"
#include "NoIDException.cpp"

namespace Modeling {

	Module::Module(std::string name) : Type(std::move(name)) {
	}

	void Module::addStatement(std::shared_ptr<Statements::Statement> &stat) {
		if (stat->getOwner().lock().get() != this)
			throw StatementOwnerException();
		else if (algSection != nullptr)
			throw AlreadyInModException("algorithm section");
		else
			algSection = stat;
	}

	void Module::removeAlgSection() {
		if (algSection != nullptr)
			algSection = nullptr;
		else
			throw AlgorithmStatException();
	}

	void Module::addModExpr(std::shared_ptr<Expression> &e) {
		if (getModExpr().count(e) == 0)
			modExpr.insert(e);
		else
			throw AlreadyInModException("Expression");
	}

	void Module::addExpression(std::string expr) {
		expressions.push_back(expr);
	}

	const std::vector<std::string> Module::getExpression() {
		return expressions;
	}


	void Module::removeModExpr(std::shared_ptr<Expression> &e) {
		modExpr.erase(e);
	}

	void Module::addVariable(std::shared_ptr<Variable> &v) {
		if (getVars().count(v) == 0)
			vars.insert(v);
		else
			throw AlreadyInModException(std::string("variable" + v->getName()));
	}

	void Module::removeVariable(std::shared_ptr<Variable> &v) {
		vars.erase(v);
	}

	void Module::addOperation(std::shared_ptr<UserDefOp> &op) {
		if (getOperations().count(op) == 0)
			ops.insert(op);
		else
			throw AlreadyInModException(std::string("operation" + op->getName()));
	}

	void Module::removeOperation(std::shared_ptr<UserDefOp> &op) {
		ops.erase(op);
	}

	void Module::addEvent(std::shared_ptr<Event> &e) {
		if (getEvents().count(e) == 0)
			evs.insert(e);
		else
			throw AlreadyInModException("Event");
	}

	void Module::removeEvent(std::shared_ptr<Event> &e) {
		evs.erase(e);
	}

	void Module::addConnection(std::shared_ptr<Connection> &c) {
		if (getConnections().count(c) == 0)
			conns.insert(c);
		else
			throw AlreadyInModException("Connection");
	}

	void Module::removeConnection(std::shared_ptr<Connection> &c) {
		conns.erase(c);
	}

	void Module::addInitAss(std::shared_ptr<InitAss> &i) {
		if (getInitialAss().count(i) == 0)
			inits.insert(i);
		else
			throw AlreadyInModException("Initial Assignment");
	}

	void Module::removeInitAss(std::shared_ptr<InitAss> &i) {
		inits.erase(i);
	}

	const std::unordered_set<std::shared_ptr<UserDefOp>> Module::getOperations() {
		return ops;
	}

	const std::unordered_set<std::shared_ptr<Event>> Module::getEvents() {
		return evs;
	}

	const std::unordered_set<std::shared_ptr<Connection>> Module::getConnections() {
		return conns;
	}

	const std::unordered_set<std::shared_ptr<InitAss>> Module::getInitialAss() {
		return inits;
	}

	const std::unordered_set<std::shared_ptr<Expression>> Module::getModExpr() {
		return modExpr;
	}

	const std::unordered_set<std::shared_ptr<Variable>> Module::getVars() {
		return vars;
	}

	const std::weak_ptr<Statements::Statement> Module::getAlgSection() {
		return algSection ? throw AlgSectionException() : algSection;
	}

	bool operator==(const Module &m1, const Module &m2) {
		return m1.name == m2.name and m1.vars == m2.vars and m1.modExpr == m2.modExpr and m1.conns == m2.conns and
			   m1.evs == m2.evs and m1.algSection == m2.algSection and m1.inits == m2.inits and m1.ops == m2.ops;
	}

	bool operator!=(const Module &m1, const Module &m2) {
		return !(m1 == m2);
	}

}
