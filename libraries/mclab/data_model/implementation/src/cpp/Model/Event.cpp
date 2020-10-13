//
// Created by Simone on 2019-08-18.
//

#include "Model/Event.h"
#include "Model/Module.h"
#include "Model/Expression.h"
#include "TriggerTypeException.cpp"
#include "DelayTypeException.cpp"
#include "PriorityTypeException.cpp"
#include "AssInEventException.cpp"

namespace Modeling {

	Event::Event(std::shared_ptr<Expression> tr, std::shared_ptr<Module> mod)
			: trigger(std::move(tr)), mod(std::move(mod)) {
		if (tr->getType().lock()->getName() != "Boolean")
			throw TriggerTypeException();
		else {
			auto ptr = shared_from_this();
			mod->addEvent(ptr);
		}
	}

	Event::Event(bool p, std::shared_ptr<Expression> tr, std::shared_ptr<Module> mod) : Event(tr, mod) {
		persistent = p;
	}

	Event::Event(bool p, std::shared_ptr<Expression> tr, std::shared_ptr<Module> mod, std::shared_ptr<Expression> delay)
			: Event(p, tr, mod) {
		setDelay(delay);
	}

	Event::Event(bool p, std::shared_ptr<Expression> tr, std::shared_ptr<Module> mod, std::shared_ptr<Expression> delay,
				 std::shared_ptr<Expression> priority) : Event(p, tr, mod, delay) {
		setPriority(priority);
	}

	bool Event::isPersistent() {
		return persistent;
	}

	const std::weak_ptr<Expression> Event::getDelay() {
		return delay;
	}

	void Event::setDelay(std::shared_ptr<Expression> &d) {
		if (delay->getType().lock()->getName() != "Real" and delay->getType().lock()->getName() != "Integer")
			throw DelayTypeException();
		else
			delay = d;
	}

	const std::weak_ptr<Expression> Event::getPriority() {
		return priority;
	}

	void Event::setPriority(std::shared_ptr<Expression> &p) {
		if (priority->getType().lock()->getName() != "Real" and priority->getType().lock()->getName() != "Integer")
			throw PriorityTypeException();
		else
			priority = p;
	}

	const std::weak_ptr<Expression> Event::getTrigger() {
		return trigger;
	}

	void Event::setTrigger(std::shared_ptr<Expression> &tr) {
		if (tr->getType().lock()->getName() != "Boolean")
			throw TriggerTypeException();
		else
			trigger = tr;
	}

	void Event::addAssignment(std::shared_ptr<Expression> &e) {
		if (getAssignment().count(e) == 0)
			assignment.insert(e);
		else
			throw AssInEventException();
	}

	const std::weak_ptr<Module> Event::getModule() {
		return mod;
	}

	const std::unordered_set<std::shared_ptr<Expression>> Event::getAssignment() {
		return assignment;
	}

	void Event::removeAssignment(std::shared_ptr<Expression> &e) {
		assignment.erase(e);
	}

	void Event::removeEvent() {
		auto ptr = shared_from_this();
		mod->removeEvent(ptr);
		this->~Event();
	}

	bool operator==(const Event &e1, const Event &e2) {
		return e1.trigger == e2.trigger and e1.delay == e2.delay and e1.persistent == e2.persistent and
			   e1.priority == e2.priority and e1.assignment == e2.assignment and e1.mod == e2.mod;
	}

	bool operator!=(const Event &e1, const Event &e2) {
		return !(e1 == e2);
	}

}