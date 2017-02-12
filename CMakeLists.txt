cmake_minimum_required(VERSION 3.6)
project(Sudok)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Sudoku.cpp Sudoku.h)
add_executable(Sudok ${SOURCE_FILES})