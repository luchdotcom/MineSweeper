cmake_minimum_required(VERSION 3.15)
project(MS_21_04)

set(CMAKE_CXX_STANDARD 14)

add_executable(MS_21_04 main.cpp Player.cpp Player.h Enemy.cpp Enemy.h DeadlyEnemy.cpp DeadlyEnemy.h SuperDeadlyEnemy.cpp SuperDeadlyEnemy.h Board.cpp Board.h Game.cpp Game.h PowerError.cpp PowerError.h)