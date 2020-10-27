//
// Created by Simone on 2019-08-18.
//

#ifndef SRC_STATEMENT_H
#define SRC_STATEMENT_H

#include <memory>

namespace Statements {

	class NestedStatement;

	class StatementOwner;

	class WhileStatem;

	class ForStatem;

	class WhenStatem;

	class ThenStatem;

	class ElseStatem;

	class Statement {
		friend class NestedStatement;

	protected:
		std::shared_ptr<StatementOwner> owner = nullptr;

		explicit Statement(std::shared_ptr<StatementOwner> own);

		Statement() = default;

	public:
		void setOwner(std::shared_ptr<StatementOwner> own);

		virtual ~Statement() = default;

		const std::weak_ptr<StatementOwner> getOwner();
	};

}

#endif //SRC_STATEMENT_H
