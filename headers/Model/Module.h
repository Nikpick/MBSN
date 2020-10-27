//
// Created by Simone on 2019-08-17.
//

#ifndef SRC_MODULE_H
#define SRC_MODULE_H

#include <unordered_set>
#include <vector>
#include "Type.h"
#include "Statements/StatementOwner.h"

namespace Modeling {

	class Variable;

	class InitAss;

	class UserDefOp;

	class Connection;

	class Event;

	class Expression;

class Module : public Type, public Statements::StatementOwner {
		friend class UserDefOp;

		friend class Variable;

		friend class Event;

		friend class Connection;

	private:
		std::unordered_set<std::shared_ptr<Expression>> modExpr;
		std::vector<std::string> expressions;
		std::unordered_set<std::shared_ptr<Variable>> vars;
		std::unordered_set<std::shared_ptr<UserDefOp>> ops;
		std::unordered_set<std::shared_ptr<Event>> evs;
		std::unordered_set<std::shared_ptr<Connection>> conns;
		std::unordered_set<std::shared_ptr<InitAss>> inits;
		std::shared_ptr<Statements::Statement> algSection = nullptr;

		void addOperation(std::shared_ptr<UserDefOp> &op);

		void removeOperation(std::shared_ptr<UserDefOp> &op);

		void addVariable(std::shared_ptr<Variable> &v);

		void removeVariable(std::shared_ptr<Variable> &v);

		void addEvent(std::shared_ptr<Event> &e);

		void removeEvent(std::shared_ptr<Event> &e);

		void addConnection(std::shared_ptr<Connection> &c);

		void removeConnection(std::shared_ptr<Connection> &c);

		void addInitAss(std::shared_ptr<InitAss> &i);

		void removeInitAss(std::shared_ptr<InitAss> &i);

		void addStatement(std::shared_ptr<Statements::Statement> &stat);

	public:
		explicit Module(std::string name);

		void addModExpr(std::shared_ptr<Expression> &e);

		void removeModExpr(std::shared_ptr<Expression> &e);

		void removeAlgSection();

		void addExpression(std::string expr);

		const std::vector<std::string> getExpression();

		const std::unordered_set<std::shared_ptr<Expression>> getModExpr();

		const std::unordered_set<std::shared_ptr<Variable>> getVars();

		const std::unordered_set<std::shared_ptr<UserDefOp>> getOperations();

		const std::unordered_set<std::shared_ptr<Event>> getEvents();

		const std::unordered_set<std::shared_ptr<Connection>> getConnections();

		const std::unordered_set<std::shared_ptr<InitAss>> getInitialAss();

		const std::weak_ptr<Statements::Statement> getAlgSection();

		friend bool operator==(const Module &m1, const Module &m2);

		friend bool operator!=(const Module &m1, const Module &m2);
	};

}

#endif //SRC_MODULE_H
