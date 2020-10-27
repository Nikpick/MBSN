//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_RETURN_H
#define SRC_RETURN_H

#include "Statements/Statement.h"

namespace Statements {

	class Return : public Statement {
	public:
		explicit Return(std::shared_ptr<StatementOwner> own);

		Return();
	};

}

#endif //SRC_RETURN_H
