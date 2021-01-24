cmake_minimum_required(VERSION 3.0.0)
project(MBSN VERSION 0.1.0)

include(CTest)
enable_testing()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_TOOLCHAIN_FILE libraries/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(SOURCE_FILES libraries/mclab-data-model/cpp/Model/Arg.cpp libraries/mclab-data-model/cpp/Model/BaseType.cpp libraries/mclab-data-model/cpp/Statements/Block.cpp libraries/mclab-data-model/cpp/Statements/Break.cpp libraries/mclab-data-model/cpp/Model/BuiltInOp.cpp libraries/mclab-data-model/cpp/Model/ConditionalExpression.cpp libraries/mclab-data-model/cpp/Model/Connection.cpp libraries/mclab-data-model/cpp/Model/Constant.cpp libraries/mclab-data-model/cpp/Model/DirConnection.cpp libraries/mclab-data-model/cpp/Statements/ElseStatem.cpp libraries/mclab-data-model/cpp/Model/Event.cpp libraries/mclab-data-model/cpp/Model/ExprVar.cpp libraries/mclab-data-model/cpp/Model/Expression.cpp libraries/mclab-data-model/cpp/Statements/ExpressionStatement.cpp libraries/mclab-data-model/cpp/Statements/ForStatem.cpp libraries/mclab-data-model/cpp/Statements/ForStatement.cpp libraries/mclab-data-model/cpp/Statements/IfStatement.cpp libraries/mclab-data-model/cpp/Model/InitAss.cpp libraries/mclab-data-model/cpp/Model/Literal.cpp libraries/mclab-data-model/cpp/Model/Module.cpp libraries/mclab-data-model/cpp/Statements/NestedStatement.cpp libraries/mclab-data-model/cpp/Model/Operation.cpp libraries/mclab-data-model/cpp/Model/OperationArg.cpp libraries/mclab-data-model/cpp/Model/OperationCall.cpp libraries/mclab-data-model/cpp/Model/Parameter.cpp libraries/mclab-data-model/cpp/Statements/Return.cpp libraries/mclab-data-model/cpp/Model/Species.cpp libraries/mclab-data-model/cpp/Statements/StNest.cpp libraries/mclab-data-model/cpp/Statements/Statement.cpp libraries/mclab-data-model/cpp/Statements/StatementOwner.cpp libraries/mclab-data-model/cpp/Statements/ThenStatem.cpp libraries/mclab-data-model/cpp/Model/Type.cpp libraries/mclab-data-model/cpp/Model/Unit.cpp libraries/mclab-data-model/cpp/Model/UserDefOp.cpp libraries/mclab-data-model/cpp/Model/Variable.cpp libraries/mclab-data-model/cpp/Statements/WhenStatem.cpp libraries/mclab-data-model/cpp/Statements/WhenStatement.cpp libraries/mclab-data-model/cpp/Statements/WhileStatem.cpp libraries/mclab-data-model/cpp/Statements/WhileStatement.cpp)
set(SOURCE_FILES ${SOURCE_FILES} libraries/mclab-data-model/headers/Model/Arg.h libraries/mclab-data-model/headers/Model/BaseType.h libraries/mclab-data-model/headers/Statements/Block.h libraries/mclab-data-model/headers/Statements/Break.h libraries/mclab-data-model/headers/Model/BuiltInOp.h libraries/mclab-data-model/headers/Model/ConditionalExpression.h libraries/mclab-data-model/headers/Model/Connection.h libraries/mclab-data-model/headers/Model/Constant.h libraries/mclab-data-model/headers/Model/DirConnection.h libraries/mclab-data-model/headers/Statements/ElseStatem.h libraries/mclab-data-model/headers/Model/Event.h libraries/mclab-data-model/headers/Model/ExprVar.h libraries/mclab-data-model/headers/Model/Expression.h libraries/mclab-data-model/headers/Statements/ExpressionStatement.h libraries/mclab-data-model/headers/Statements/ForStatem.h libraries/mclab-data-model/headers/Statements/ForStatement.h libraries/mclab-data-model/headers/Statements/IfStatement.h libraries/mclab-data-model/headers/Model/InitAss.h libraries/mclab-data-model/headers/Model/Literal.h libraries/mclab-data-model/headers/Model/Module.h libraries/mclab-data-model/headers/Statements/NestedStatement.h libraries/mclab-data-model/headers/Model/Operation.h libraries/mclab-data-model/headers/Model/OperationArg.h libraries/mclab-data-model/headers/Model/OperationCall.h libraries/mclab-data-model/headers/Model/Parameter.h libraries/mclab-data-model/headers/Statements/Return.h libraries/mclab-data-model/headers/Model/Species.h libraries/mclab-data-model/headers/Statements/StNest.h libraries/mclab-data-model/headers/Statements/Statement.h libraries/mclab-data-model/headers/Statements/StatementOwner.h libraries/mclab-data-model/headers/Statements/ThenStatem.h libraries/mclab-data-model/headers/Model/Type.h libraries/mclab-data-model/headers/Model/Unit.h libraries/mclab-data-model/headers/Model/UserDefOp.h libraries/mclab-data-model/headers/Model/Variable.h libraries/mclab-data-model/headers/Statements/WhenStatem.h libraries/mclab-data-model/headers/Statements/WhenStatement.h libraries/mclab-data-model/headers/Statements/WhileStatem.h libraries/mclab-data-model/headers/Statements/WhileStatement.h)
set(SOURCE_FILES ${SOURCE_FILES} libraries/mclab-data-model/utils/exceptions/AlgSectionException.cpp libraries/mclab-data-model/utils/exceptions/AlgorithmStatException.cpp libraries/mclab-data-model/utils/exceptions/AlreadyInModException.cpp libraries/mclab-data-model/utils/exceptions/ArrayIndexOutOfBoundsException.cpp libraries/mclab-data-model/utils/exceptions/AssInEventException.cpp libraries/mclab-data-model/utils/exceptions/BaseTypeException.cpp libraries/mclab-data-model/utils/exceptions/CondExpressionException.cpp libraries/mclab-data-model/utils/exceptions/ConditionTypeException.cpp libraries/mclab-data-model/utils/exceptions/DefInOperationException.cpp libraries/mclab-data-model/utils/exceptions/DelayTypeException.cpp libraries/mclab-data-model/utils/exceptions/ElseAlreadyInException.cpp libraries/mclab-data-model/utils/exceptions/ElseOnlyWithThenException.cpp libraries/mclab-data-model/utils/exceptions/ElseStatException.cpp libraries/mclab-data-model/utils/exceptions/EqualsVarInConnException.cpp libraries/mclab-data-model/utils/exceptions/ForIndexException.cpp libraries/mclab-data-model/utils/exceptions/InitAssException.cpp libraries/mclab-data-model/utils/exceptions/InitAssTypeException.cpp libraries/mclab-data-model/utils/exceptions/InitAssVarException.cpp libraries/mclab-data-model/utils/exceptions/IterationStatException.cpp libraries/mclab-data-model/utils/exceptions/LiteralException.cpp libraries/mclab-data-model/utils/exceptions/MultiplicityConstraintException.cpp libraries/mclab-data-model/utils/exceptions/NotInvolvedInLinkException.cpp libraries/mclab-data-model/utils/exceptions/NullPointerException.cpp libraries/mclab-data-model/utils/exceptions/OpNotInModException.cpp libraries/mclab-data-model/utils/exceptions/OperationTypeException.cpp libraries/mclab-data-model/utils/exceptions/ParameterException.cpp libraries/mclab-data-model/utils/exceptions/PriorityTypeException.cpp libraries/mclab-data-model/utils/exceptions/RemoveStatException.cpp libraries/mclab-data-model/utils/exceptions/StatInBlockException.cpp libraries/mclab-data-model/utils/exceptions/StatNotInWhenException.cpp libraries/mclab-data-model/utils/exceptions/StatemInWhenException.cpp libraries/mclab-data-model/utils/exceptions/StatementOwnerException.cpp libraries/mclab-data-model/utils/exceptions/TriggerTypeException.cpp libraries/mclab-data-model/utils/exceptions/TypeVarInConnException.cpp libraries/mclab-data-model/utils/exceptions/VarNotInModuleException.cpp libraries/mclab-data-model/utils/exceptions/WhenStatOwnerException.cpp libraries/mclab-data-model/utils/exceptions/WhileCondTypeException.cpp libraries/mclab-data-model/utils/exceptions/ArgumentInOtherFunctionException.cpp libraries/mclab-data-model/utils/exceptions/VarInAnotherModuleException.cpp libraries/mclab-data-model/utils/exceptions/StatementWithOwnerException.cpp libraries/mclab-data-model/utils/exceptions/NoStatementException.cpp libraries/mclab-data-model/utils/exceptions/NoPHMLInputException.cpp libraries/mclab-data-model/utils/exceptions/NoTypeFoundException.cpp libraries/mclab-data-model/utils/exceptions/NoUnitFoundException.cpp libraries/mclab-data-model/utils/exceptions/NoIDException.cpp libraries/mclab-data-model/utils/exceptions/NoModuleFoundException.cpp libraries/mclab-data-model/utils/exceptions/NoVariableFoundException.cpp libraries/mclab-data-model/utils/exceptions/NoModuleConnectionException.cpp libraries/mclab-data-model/utils/exceptions/NotSupportedException.cpp)
set(SOURCE_FILES ${SOURCE_FILES} libraries/mclab-data-model/include/AbstractAssociationLink.h libraries/mclab-data-model/include/AbstractAssociationRole.h libraries/mclab-data-model/include/ArrayIndexOutOfBoundsException.h libraries/mclab-data-model/include/DoubleOwnerAssociationLink.h libraries/mclab-data-model/include/MultiplicityConstraintException.h libraries/mclab-data-model/include/OrderedAssociationRole.h libraries/mclab-data-model/include/OrderedSet.h libraries/mclab-data-model/include/SingleOwnerAssociationLink.h libraries/mclab-data-model/include/StrongAssociationRole.h libraries/mclab-data-model/include/WeakAssociationRole.h)
set(SOURCE_FILES ${SOURCE_FILES} cpp/json_reader.cpp cpp/json_reader.h cpp/mathML_to_string.cpp cpp/mathML_to_string.h cpp/parser.cpp cpp/parser.h)
set(SOURCE_FILES ${SOURCE_FILES} main.cpp)

include_directories(libraries/vcpkg/installed/x86-windows/include)
link_directories(./libraries/vcpkg/packages/libsbml_x86-windows/lib)
link_directories(./libraries/vcpkg/packages/jsoncpp_x86-windows/lib)


#find_package(libsbml CONFIG REQUIRED)

add_executable(MBSN ${SOURCE_FILES})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(EXTERNAL_LIB_HEADERS libraries/mclab-data-model/headers)
set(EXTERNAL_LIB_HEAD_STATE libraries/mclab-data-model/headers/Statements)
set(EXTERNAL_LIB_HEAD_MOD libraries/mclab-data-model/headers/Model)
set(EXTERNAL_LIB_INCLUDE libraries/mclab-data-model/include)
set(EXTERNAL_LIB_EXP libraries/mclab-data-model/utils/exceptions)

target_include_directories(
    MBSN PRIVATE

    ${EXTERNAL_LIB_HEADERS}
    ${EXTERNAL_LIB_HEAD_STATE}
    ${EXTERNAL_LIB_HEAD_MOD}
    ${EXTERNAL_LIB_INCLUDE}
    ${EXTERNAL_LIB_EXP}
    ./libraries/vcpkg/installed/x86-windows/include
)

target_link_libraries(MBSN PRIVATE libsbml.lib)
target_link_libraries(MBSN PRIVATE jsoncpp.lib)