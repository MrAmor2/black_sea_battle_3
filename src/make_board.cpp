#include <iostream>
#include <vector>

void my_swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

std::vector <std::vector <std::pair <int, int>>> default_vector = {};

void make_board(char ** board, std::pair <int, int> * coordinates_array, int coordinates_count, \
    std::vector <std::vector <std::pair <int, int>>> &list_of_ships = default_vector, \
        int ** ships_number_by_coordinates = nullptr) {

    for (int extreme_deck_index = 0; extreme_deck_index < coordinates_count; extreme_deck_index += 2) {

        std::pair <int, int> extreme_deck_1 = coordinates_array[extreme_deck_index], \
        extreme_deck_2 = coordinates_array[extreme_deck_index + 1];

        int deck_1_coord_x = extreme_deck_1.second, deck_1_coord_y = extreme_deck_1.first, \
        deck_2_coord_x = extreme_deck_2.second, deck_2_coord_y = extreme_deck_2.first;

        if (deck_1_coord_y == deck_2_coord_y) {

            if (deck_1_coord_x > deck_2_coord_x) {
                my_swap(deck_1_coord_x, deck_2_coord_x);
            }

            for (int deck_coord_x = deck_1_coord_x; deck_coord_x <= deck_2_coord_x; ++deck_coord_x) {

                board[deck_1_coord_y][deck_coord_x] = '#';

                if (list_of_ships.size() != 0) {
                    list_of_ships[extreme_deck_index / 2].push_back({deck_1_coord_y, deck_coord_x});
                    ships_number_by_coordinates[deck_1_coord_y][deck_coord_x] = extreme_deck_index / 2;
                }

            }

        } else if (deck_1_coord_x == deck_2_coord_x) {

            if (deck_1_coord_y > deck_2_coord_y) {
                my_swap(deck_1_coord_y, deck_2_coord_y);
            }

            for (int deck_coord_y = deck_1_coord_y; deck_coord_y <= deck_2_coord_y; ++deck_coord_y) {

                board[deck_coord_y][deck_1_coord_x] = '#';
                
                if (list_of_ships.size() != 0) {
                    list_of_ships[extreme_deck_index / 2].push_back({deck_coord_y, deck_1_coord_x});
                    ships_number_by_coordinates[deck_coord_y][deck_1_coord_x] = extreme_deck_index / 2;
                }

            }

        }

    }

}