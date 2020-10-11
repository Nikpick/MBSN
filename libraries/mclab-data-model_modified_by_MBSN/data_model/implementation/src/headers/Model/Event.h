//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_EVENT_H
#define SRC_EVENT_H

#include <unordered_set>
#include <memory>
#include "Module.h"

namespace Modeling {

	class Expression;

	class Module;

	class Event : std::enable_shared_from_this<Event> {
	private:
		bool persistent = false;
		std::shared_ptr<Expression> delay = nullptr;
		std::shared_ptr<Expression> priority = nullptr;
		std::shared_ptr<Expression> trigger;
		std::unordered_set<std::shared_ptr<Expression>> assignment;
		std::shared_ptr<Module> mod;
	public:
		Event(std::shared_ptr<Expression> trigger, std::shared_ptr<Module> mod);

		Event(bool p, std::shared_ptr<Expression> trigger, std::shared_ptr<Module> mod);

		Event(bool p, std::shared_ptr<Expression> trigger, std::shared_ptr<Module> mod,
			  std::shared_ptr<Expression> delay);

		Event(bool p, std::shared_ptr<Expression> trigger, std::shared_ptr<Module> mod,
			  std::shared_ptr<Expression> delay, std::shared_ptr<Expression> priority);

		bool isPersistent();

		const std::weak_ptr<Expression> getDelay();

		void setDelay(std::shared_ptr<Expression> &d);

		const std::weak_ptr<Expression> getPriority();

		void setPriority(std::shared_ptr<Expression> &p);

		const std::weak_ptr<Expression> getTrigger();

		void setTrigger(std::shared_ptr<Expression> &tr);

		void addAssignment(std::shared_ptr<Expression> &e);

		void removeAssignment(std::shared_ptr<Expression> &e);

		const std::weak_ptr<Module> getModule();

		const std::unordered_set<std::shared_ptr<Expression>> getAssignment();

		void removeEvent();

		friend bool operator==(const Event &e1, const Event &e2);

		friend bool operator!=(const Event &e1, const Event &e2);
	};

}

#endif //SRC_EVENT_H
