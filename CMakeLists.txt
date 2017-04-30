cmake_minimum_required(VERSION 2.8)
project(astar)
set(CMAKE_C_COMPILER "g++")
set(CMAKE_C_FLAGS "-Wall -Wextra -std=c++17 -Werror -g -pedantic")
set(CMAKE_C_FLAGS_RELEASE "-O2")

set(SRC
    src/main.cc
    src/class/astar.cc
    src/class/node.cc
)

add_executable(astar ${SRC})
