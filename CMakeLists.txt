cmake_minimum_required(VERSION 3.21)
project(Water_Sort_Puzzle_again)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(Water_Sort_Puzzle_again main.cpp Tube.cpp Tube.h Game.cpp Game.h Timer.cpp Timer.h)
