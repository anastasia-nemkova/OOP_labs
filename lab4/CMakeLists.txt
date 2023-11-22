cmake_minimum_required(VERSION 3.10)
project(lab4)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${INCLUDE_DIR})

add_library(lab4_lib INTERFACE)
target_include_directories(lab4_lib INTERFACE ${INCLUDE_DIR})


file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false test.cpp)

add_executable(lab4_test ${TEST_SOURCES})
target_link_libraries(lab4_test PRIVATE lab4_lib GTest::GTest GTest::Main)

find_package(Threads REQUIRED) 
target_link_libraries(lab4_test PRIVATE Threads::Threads) 


add_test(NAME lab4_test COMMAND lab4_test)
