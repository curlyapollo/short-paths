cmake_minimum_required(VERSION 3.24)
project(Graphs)

set(CMAKE_CXX_STANDARD 17)

add_executable(Graphs main.cpp algorithms.cpp algorithms.h generation.cpp generation.h measurements.h measurements.cpp tables.cpp tables.h)
