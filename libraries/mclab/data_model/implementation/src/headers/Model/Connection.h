//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_CONNECTION_H
#define SRC_CONNECTION_H

#include <memory>

namespace Modeling {

	class Module;

	class Connection : public std::enable_shared_from_this<Connection> {
	protected:
		std::shared_ptr<Module> mod;

		void removeConnection();

	public:
		virtual ~Connection() = 0;

		Connection();

		void setModule(std::shared_ptr<Module> mod);

		const std::weak_ptr<Module> getModule();
	};

}

#endif //SRC_CONNECTION_H
