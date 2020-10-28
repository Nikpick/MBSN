cmake_minimum_required(VERSION 3.0.0)
project(MBSN VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(MBSN main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(EXTERNAL_LIB_HEADERS mclab-data-model/headers)
target_include_directories(
    MBSN PRIVATE
    ${EXTERNAL_LIB_HEADERS}
)
