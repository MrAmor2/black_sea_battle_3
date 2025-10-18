#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "include\draw_boards.hpp"
#include "include\mini_functions.hpp"

void make_move(std::vector <std::vector <std::pair <int, int>>> &list_of_ships, int &decks_count, \
    int &move, char ** opponent_board, char ** attack_board, int ** ships_number_by_coordinates, char ** board_player_move) {

        std::string coordinates = "";
        int x = 32, y = 5;

        std::cout << "Do you want to see your board? [y / n]";

        move_cursor(32, 5);

        int button_code;
        char answer;

        char old_square_icon;
        std::pair <int, int> old_square;

        while (true) {

            button_code = _getch();

            if (button_code == 0 || button_code == 224) {

                button_code = _getch();
                
                if (button_code == 75) {
                    if (x == 36) {
                        x -= 4;
                    }
                } else if (button_code == 77) {
                    if (x == 32) {
                        x += 4;
                    }
                }

                move_cursor(x, 5);

            } else {
                
                if (button_code == 13) {

                    if (x == 36) {
                        answer = 'n';
                    } else if (x == 32) {
                        answer = 'y';
                    }

                    break;

                }

            }

        }

        Sleep(2000);

        system("cls");

        if (answer == 'y') {
            draw_boards(attack_board, board_player_move, true, true);
        } else {
            draw_boards(attack_board, board_player_move, false, true);
        }

        std::cout << "Your move: ";

        while (true) {

            coordinates = "";

            x = 5, y = 4;

            move_cursor(x, y);

            while (true) {

                button_code = _getch();

                if (button_code == 0 || button_code == 224) {

                    button_code = _getch();
                    
                    if (button_code == 72) {
                        if (y > 4) {
                            y -= 1;
                        }
                    } else if (button_code == 80) {
                        if (y < 13) {
                            y += 1;
                        }
                    } else if (button_code == 75) {
                        if (x >= 7) {
                            x -= 2;
                        }
                    } else if (button_code == 77) {
                        if (x <= 21) {
                            x += 2;
                        }
                    }

                    move_cursor(x, y);

                } else {

                    if (button_code == 13) {

                        coordinates += (char) ('a' + (x - 5) / 2);

                        if (y - 6 == 7) {
                            coordinates += "10";
                        } else {
                            coordinates += (char) ('1' + (y - 4));
                        }

                        move_cursor(x, y);
                        std::cout << "💥";
                        move_cursor(x, y);

                        old_square = {x, y};
                        old_square_icon = attack_board[y - 4][(x - 5) / 2];

                        break;

                    }

                }

            }

            move_cursor(11, 16);

            std::cout << coordinates;

            Sleep(2000);

            if (coordinates.size() == 3) {

                y = 9;
                x = (int) coordinates[0] - 'a';

            } else if (coordinates.size() == 2) {

                y = coordinates[1] - '1';
                x = (int) coordinates[0] - 'a';

            }

            if (attack_board[y][x] == ' ') {

                break;
                
            } else {

                move_cursor(old_square.first, old_square.second);
                print_unicode(old_square_icon);

                move_cursor(11, 16);
                std::cout << "                                                          ";

                move_cursor(11, 16);
                std::cout << "There can't be a ship here, or it's already been attacked!";
                Sleep(2000);

                move_cursor(11, 16);
                std::cout << "                                                          ";

            }

        }



        move_cursor(0, 18);

        if (opponent_board[y][x] == ' ') {

            std::cout << "Miss!\n\n";

            opponent_board[y][x] = '.';
            attack_board[y][x] = '.';
            move = 3 - move;

        } else if (opponent_board[y][x] == '#') {

            opponent_board[y][x] = 'x';
            attack_board[y][x] = 'x';
            decks_count -= 1;

            int num_of_ship = ships_number_by_coordinates[y][x];
            int count_destroyed_decks = 0;

            for (int i = 0; i < list_of_ships[num_of_ship].size(); ++i) {

                std::pair <int, int> deck = list_of_ships[num_of_ship][i];

                if (opponent_board[deck.first][deck.second] == 'x') {
                    count_destroyed_decks += 1;
                }

            }

            if (count_destroyed_decks == list_of_ships[num_of_ship].size()) {

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

                std::cout << "Hit!\n\n";

            }

        }

        move_cursor(0, 0);

        draw_boards(attack_board, board_player_move, false, true);

        move_cursor(0, 20);

        std::cout << "Press enter to continue\n\n";

        // std::cin.ignore();

        while (true) {

            button_code = _getch();

            if (button_code == 13) {
                break;
            }

        }

        system("cls");
        
}