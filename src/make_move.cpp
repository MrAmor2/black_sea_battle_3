#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "..\include\draw_boards.hpp"
#include "..\include\mini_functions.hpp"

bool make_move(std::vector <std::vector <std::pair <int, int>>> &list_of_ships, int &unbroken_decks_count, \
    int &number_of_moving_player, char ** opponent_board, char ** attack_board, int ** ships_number_by_coordinates, char ** board_player_move) {
    
    std::string empty_line = "                                                                                                     ";
    std::string coordinates = "";
    int coord_x, coord_y; // на доске

    int x = 32, y = 5; // в консоли

    std::cout << "Хочешь увидеть свою доску? [✔ / ✖]";

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
                if (x == 32) {
                    x -= 4;
                }
            } else if (button_code == 77) {
                if (x == 28) {
                    x += 4;
                }
            }

            move_cursor(x, 5);

        } else {
            
            if (button_code == 13) {

                if (x == 32) {
                    answer = 'n';
                } else if (x == 28) {
                    answer = 'y';
                }

                break;

            }

        }

    }

    move_cursor(0, 7);

    if (answer == 'y') {
        draw_boards(attack_board, board_player_move, true, true);
    } else {
        draw_boards(attack_board, board_player_move, false, true);
    }

    std::cout << "Твой ход: ";

    while (true) {

        coordinates = "";

        x = 5, y = 11;

        move_cursor(x, y);

        while (true) {

            button_code = _getch();

            if (button_code == 0 || button_code == 224) {

                button_code = _getch();
                
                if (button_code == 72) {
                    if (y > 11) {
                        y -= 1;
                    }
                } else if (button_code == 80) {
                    if (y < 20) {
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

                    coordinates += (char) ('A' + (x - 5) / 2);

                    if (y - 6 == 14) {
                        coordinates += "10";
                    } else {
                        coordinates += (char) ('1' + (y - 11));
                    }

                    move_cursor(x, y);
                    std::cout << "💥";
                    move_cursor(x, y);

                    old_square = {x, y};
                    old_square_icon = attack_board[y - 11][(x - 5) / 2];

                    break;

                }

            }

        }

        move_cursor(10, 23);

        std::cout << coordinates;

        Sleep(2000);

        if (coordinates.size() == 3) {

            coord_y = 9;
            coord_x = (int) coordinates[0] - 'A';

        } else if (coordinates.size() == 2) {

            coord_y = coordinates[1] - '1';
            coord_x = (int) coordinates[0] - 'A';

        }

        if (attack_board[coord_y][coord_x] == ' ') {

            break;
            
        } else {

            move_cursor(old_square.first, old_square.second);
            print_unicode(old_square_icon);

            move_cursor(10, 23);
            std::cout << empty_line;

            move_cursor(10, 23);
            std::cout << "Здесь не может быть корабля, или эта клетка уже атакована!";
            Sleep(2000);

            move_cursor(10, 23);
            std::cout << empty_line;

        }

    }



    move_cursor(0, 25);

    if (opponent_board[coord_y][coord_x] == ' ') {

        std::cout << "Мимо!\n\n";

        opponent_board[coord_y][coord_x] = '.';
        attack_board[coord_y][coord_x] = '.';
        number_of_moving_player = 3 - number_of_moving_player;

    } else if (opponent_board[coord_y][coord_x] == '#') {

        opponent_board[coord_y][coord_x] = 'x';
        attack_board[coord_y][coord_x] = 'x';
        unbroken_decks_count -= 1;

        int number_of_ship = ships_number_by_coordinates[coord_y][coord_x];
        int count_this_ship_destroyed_decks = 0;

        for (int deck_index = 0; deck_index < list_of_ships[number_of_ship].size(); ++deck_index) {

            std::pair <int, int> deck = list_of_ships[number_of_ship][deck_index];

            if (opponent_board[deck.first][deck.second] == 'x') {
                count_this_ship_destroyed_decks += 1;
            }

        }

        if (count_this_ship_destroyed_decks == list_of_ships[number_of_ship].size()) {

            std::cout << "Потопил(-а)!\n\n";

            for (int deck_index = 0; deck_index < list_of_ships[number_of_ship].size(); ++deck_index) {

                std::pair <int, int> deck = list_of_ships[number_of_ship][deck_index];
                std::vector <int> coordinate_difference = {1, 0, -1};

                for (int diff_y = 0; diff_y < 3; ++diff_y) {
                    for (int diff_x = 0; diff_x < 3; ++diff_x) {

                        if (deck.first + coordinate_difference[diff_y] >= 0 && deck.first + coordinate_difference[diff_y] <= 9 \
                            && deck.second + coordinate_difference[diff_x] >= 0 && deck.second + coordinate_difference[diff_x] <= 9) {

                            if (opponent_board[deck.first + coordinate_difference[diff_y]][deck.second \
                                + coordinate_difference[diff_x]] != 'x') {

                                opponent_board[deck.first + coordinate_difference[diff_y]][deck.second + \
                                coordinate_difference[diff_x]] = '.';

                                attack_board[deck.first + coordinate_difference[diff_y]][deck.second + \
                                coordinate_difference[diff_x]] = '.';

                            }
                        }

                    }
                }
            }

        } else {

            std::cout << "Ранил(-а)!\n\n";

        }

    }

    move_cursor(0, 7);

    draw_boards(attack_board, board_player_move, false, true);

    move_cursor(0, 27);

    if (unbroken_decks_count != 0) {

        std::cout << "Нажми enter, чтобы продолжить, или Q, чтобы сдаться\n\n";

        while (true) {

            button_code = _getch();

            if (button_code == 13) {
                return false;
            } else if (button_code == 81 || button_code == 113) {
                return true;
            }

        }

    } else {

        std::cout << "Нажми enter, чтобы продолжить\n\n";

        while (true) {

            button_code = _getch();

            if (button_code == 13) {
                return false;
            }

        }

    }
        
}