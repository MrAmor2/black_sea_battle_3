#include <vector>
#include <string>
#include <iostream>
#include <windows.h>

#include "include\draw_boards.hpp"

void make_move(std::vector <std::vector <std::pair <int, int>>> &list_of_ships, int &decks_count, \
    int &move, char ** opponent_board, char ** attack_board, int ** ships_number_by_coordinates, char ** board) {

        std::string upper_letters = "QWERTYUIOPASDFGHJKLZXCVBNM";
        std::string lower_letters = "qwertyuiopasdfghjklzxcvbnm";
        std::string digits = "0123456789";

        std::string coordinates;
        int y, x;

        std::cout << "Do you want to see your board? [y/n]\n\n";

        char answer;

        std::cin >> answer;
        std::cout << '\n';

        Sleep(2000);

        system("cls");

        if (answer == 'y') {
            draw_boards(attack_board, board, true, true);
        } else {
            draw_boards(attack_board, board, false, true);
        }

        std::cout << "Enter the coordinates you want to strike in the format \"letternumber\"\n\n";

        while (true) {

            std::cin >> coordinates;

            std::cout << '\n';

            if (coordinates.size() == 3) {



                if (coordinates[1] != '1' || coordinates[2] != '0') {
                    std::cout << "This point is off the board, or these are incorrect coordinates!\n\n";
                    continue;
                }

                y = 9;

                if (upper_letters.find(coordinates[0]) != std::string::npos) {
                    x = (int) coordinates[0] - 'A';
                } else if (lower_letters.find(coordinates[0]) != std::string::npos) {
                    x = (int) coordinates[0] - 'a';
                } else {
                    std::cout << "These are incorrect coordinates!\n\n";
                    continue;
                }



            } else if (coordinates.size() == 2) {



                if (digits.find(coordinates[1]) == std::string::npos) {
                    std::cout << "This point is off the board, or these are incorrect coordinates!\n\n";
                    continue;
                }

                y = coordinates[1] - '1';

                if (upper_letters.find(coordinates[0]) != std::string::npos) {
                    x = (int) coordinates[0] - 'A';
                } else if (lower_letters.find(coordinates[0]) != std::string::npos) {
                    x = (int) coordinates[0] - 'a';
                } else {
                    std::cout << "These are incorrect coordinates!\n\n";
                    continue;
                }



            } else {
                std::cout << "This point is off the board, or these are incorrect coordinates!\n\n";
                continue;
            }

            

            if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9)) {
                if (attack_board[y][x] == ' ') {
                    break;
                } else {
                    std::cout << "There can't be a ship here, or it's already been attacked!\n\n";
                }
            } else {
                std::cout << "This point is off the board!\n\n";
            }

        }

        Sleep(2000);

        system("cls");

        if (opponent_board[y][x] == ' ') {

            std::cout << "Your last move: " << coordinates << "\n\n";
            std::cout << "Miss!\n\n";

            opponent_board[y][x] = '.';
            attack_board[y][x] = '.';
            move = 3 - move;

        } else if (opponent_board[y][x] == '#') {

            opponent_board[y][x] = 'x';
            attack_board[y][x] = 'x';
            decks_count -= 1;

            int num_of_ship = ships_number_by_coordinates[y][x];
            int count_destroyed_decks;

            for (int i = 0; i < list_of_ships[num_of_ship].size(); ++i) {

                std::pair <int, int> deck = list_of_ships[num_of_ship][i];

                if (opponent_board[deck.first][deck.second] == 'x') {
                    count_destroyed_decks += 1;
                }

            }

            if (count_destroyed_decks == list_of_ships[num_of_ship].size()) {

                std::cout << "Your last move: " << coordinates << "\n\n";
                std::cout << "Sunk!\n\n";

                for (int i = 0; i < list_of_ships[num_of_ship].size(); ++i) {

                    std::pair <int, int> deck = list_of_ships[num_of_ship][i];
                    std::vector <int> coordinate_diff = {1, 0, -1};

                    for (int y = 0; y < 3; ++y) {
                        for (int x = 0; x < 3; ++x) {

                            if (deck.first + coordinate_diff[y] >= 0 && deck.first + coordinate_diff[y] <= 9 \
                                && deck.second + coordinate_diff[x] >= 0 && deck.second + coordinate_diff[x] <= 9) {

                                if (opponent_board[deck.first + coordinate_diff[y]][deck.second + coordinate_diff[x]] != 'x') {

                                    opponent_board[deck.first + coordinate_diff[y]][deck.second + coordinate_diff[x]] = '.';
                                    attack_board[deck.first + coordinate_diff[y]][deck.second + coordinate_diff[x]] = '.';

                                }
                            }

                        }
                    }
                }

            } else {
                std::cout << "Your last move: " << coordinates << "\n\n";
                std::cout << "Hit!\n\n";

            }

        }

        draw_boards(attack_board, board, false, true);

        std::cout << "Press enter to continue\n\n";

        std::cin.ignore();
        std::cin.ignore();

        system("cls");
        
}