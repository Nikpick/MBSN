cmake_minimum_required(VERSION 3.0.0)
project(MBSN VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(MBSN main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(EXTERNAL_LIB_HEADERS libraries/mclab-data-model/headers)
set(EXTERNAL_LIB_JSONCPP libraries/jsoncpp)
set(EXTERNAL_LIB_CPP cpp)
set(EXTERNAL_LIB_RAPIDXML libraries/rapidxml-1.13)


target_include_directories(
    MBSN PRIVATE

    ${EXTERNAL_LIB_HEADERS}
    ${EXTERNAL_LIB_JSONCPP}
    ${EXTERNAL_LIB_CPP}
    ${EXTERNAL_LIB_RAPIDXML}
)
