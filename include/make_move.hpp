#include <vector>

#pragma once

void make_move(std::vector <std::vector <std::pair <int, int>>> &list_of_ships, int &decks_count, \
    int &move, char ** opponent_board, char ** attack_board, int ** ships_number_by_coordinates, char ** board);