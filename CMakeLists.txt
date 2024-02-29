cmake_minimum_required(VERSION 3.24)
project(alltree)

set(CMAKE_CXX_STANDARD 17)

add_executable(alltree main.cpp priority_queue/priority_queue.hpp "Red-Black Tree/RedBlackTree.hpp")
