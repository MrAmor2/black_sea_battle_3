#include <vector>

#pragma once

extern std::vector <std::vector <std::pair <int, int>>> default_vector;

void make_board(char ** board, std::pair <int, int> * coordinates_array, int coordinates_count, \
    std::vector <std::vector <std::pair <int, int>>> &list_of_ships = default_vector, \
        int ** ships_number_by_coordinates = nullptr);