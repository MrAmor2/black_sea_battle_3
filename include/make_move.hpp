#include <vector>

#pragma once

bool make_move(std::vector <std::vector <std::pair <int, int>>> &list_of_ships, int &unbroken_decks_count, \
    int &number_of_moving_player, char ** opponent_board, char ** attack_board, int ** ships_number_by_coordinates, char ** board);