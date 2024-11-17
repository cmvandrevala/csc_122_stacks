cmake_minimum_required(VERSION 3.15)

project("Stack Examples")

set (CMAKE_CXX_STANDARD 14)

add_library(my_stack my_stack.cpp)
add_executable(1_reverse_a_string 1_reverse_a_string.cpp)
