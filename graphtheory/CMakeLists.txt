cmake_minimum_required(VERSION 3.12)
project(graphtheory)

set(CMAKE_CXX_STANDARD 14)

add_executable(graphtheory main.cpp)

add_executable(bellmanford bellmanford.cpp)