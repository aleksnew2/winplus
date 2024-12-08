cmake_minimum_required(VERSION 3.31)

project(winplus)

set(CMAKE_CXX_COMPILER "clang++")
file(GLOB SOURCES "src/*.c++" "include/*.hpp")
set(CMAKE_CXX_FLAGS "-std=c++26")

add_library(${PROJECT_NAME} SHARED ${SOURCES})