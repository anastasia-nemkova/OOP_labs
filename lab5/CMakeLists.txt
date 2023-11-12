cmake_minimum_required(VERSION 3.10)
project(lab5)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(ALLOCATOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/allocator)
set(LIST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/list)
set(ITERATOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/iterators)

include_directories(${ALLOCATOR_DIR})
include_directories(${LIST_DIR})
include_directories(${ITERATOR_DIR})

add_library(lab5_lib INTERFACE)
target_include_directories(lab5_lib INTERFACE ${ALLOCATOR_DIR} ${LIST_DIR} ${ITERATOR_DIR})


file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false test.cpp)

add_executable(lab5_test ${TEST_SOURCES})
target_link_libraries(lab5_test PRIVATE lab5_lib GTest::GTest GTest::Main)

find_package(Threads REQUIRED) 
target_link_libraries(lab5_test PRIVATE Threads::Threads) 


add_test(NAME lab5_test COMMAND lab5_test)
