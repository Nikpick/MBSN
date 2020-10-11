cmake_minimum_required(VERSION 3.16)
project(custom)

set(CMAKE_CXX_STANDARD 17)

include_directories(cpp)
include_directories(cpp/Model)
include_directories(cpp/Statements)
include_directories(headers)
include_directories(headers/Model)
include_directories(headers/Statements)
include_directories(include)
include_directories(parser)
include_directories(toModelica)
include_directories(utils)
include_directories(utils/exceptions)
include_directories(/usr/include/libxml++/libxml++)
include_directories(/usr/include/libxml++)
include_directories(/usr/include/glib)
include_directories(/usr/include/glibmm)
include_directories(/usr/include/sbml)

file(GLOB               total
                        "/usr/include/sbml/math/*.cpp"
                        "/usr/include/sbml/math/*.h"
       )

set(SOURCE_FILES cpp/Model/Arg.cpp cpp/Model/BaseType.cpp cpp/Statements/Block.cpp cpp/Statements/Break.cpp cpp/Model/BuiltInOp.cpp cpp/Model/ConditionalExpression.cpp cpp/Model/Connection.cpp cpp/Model/Constant.cpp cpp/Model/DirConnection.cpp cpp/Statements/ElseStatem.cpp cpp/Model/Event.cpp cpp/Model/ExprVar.cpp cpp/Model/Expression.cpp cpp/Statements/ExpressionStatement.cpp cpp/Statements/ForStatem.cpp cpp/Statements/ForStatement.cpp cpp/Statements/IfStatement.cpp cpp/Model/InitAss.cpp cpp/Model/Literal.cpp cpp/Model/Module.cpp cpp/Statements/NestedStatement.cpp cpp/Model/Operation.cpp cpp/Model/OperationArg.cpp cpp/Model/OperationCall.cpp cpp/Model/Parameter.cpp cpp/Statements/Return.cpp cpp/Model/Species.cpp cpp/Statements/StNest.cpp cpp/Statements/Statement.cpp cpp/Statements/StatementOwner.cpp cpp/Statements/ThenStatem.cpp cpp/Model/Type.cpp cpp/Model/Unit.cpp cpp/Model/UserDefOp.cpp cpp/Model/Variable.cpp cpp/Statements/WhenStatem.cpp cpp/Statements/WhenStatement.cpp cpp/Statements/WhileStatem.cpp cpp/Statements/WhileStatement.cpp)
set(SOURCE_FILES ${SOURCE_FILES} headers/Model/Arg.h headers/Model/BaseType.h headers/Statements/Block.h headers/Statements/Break.h headers/Model/BuiltInOp.h headers/Model/ConditionalExpression.h headers/Model/Connection.h headers/Model/Constant.h headers/Model/DirConnection.h headers/Statements/ElseStatem.h headers/Model/Event.h headers/Model/ExprVar.h headers/Model/Expression.h headers/Statements/ExpressionStatement.h headers/Statements/ForStatem.h headers/Statements/ForStatement.h headers/Statements/IfStatement.h headers/Model/InitAss.h headers/Model/Literal.h headers/Model/Module.h headers/Statements/NestedStatement.h headers/Model/Operation.h headers/Model/OperationArg.h headers/Model/OperationCall.h headers/Model/Parameter.h headers/Statements/Return.h headers/Model/Species.h headers/Statements/StNest.h headers/Statements/Statement.h headers/Statements/StatementOwner.h headers/Statements/ThenStatem.h headers/Model/Type.h headers/Model/Unit.h headers/Model/UserDefOp.h headers/Model/Variable.h headers/Statements/WhenStatem.h headers/Statements/WhenStatement.h headers/Statements/WhileStatem.h headers/Statements/WhileStatement.h)
set(SOURCE_FILES ${SOURCE_FILES} include/AbstractAssociationLink.h include/AbstractAssociationRole.h include/ArrayIndexOutOfBoundsException.h include/DoubleOwnerAssociationLink.h include/MultiplicityConstraintException.h include/OrderedAssociationRole.h include/OrderedSet.h include/SingleOwnerAssociationLink.h include/StrongAssociationRole.h include/WeakAssociationRole.h)
set(SOURCE_FILES ${SOURCE_FILES} parser/Parser.cpp parser/Parser.h)
set(SOURCE_FILES ${SOURCE_FILES} utils/exceptions/AlgSectionException.cpp utils/exceptions/AlgorithmStatException.cpp utils/exceptions/AlreadyInModException.cpp utils/exceptions/ArrayIndexOutOfBoundsException.cpp utils/exceptions/AssInEventException.cpp utils/exceptions/BaseTypeException.cpp utils/exceptions/CondExpressionException.cpp utils/exceptions/ConditionTypeException.cpp utils/exceptions/DefInOperationException.cpp utils/exceptions/DelayTypeException.cpp utils/exceptions/ElseAlreadyInException.cpp utils/exceptions/ElseOnlyWithThenException.cpp utils/exceptions/ElseStatException.cpp utils/exceptions/EqualsVarInConnException.cpp utils/exceptions/ForIndexException.cpp utils/exceptions/InitAssException.cpp utils/exceptions/InitAssTypeException.cpp utils/exceptions/InitAssVarException.cpp utils/exceptions/IterationStatException.cpp utils/exceptions/LiteralException.cpp utils/exceptions/MultiplicityConstraintException.cpp utils/exceptions/NotInvolvedInLinkException.cpp utils/exceptions/NullPointerException.cpp utils/exceptions/OpNotInModException.cpp utils/exceptions/OperationTypeException.cpp utils/exceptions/ParameterException.cpp utils/exceptions/PriorityTypeException.cpp utils/exceptions/RemoveStatException.cpp utils/exceptions/StatInBlockException.cpp utils/exceptions/StatNotInWhenException.cpp utils/exceptions/StatemInWhenException.cpp utils/exceptions/StatementOwnerException.cpp utils/exceptions/TriggerTypeException.cpp utils/exceptions/TypeVarInConnException.cpp utils/exceptions/VarNotInModuleException.cpp utils/exceptions/WhenStatOwnerException.cpp utils/exceptions/WhileCondTypeException.cpp utils/exceptions/ArgumentInOtherFunctionException.cpp utils/exceptions/VarInAnotherModuleException.cpp utils/exceptions/StatementWithOwnerException.cpp utils/exceptions/NoStatementException.cpp utils/exceptions/NoPHMLInputException.cpp utils/exceptions/NoTypeFoundException.cpp utils/exceptions/NoUnitFoundException.cpp utils/exceptions/NoIDException.cpp utils/exceptions/NoModuleFoundException.cpp utils/exceptions/NoVariableFoundException.cpp utils/exceptions/NoModuleConnectionException.cpp utils/exceptions/NotSupportedException.cpp)
set(SOURCE_FILES ${SOURCE_FILES} main.cpp)
set(SOURCE_FILES ${SOURCE_FILES} toModelica/model2Modelica.cpp toModelica/model2Modelica.h)
set(SOURCE_FILES ${SOURCE_FILES} total)

add_executable(custom
        ${total}
        cpp/Model/Arg.cpp
        cpp/Model/BaseType.cpp
        cpp/Model/BuiltInOp.cpp
        cpp/Model/ConditionalExpression.cpp
        cpp/Model/Connection.cpp
        cpp/Model/Constant.cpp
        cpp/Model/DirConnection.cpp
        cpp/Model/Event.cpp
        cpp/Model/Expression.cpp
        cpp/Model/ExprVar.cpp
        cpp/Model/InitAss.cpp
        cpp/Model/Literal.cpp
        cpp/Model/Module.cpp
        cpp/Model/Operation.cpp
        cpp/Model/OperationArg.cpp
        cpp/Model/OperationCall.cpp
        cpp/Model/Parameter.cpp
        cpp/Model/Species.cpp
        cpp/Model/Type.cpp
        cpp/Model/Unit.cpp
        cpp/Model/UserDefOp.cpp
        cpp/Model/Variable.cpp
        cpp/Statements/Block.cpp
        cpp/Statements/Break.cpp
        cpp/Statements/ElseStatem.cpp
        cpp/Statements/ExpressionStatement.cpp
        cpp/Statements/ForStatem.cpp
        cpp/Statements/ForStatement.cpp
        cpp/Statements/IfStatement.cpp
        cpp/Statements/NestedStatement.cpp
        cpp/Statements/Return.cpp
        cpp/Statements/Statement.cpp
        cpp/Statements/StatementOwner.cpp
        cpp/Statements/StNest.cpp
        cpp/Statements/ThenStatem.cpp
        cpp/Statements/WhenStatem.cpp
        cpp/Statements/WhenStatement.cpp
        cpp/Statements/WhileStatem.cpp
        cpp/Statements/WhileStatement.cpp
        headers/Model/Arg.h
        headers/Model/BaseType.h
        headers/Model/BuiltInOp.h
        headers/Model/ConditionalExpression.h
        headers/Model/Connection.h
        headers/Model/Constant.h
        headers/Model/DirConnection.h
        headers/Model/Event.h
        headers/Model/Expression.h
        headers/Model/ExprVar.h
        headers/Model/InitAss.h
        headers/Model/Literal.h
        headers/Model/Module.h
        headers/Model/Operation.h
        headers/Model/OperationArg.h
        headers/Model/OperationCall.h
        headers/Model/Parameter.h
        headers/Model/Species.h
        headers/Model/Type.h
        headers/Model/Unit.h
        headers/Model/UserDefOp.h
        headers/Model/Variable.h
        headers/Statements/Block.h
        headers/Statements/Break.h
        headers/Statements/ElseStatem.h
        headers/Statements/ExpressionStatement.h
        headers/Statements/ForStatem.h
        headers/Statements/ForStatement.h
        headers/Statements/IfStatement.h
        headers/Statements/NestedStatement.h
        headers/Statements/Return.h
        headers/Statements/Statement.h
        headers/Statements/StatementOwner.h
        headers/Statements/StNest.h
        headers/Statements/ThenStatem.h
        headers/Statements/WhenStatem.h
        headers/Statements/WhenStatement.h
        headers/Statements/WhileStatem.h
        headers/Statements/WhileStatement.h
        include/AbstractAssociationLink.h
        include/AbstractAssociationRole.h
        include/ArrayIndexOutOfBoundsException.h
        include/DoubleOwnerAssociationLink.h
        include/MultiplicityConstraintException.h
        include/OrderedAssociationRole.h
        include/OrderedSet.h
        include/SingleOwnerAssociationLink.h
        include/StrongAssociationRole.h
        include/WeakAssociationRole.h
        parser/Parser.cpp
        parser/Parser.h
        toModelica/model2Modelica.cpp
        toModelica/model2Modelica.h
        utils/exceptions/AlgorithmStatException.cpp
        utils/exceptions/AlgSectionException.cpp
        utils/exceptions/AlreadyInModException.cpp
        utils/exceptions/ArgumentInOtherFunctionException.cpp
        utils/exceptions/ArrayIndexOutOfBoundsException.cpp
        utils/exceptions/AssInEventException.cpp
        utils/exceptions/BaseTypeException.cpp
        utils/exceptions/CondExpressionException.cpp
        utils/exceptions/ConditionTypeException.cpp
        utils/exceptions/DefInOperationException.cpp
        utils/exceptions/DelayTypeException.cpp
        utils/exceptions/ElseAlreadyInException.cpp
        utils/exceptions/ElseOnlyWithThenException.cpp
        utils/exceptions/ElseStatException.cpp
        utils/exceptions/EqualsVarInConnException.cpp
        utils/exceptions/ForIndexException.cpp
        utils/exceptions/InitAssException.cpp
        utils/exceptions/InitAssTypeException.cpp
        utils/exceptions/InitAssVarException.cpp
        utils/exceptions/IterationStatException.cpp
        utils/exceptions/LiteralException.cpp
        utils/exceptions/MultiplicityConstraintException.cpp
        utils/exceptions/NoIDException.cpp
        utils/exceptions/NoModuleConnectionException.cpp
        utils/exceptions/NoModuleFoundException.cpp
        utils/exceptions/NoPHMLInputException.cpp
        utils/exceptions/NoStatementException.cpp
        utils/exceptions/NotInvolvedInLinkException.cpp
        utils/exceptions/NotSupportedException.cpp
        utils/exceptions/NoTypeFoundException.cpp
        utils/exceptions/NoUnitFoundException.cpp
        utils/exceptions/NoVariableFoundException.cpp
        utils/exceptions/NullPointerException.cpp
        utils/exceptions/OperationTypeException.cpp
        utils/exceptions/OpNotInModException.cpp
        utils/exceptions/ParameterException.cpp
        utils/exceptions/PriorityTypeException.cpp
        utils/exceptions/RemoveStatException.cpp
        utils/exceptions/StatementOwnerException.cpp
        utils/exceptions/StatementWithOwnerException.cpp
        utils/exceptions/StatemInWhenException.cpp
        utils/exceptions/StatInBlockException.cpp
        utils/exceptions/StatNotInWhenException.cpp
        utils/exceptions/TriggerTypeException.cpp
        utils/exceptions/TypeVarInConnException.cpp
        utils/exceptions/VarInAnotherModuleException.cpp
        utils/exceptions/VarNotInModuleException.cpp
        utils/exceptions/WhenStatOwnerException.cpp
        utils/exceptions/WhileCondTypeException.cpp
        main.cpp)

include(FindPkgConfig)
pkg_check_modules(LIBXMLXX REQUIRED libxml++-3.0 libsbml glib-2.0 glibmm-2.4)
target_link_libraries(custom ${LIBXMLXX_LDFLAGS})
