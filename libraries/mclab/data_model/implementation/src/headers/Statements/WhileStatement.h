//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_WHILESTATEMENT_H
#define SRC_WHILESTATEMENT_H

#include <memory>
#include "NestedStatement.h"

namespace Modeling {
	class Expression;
}

namespace Statements {
	class WhileStatem;

	class WhileStatement : public NestedStatement, protected OrderedAssociationRole<WhileStatem, 1, 1> {
	private:
		std::shared_ptr<Modeling::Expression> whileCond;
	public:
		WhileStatement(std::shared_ptr<Modeling::Expression> c, std::shared_ptr<Statement> stat);

		WhileStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Modeling::Expression> c,
					   std::shared_ptr<Statement> stat);

		const std::weak_ptr<Modeling::Expression> getWhilecond() const;

		const std::weak_ptr<Statement> getStatement() const;
	};

}

#endif //SRC_WHILESTATEMENT_H
