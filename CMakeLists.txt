cmake_minimum_required(VERSION 3.21)
project(WORDLEGAME)

set(CMAKE_CXX_STANDARD 14)

add_executable(Game
            Board.cpp Board.h
            Checker.cpp Checker.h
            Main.cpp
            Interface.cpp Interface.h
            DefaultIncludes.h)