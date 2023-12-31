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
set(MEMORY_LIB include/memory.h src/memory.cc)
add_library(memory SHARED ${MEMORY_LIB})
target_link_libraries(memory tools)


#list
set(LIST_LIB "include/list.h" "src/list.cc")
add_library(list SHARED ${LIST_LIB})
target_include_directories(list PUBLIC "include")
target_link_libraries(list memory exception tools)

#set
set(SET_LIB "include/set.h" "src/set.cc")
add_library(set SHARED ${SET_LIB})
target_include_directories(set PUBLIC "include")
target_link_libraries(set memory list)


#sorts
set(SORTS_LIB "include/sorts.hh" "src/sorts.cc")
add_library(sorts SHARED ${SORTS_LIB})
target_link_libraries(sorts exception)

#main
# add_executable(main main.cpp)
# target_include_directories(main PUBLIC "include")
# target_link_libraries(main list sorts)


#tests
option(GTEST_STL "Create target string_tests for testing" OFF)



if(GTEST_STL)
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

#set
    add_executable(gtest_set test/gtest_set.cpp)
    target_include_directories(gtest_set PUBLIC "modules/googletest/googlemock/include" "modules/googletest/googletest/include")
    target_link_libraries(gtest_set ${TEST_INCLUDE} set)

endif()

