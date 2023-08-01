cmake_minimum_required(VERSION 3.27.1)

project(STL CXX)

add_library(string SHARED "include/string.hpp" "src/string.cc")
target_include_directories(string PUBLIC "include")

add_executable(main main.cpp)
target_link_libraries(main string)