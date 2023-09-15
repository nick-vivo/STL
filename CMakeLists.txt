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
add_library(memory include/memory.h src/memory.cc)
target_link_libraries(memory)


#tests
option(TEST "Create target string_tests for testing" OFF)



if(TEST)
    add_subdirectory(modules/googletest)
    set(TEST_INCLUDE gmock_main gmock gtest gtest_main)

#string
    add_executable(gtest_string test/gtest_string.cpp)
    target_include_directories(gtest_string PUBLIC "modules/googletest/googlemock/include" "modules/googletest/googletest/include")
    target_link_libraries(gtest_string ${TEST_INCLUDE} string)

#vector
    add_executable(gtest_vector test/gtest_vector.cpp)
    target_include_directories(gtest_vector PUBLIC "modules/googletest/googlemock/include" "modules/googletest/googletest/include")
    target_link_libraries(gtest_vector ${TEST_INCLUDE} vector)
#memory
    add_executable(gtest_memory test/gtest_memory.cpp)
    target_include_directories(gtest_memory PUBLIC "modules/googletest/googlemock/include" "modules/googletest/googletest/include")
    target_link_libraries(gtest_memory ${TEST_INCLUDE} memory)
endif()

