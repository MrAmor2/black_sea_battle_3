#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "include\draw_boards.hpp"
#include "include\mini_functions.hpp"

void make_move(std::vector <std::vector <std::pair <int, int>>> &list_of_ships, int &decks_count, \
    int &number_of_moving_player, char ** opponent_board, char ** attack_board, int ** ships_number_by_coordinates, char ** board_player_move) {

        std::string coordinates = "";
        int x = 28, y = 5;

        std::cout << "Хочешь увидеть свою доску? [✔ / ✖]";

        move_cursor(28, 5);

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

                y = 9;
                x = (int) coordinates[0] - 'A';

            } else if (coordinates.size() == 2) {

                y = coordinates[1] - '1';
                x = (int) coordinates[0] - 'A';

            }

            if (attack_board[y][x] == ' ') {

                break;
                
            } else {

                move_cursor(old_square.first, old_square.second);
                print_unicode(old_square_icon);

                move_cursor(10, 23);
                std::cout << "                                                          ";

                move_cursor(10, 23);
                std::cout << "Здесь не может быть корабля, или эта клетка уже атакована!";
                Sleep(2000);

                move_cursor(10, 23);
                std::cout << "                                                          ";

            }

        }



        move_cursor(0, 25);

        if (opponent_board[y][x] == ' ') {

            std::cout << "Мимо!\n\n";

            opponent_board[y][x] = '.';
            attack_board[y][x] = '.';
            number_of_moving_player = 3 - number_of_moving_player;

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

                std::cout << "Потопил(-а)!\n\n";

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

                std::cout << "Ранил(-а)!\n\n";

            }

        }

        move_cursor(0, 7);

        draw_boards(attack_board, board_player_move, false, true);

        move_cursor(0, 27);

        std::cout << "Нажми enter, чтобы продолжить\n\n";

        while (true) {

            button_code = _getch();

            if (button_code == 13) {
                break;
            }

        }

        system("cls");
        
}