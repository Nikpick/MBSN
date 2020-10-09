cmake_minimum_required(VERSION 3.14)
project(MBSN)

set(CMAKE_CXX_STANDARD 17)

add_executable(MBSN main.cpp)

target_include_directories(MBSN PUBLIC "${PROJECT_BINARY_DIR}")
