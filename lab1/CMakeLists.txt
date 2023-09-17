cmake_minimum_required(VERSION 3.10)
project(lab1)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task main.cpp lab1.cpp)

enable_testing()
add_executable(tests gtest.cpp  lab1.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests01)
