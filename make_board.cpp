#include <vector>
#include <iostream>

void make_board(char ** board, std::vector <std::pair <int, int>> coordinates) {
    for (int i = 0; i < 20; i += 2) {
        std::pair <int, int> pair_1 = coordinates[i], pair_2 = coordinates[i + 1];

        if (pair_1.first == pair_2.first) {

            if (pair_1.second < pair_2.second) {
                for (int j = pair_1.second; j <= pair_2.second; ++j) {
                    board[pair_1.first][j] = '#';
                }
            } else {
                for (int j = pair_2.second; j <= pair_1.second; ++j) {
                    board[pair_1.first][j] = '#';
                }
            }

        } else if (pair_1.second == pair_2.second) {

            if (pair_1.first < pair_2.first) {
                for (int j = pair_1.first; j <= pair_2.first; ++j) {
                    board[j][pair_1.second] = '#';
                }
            } else {
                for (int j = pair_2.first; j <= pair_1.first; ++j) {
                    board[j][pair_1.second] = '#';
                }
            }
        }
    }
}