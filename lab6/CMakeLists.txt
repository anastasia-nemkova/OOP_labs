cmake_minimum_required(VERSION 3.10)
project(lab6)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/npc.cpp
    src/factory.cpp
    src/errant_knight.cpp
    src/slaver.cpp
    src/squirrel.cpp
    src/observer.cpp
    src/visitors.cpp
    main.cpp
)

set(HEADERS
    include/npc.hpp
    include/factory.hpp
    include/errant_knight.hpp
    include/slaver.hpp
    include/squirrel.hpp
    include/observer.hpp
    include/visitors.hpp
)

add_library(lab6_lib STATIC ${SOURCES} ${HEADERS})
target_include_directories(lab6_lib PUBLIC include)

add_executable(lab6_main main.cpp)
target_link_libraries(lab6_main PRIVATE lab6_lib)

set(TEST_SOURCES
    test/lab6_test.cpp
)

add_executable(lab6_test ${TEST_SOURCES})
target_include_directories(lab6_test PRIVATE include)
target_link_libraries(lab6_test PRIVATE lab6_lib GTest::GTest GTest::Main)
add_test(NAME lab6_test COMMAND lab6_test)
