cmake_minimum_required(VERSION 3.17)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(AdventOfCode2022
        main.cpp
        Solutions/Day1.cpp
        Solutions/Day1.h
        Solutions/Day2.cpp
        Solutions/Day2.h Solutions/Day3.cpp Solutions/Day3.h)