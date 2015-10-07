cmake_minimum_required(VERSION 3.3)
project(Online_Challenges)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Divisiility_problem.cpp)
add_executable(Online_Challenges ${SOURCE_FILES})