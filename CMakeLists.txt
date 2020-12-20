cmake_minimum_required(VERSION 3.17)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(leetcode main.cpp solution/backtracking.cpp solution/commom.h solution/dp.cpp solution/dp.h)