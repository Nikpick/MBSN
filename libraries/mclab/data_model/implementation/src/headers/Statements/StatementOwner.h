//
// Created by Simone on 2019-08-27.
//

#ifndef SRC_STATEMENTOWNER_H
#define SRC_STATEMENTOWNER_H

namespace Statements {

	class Statement;

	class StatementOwner {
		friend class Statement;

	protected:
		StatementOwner() = default;

	public:
		virtual ~StatementOwner() = 0;
	};

}

#endif //SRC_STATEMENTOWNER_H
