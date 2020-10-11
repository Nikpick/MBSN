//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_BLOCK_H
#define SRC_BLOCK_H

#include "Statements/NestedStatement.h"

namespace Statements {

	class Block : public NestedStatement, public std::enable_shared_from_this<Block> {
	public:
		explicit Block(std::shared_ptr<StatementOwner> own);

		void addStatem(std::shared_ptr<Statement> stat);
	};

}

#endif //SRC_BLOCK_H
