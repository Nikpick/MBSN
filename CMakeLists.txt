cmake_minimum_required(VERSION 3.14)
project(MBSN)

set(CMAKE_CXX_STANDARD 17)

include_directories(cpp)
include_directories(libraries)

set(SOURCE_FILES ${SOURCE_FILES} cpp/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/opt/local/include/jsoncpp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/opt/local/lib/jsoncpp")

add_executable(MBSN ${SOURCE_FILES})

add_library(jsoncpp)

target_link_libraries(MBSN /opt/local/lib/jsoncpp/json.h)
target_link_libraries(MBSN /opt/local/include/jsoncpp/json.h)
target_link_libraries(MBSN ${jsoncpp_LDFLAGS})
target_link_libraries(MBSN cpp/main)