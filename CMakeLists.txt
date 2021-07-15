cmake_minimum_required(VERSION 3.16.3)
project(dsa-project)

set(CMAKE_CXX_STANDARD 11)

include_directories(includes)

add_executable(dsa-project 
               src/main.cpp)
