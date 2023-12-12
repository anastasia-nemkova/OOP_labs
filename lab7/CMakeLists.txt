cmake_minimum_required(VERSION 3.10)
project(lab7)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED) 

set(SOURCES
    src/npc.cpp
    src/errant_knight.cpp
    src/slaver.cpp
    src/squirrel.cpp
    main.cpp
)

set(HEADERS
    include/observer.hpp
    include/npc.hpp
    include/errant_knight.hpp
    include/slaver.hpp
    include/squirrel.hpp
)

add_library(lab7_lib STATIC ${SOURCES} ${HEADERS})
target_include_directories(lab7_lib PUBLIC include)
target_link_libraries(lab7_lib PRIVATE Threads::Threads)

add_executable(lab7_main main.cpp)
target_link_libraries(lab7_main PRIVATE lab7_lib)

set(TEST_SOURCES
    test/lab7_test.cpp
)

add_executable(lab7_test ${TEST_SOURCES})
target_include_directories(lab7_test PRIVATE include)
target_link_libraries(lab7_test PRIVATE lab7_lib GTest::GTest GTest::Main)
add_test(NAME lab7_test COMMAND lab7_test)
