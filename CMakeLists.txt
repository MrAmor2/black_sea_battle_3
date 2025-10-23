cmake_minimum_required(VERSION 3.10)
project(Black_Sea_Battle_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(sea_battle
    mini_functions.cpp
    include/mini_functions.hpp
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
    print_rules.cpp
    include/print_rules.hpp
)