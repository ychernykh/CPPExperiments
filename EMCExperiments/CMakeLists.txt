cmake_minimum_required(VERSION 2.8)

project(EMCExperiments)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -O0 -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

add_executable(TemplateFunctionTypeDeduction TemplateFunctionTypeDeduction.cpp)
add_executable(ArraySizeDeduction ArraySizeDeduction.cpp)

