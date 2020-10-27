//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_IFSTATEMENT_H
#define SRC_IFSTATEMENT_H

#include "NestedStatement.h"

namespace Modeling {
	class Expression;
}

namespace Statements {
	class ThenStatem;

	class ElseStatem;

	class IfStatement : public NestedStatement,
						protected OrderedAssociationRole<ThenStatem, 1, 1>,
						protected OrderedAssociationRole<ElseStatem, 0, 1>,
						public std::enable_shared_from_this<IfStatement> {
	private:
		std::shared_ptr<Modeling::Expression> condIfSt;
	public:
		IfStatement(std::shared_ptr<Modeling::Expression> c, std::shared_ptr<Statement> stat);

		IfStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Modeling::Expression> c,
					std::shared_ptr<Statement> stat);

		IfStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Modeling::Expression> c, std::shared_ptr<Statement> then,
					std::shared_ptr<Statement> els);

		IfStatement(std::shared_ptr<Modeling::Expression> c, std::shared_ptr<Statement> then, std::shared_ptr<Statement> els);

		const std::weak_ptr<Modeling::Expression> getCondition() const;

		void addElseStatement(std::shared_ptr<Statement> stat);

		const std::weak_ptr<Statement> getElse() const;

		const std::weak_ptr<Statement> getThen() const;

	};

}

#endif //SRC_IFSTATEMENT_H
