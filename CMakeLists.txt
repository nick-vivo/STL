cmake_minimum_required(VERSION 3.27.1)

project(STL CXX)

#tools
set(TOOLS_LIB "include/tools.h" "src/tools.cc")
add_library(tools SHARED ${TOOLS_LIB})
target_include_directories(tools PUBLIC "include")

#string
set(STRING_LIB "include/string.hpp" "src/string.cc")
add_library(string SHARED ${STRING_LIB})
target_include_directories(string PUBLIC "include")
target_link_libraries(string tools)


#tests
option(TESTSING "Create target string_tests for testing" ON)
set(TESTSING ON)


if(${TESTSING})
    add_subdirectory(tests)
    set(G_TARGETS gmock_main gmock gtest gtest_main)
    add_executable(string_tests tests/string_tests.cpp)
    target_include_directories(string_tests PUBLIC "tests/googletest/googlemock/include" "tests/googletest/googletest/include" "include")
    target_link_libraries(string_tests ${G_TARGETS} string)
endif()

# add_executable(main main.cpp)
# target_include_directories(main PUBLIC "include")
# target_link_libraries(main string)