cmake_minimum_required(VERSION 3.10)
project(Black_Sea_Battle_3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sea_battle
    check_board.cpp
    include/check_board.hpp
    draw_boards.cpp
    include/draw_boards.hpp
    fill_list_of_ships.cpp
    include/fill_list_of_ships.hpp
    get_coordinates.cpp
    include/get_coordinates.hpp
    sea_battle.cpp
    make_board.cpp
    include/make_board.hpp
    make_move.cpp
    include/make_move.hpp
)