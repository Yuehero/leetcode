cmake_minimum_required(VERSION 3.17)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(leetcode main.cpp
                solution/src/backtracking.cpp solution/util/commom.h solution/src/dp.cpp solution/inc/dp.h solution/src/arrays.cpp solution/inc/arrays.h solution/util/commom.cpp solution/inc/list.h solution/src/list.cpp solution/src/queue_stack.cpp solution/inc/queue_stack.h solution/src/tree.cpp solution/inc/tree.h solution/src/sort.cpp solution/inc/sort.h)