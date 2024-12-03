cmake_minimum_required(VERSION 3.31)

project(winplus)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER "clang++")
file(GLOB SOURCES "src/*.c++" "include/*.hpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES})