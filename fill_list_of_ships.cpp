#include <vector>

void fill_list_of_ships(std::vector <std::vector <std::pair <int, int>>> &list_of_ships, \
    std::vector <std::pair <int, int>> coordinates, int ** ships_number_by_coordinates) {

        for (int i = 0; i < 20; i += 2) {

            std::pair <int, int> pair_1 = coordinates[i], pair_2 = coordinates[i + 1];

            if (pair_1.first == pair_2.first) {

                if (pair_1.second < pair_2.second) {

                    for (int j = pair_1.second; j <= pair_2.second; ++j) {
                        list_of_ships[i / 2].push_back({pair_1.first, j});
                        ships_number_by_coordinates[pair_1.first][j] = i / 2;
                    }

                } else {

                    for (int j = pair_2.second; j <= pair_1.second; ++j) {
                        list_of_ships[i / 2].push_back({pair_1.first, j});
                        ships_number_by_coordinates[pair_1.first][j] = i / 2;
                    }

                }

            } else if (pair_1.second == pair_2.second) {

                if (pair_1.first < pair_2.first) {

                    for (int j = pair_1.first; j <= pair_2.first; ++j) {
                        list_of_ships[i / 2].push_back({j, pair_1.second});
                        ships_number_by_coordinates[j][pair_1.second] = i / 2;
                    }

                } else {

                    for (int j = pair_2.first; j <= pair_1.first; ++j) {
                        list_of_ships[i / 2].push_back({j, pair_1.second});
                        ships_number_by_coordinates[j][pair_1.second] = i / 2;
                    }

                }

            }
        }

}