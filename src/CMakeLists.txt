cmake_minimum_required(VERSION 3.21)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp split.cpp)
