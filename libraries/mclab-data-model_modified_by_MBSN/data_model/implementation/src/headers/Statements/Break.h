//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_BREAK_H
#define SRC_BREAK_H

#include "Statements/Statement.h"

namespace Statements {

	class Break : public Statement {
	public:
		explicit Break(std::shared_ptr<StatementOwner> own);

		Break();
	};

}

#endif //SRC_BREAK_H
