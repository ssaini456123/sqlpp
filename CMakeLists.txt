cmake_minimum_required(VERSION 3.31)
project(sqlpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(sqlpp main.cpp
        token.cpp
        token.h
)
