cmake_minimum_required(VERSION 3.27.1)

project(STL CXX)

add_library(string SHARED "include/string.hpp" "src/string.cc")
target_include_directories(string PUBLIC "include")

#tests
option(TESTSING "Create target string_tests for testing" ON)
set(TESTSING ON)

#result
if(${TESTSING})
    add_subdirectory(tests)
    set(G_TARGETS gmock_main gmock gtest gtest_main)
    add_executable(string_tests tests/string_tests.cpp)
    target_include_directories(string_tests PUBLIC "tests/googletest/googlemock/include" "tests/googletest/googletest/include" "include")
    target_link_libraries(string_tests ${G_TARGETS} string)
endif()
