cmake_minimum_required(VERSION 2.8)
project(GameOfLife)

include(FindOpenMP)

include_directories(src)
include_directories(test)

add_subdirectory(src)
add_subdirectory(test)
