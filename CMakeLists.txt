cmake_minimum_required(VERSION 3.27.1)

project(STL CXX)

include_directories(include)

#tools
set(TOOLS_LIB "include/tools.h" "src/tools.cc")
add_library(tools SHARED ${TOOLS_LIB})
target_include_directories(tools PUBLIC "include")

#string
set(STRING_LIB "include/string.hpp" "src/string.cc")
add_library(string SHARED ${STRING_LIB})
target_include_directories(string PUBLIC "include")
target_link_libraries(string tools)

#exception
set(EXCEPTION_LIB "include/exception.h" "src/exception.cc")
add_library(exception SHARED ${EXCEPTION_LIB})
target_include_directories(exception PUBLIC "include")
target_link_libraries(exception string)

#vector
set(VECTOR_LIB "include/vector.h" "src/vector.cc")
add_library(vector SHARED ${VECTOR_LIB})
target_include_directories(vector PUBLIC "include")
target_link_libraries(vector tools exception)

#memory
set(MEMORY_LIB "include/memory.h" "src/memory.cc")
add_library(memory SHARED ${MEMORY_LIB})
target_include_directories(memory PUBLIC "include")
target_link_libraries(memory tools)

#tests
option(TESTSING "Create target string_tests for testing" ON)
set(TESTSING OFF)


if(${TESTSING})
    add_subdirectory(tests)
    set(G_TARGETS gmock_main gmock gtest gtest_main)

    add_executable(string_tests tests/string_tests.cpp)
    target_include_directories(string_tests PUBLIC "tests/googletest/googlemock/include" "tests/googletest/googletest/include" "include")
    target_link_libraries(string_tests ${G_TARGETS} string)

    add_executable(vector_test tests/vector_test.cpp)
    target_include_directories(vector_test PUBLIC "tests/googletest/googlemock/include" "tests/googletest/googletest/include" "include")
    target_link_libraries(vector_test ${G_TARGETS} vector)
endif()

# add_executable(main main.cpp)
# target_include_directories(main PUBLIC "include")
# target_link_libraries(main memory)
