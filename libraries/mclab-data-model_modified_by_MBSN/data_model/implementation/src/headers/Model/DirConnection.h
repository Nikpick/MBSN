//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_DIRCONNECTION_H
#define SRC_DIRCONNECTION_H

#include "Connection.h"

namespace Modeling {

	class Variable;

	class DirConnection : public Connection {
	private:
		std::shared_ptr<Variable> connInVar;
		std::shared_ptr<Variable> connOutVar;
	public:
		DirConnection(std::shared_ptr<Variable> &in, std::shared_ptr<Variable> &out);

		const std::weak_ptr<Variable> getInVar();

		const std::weak_ptr<Variable> getOutVar();

		void setInVar(std::shared_ptr<Variable> &var);

		void setOutVar(std::shared_ptr<Variable> &var);
	};

}

#endif //SRC_DIRCONNECTION_H
