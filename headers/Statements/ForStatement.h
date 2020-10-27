//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_FORSTATEMENT_H
#define SRC_FORSTATEMENT_H

#include "NestedStatement.h"

namespace Modeling {
	class Expression;
}

namespace Statements {
	class ForStatem;

	class ForStatement : public NestedStatement,
						 protected OrderedAssociationRole<ForStatem, 1, 1>,
						 public std::enable_shared_from_this<ForStatement> {
	private:
		std::shared_ptr<Modeling::Expression> begin;
		std::shared_ptr<Modeling::Expression> step;
		std::shared_ptr<Modeling::Expression> upTo;
	public:
		ForStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Modeling::Expression> b, std::shared_ptr<Modeling::Expression> s,
					 std::shared_ptr<Modeling::Expression> u, std::shared_ptr<Statement> stat);

		ForStatement(std::shared_ptr<Modeling::Expression> b, std::shared_ptr<Modeling::Expression> s, std::shared_ptr<Modeling::Expression> u,
					 std::shared_ptr<Statement> stat);

		const std::shared_ptr<Modeling::Expression> getBegin() const;

		const std::shared_ptr<Modeling::Expression> getStep() const;

		const std::shared_ptr<Modeling::Expression> getUpTo() const;

		const std::weak_ptr<Statement> getStatement() const;
	};

}

#endif //SRC_FORSTATEMENT_H
