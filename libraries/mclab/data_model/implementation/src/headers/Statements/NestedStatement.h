//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_NESTEDSTATEMENT_H
#define SRC_NESTEDSTATEMENT_H

#include <set>
#include "OrderedAssociationRole.h"
#include "StatementOwner.h"
#include "Statement.h"

namespace Statements {

	class StNest;

	class NestedStatement : public StatementOwner, protected Statement, protected OrderedAssociationRole<StNest, 0, N> {
	protected:
		explicit NestedStatement(std::shared_ptr<StatementOwner> own);

		NestedStatement();

		void addStatement(std::shared_ptr<StNest> &stat);

	public:
		virtual ~NestedStatement() = default;

		const std::set<std::shared_ptr<Statement>> getStatements() const;
	};

}

#endif //SRC_NESTEDSTATEMENT_H
