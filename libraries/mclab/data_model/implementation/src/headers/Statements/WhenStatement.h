//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_WHENSTATEMENT_H
#define SRC_WHENSTATEMENT_H

#include <map>
#include "NestedStatement.h"

namespace Modeling {
	class Expression;
}

namespace Statements {
	class WhenStatem;

	class WhenStatement : public NestedStatement,
						  protected OrderedAssociationRole<WhenStatem, 0, N>,
						  public std::enable_shared_from_this<WhenStatement> {
	private:
		bool findCondition(std::shared_ptr<Modeling::Expression> &cond);

	public:
		WhenStatement(std::shared_ptr<Statement> stat, std::shared_ptr<Modeling::Expression> cond);

		WhenStatement(std::shared_ptr<StatementOwner> own, std::shared_ptr<Statement> stat,
					  std::shared_ptr<Modeling::Expression> cond);

		void addStatement(std::shared_ptr<Statement> &stat, std::shared_ptr<Modeling::Expression> cond);

		void setWhenCondition(std::shared_ptr<WhenStatem> &st, std::shared_ptr<Modeling::Expression> c);

		const std::map<std::shared_ptr<Modeling::Expression>, std::shared_ptr<Statement>> getStatements() const;
	};

}

#endif //SRC_WHENSTATEMENT_H
