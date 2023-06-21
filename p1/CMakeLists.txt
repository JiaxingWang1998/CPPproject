cmake_minimum_required(VERSION 3.25)
project(p1)

set(CMAKE_CXX_STANDARD 17)

add_executable(p1 main.cpp string_test.cpp string_test.h vector_test.cpp vector_test.h deque_test.cpp)
