#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

#include "include\draw_boards.hpp"
#include "include\make_board.hpp"
#include "include\mini_functions.hpp"

int abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

void get_coordinates(std::pair <int, int> (&coordinates_array)[]) {

    std::string input_coordinates_1 = "", input_coordinates_2 = "";
    int x_decks_ships_count[4] {};

    char ** home_board = new char* [10];
    for (size_t i = 0; i < 10; ++i) {
        home_board[i] = new char [10];
    }

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            home_board[i][j] = ' ';
        }
    }

    move_cursor(0, 3);

    draw_boards(home_board, home_board, true, false);

    for (int i = 0; i < 10; ++i) {
        if (i == 9) {
            std::cout << "Корабль №" << i + 1 << ":\n";
        } else {
            std::cout << "Корабль №0" << i + 1 << ":\n"; 
        }
    }



    int shift = 0;

    for (size_t i = 0; i < 10; ++i) {

        move_cursor(13, i + 19);
        std::cout << "                                                                                                       ";

        input_coordinates_1 = "", input_coordinates_2 = "";

        int x = 5, y = 7;
        move_cursor(x, y);
        bool back = false;

        int enters_count = 0, button_code;
        char old_square_icon_1, old_square_icon_2;
        std::pair <int, int> old_square_1, old_square_2;

        while (true) {

            button_code = _getch();

            if (button_code == 0 || button_code == 224) {

                button_code = _getch();
                
                if (button_code == 72) {
                    if (y > 7) {
                        y -= 1;
                    }
                } else if (button_code == 80) {
                    if (y < 16) {
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

                    enters_count += 1;

                    if (enters_count == 1) {

                        input_coordinates_1 += (char) ('A' + (x - 5) / 2);

                        if (y - 7 == 9) {
                            input_coordinates_1 += "10";
                        } else {
                            input_coordinates_1 += (char) ('1' + (y - 7));
                        }

                        move_cursor(x, y);
                        std::cout << "⚓";
                        move_cursor(x, y);

                        old_square_1 = {x, y};
                        old_square_icon_1 = home_board[y - 7][(x - 5) / 2];

                    } else if (enters_count == 2) {

                        input_coordinates_2 += (char) ('A' + (x - 5) / 2);
                        
                        if (y - 7 == 9) {
                            input_coordinates_2 += "10";
                        } else {
                            input_coordinates_2 += (char) ('1' + (y - 7));
                        }

                        move_cursor(x, y);
                        std::cout << "⚓";
                        move_cursor(x, y);

                        old_square_2 = {x, y};
                        old_square_icon_2 = home_board[y - 7][(x - 5) / 2];

                    }

                } else if (button_code == 90 || button_code == 122 && i >= 1) {

                    back = true;

                    shift -= 2;
                    i -= 2;

                    int len = abs(coordinates_array[shift].first - coordinates_array[shift + 1].first) + \
                    abs(coordinates_array[shift].second - coordinates_array[shift + 1].second) + 1;
                    x_decks_ships_count[len - 1] -= 1;

                    for (int board_i = 0; board_i < 10; ++board_i) {
                        for (int board_j = 0; board_j < 10; ++board_j) {
                            home_board[board_i][board_j] = ' ';
                        }
                    }

                    make_board(home_board, coordinates_array, shift);

                    move_cursor(0, 3);

                    draw_boards(home_board, home_board, true, false);

                    break;

                }

            }

            if (enters_count == 2) {
                break;
            }

        }

        if (back) {
            continue;
        }

        move_cursor(13, i + 19);

        std::cout << input_coordinates_1 << ' ' << input_coordinates_2;

        if (input_coordinates_1.size() == 3) {
            coordinates_array[shift] = {10 - 1, (int) input_coordinates_1[0] - 'A'};
        } else {
            coordinates_array[shift] = {input_coordinates_1[1] - '1', \
                (int) input_coordinates_1[0] - 'A'};
        }

        shift++;

        if (input_coordinates_2.size() == 3) {
            coordinates_array[shift] = {10 - 1, (int) input_coordinates_2[0] - 'A'};
        } else {
            coordinates_array[shift] = {input_coordinates_2[1] - '1', \
                (int) input_coordinates_2[0] - 'A'};
        }

        shift++;



        move_cursor(old_square_1.first, old_square_1.second);
        print_unicode(old_square_icon_1);

        move_cursor(old_square_2.first, old_square_2.second);
        print_unicode(old_square_icon_2);



        // Проверка корректности



        std::pair <int, int> deck_1 = coordinates_array[shift - 2], \
        deck_2 = coordinates_array[shift - 1];

        std::string message = "";

        if (deck_1.first != deck_2.first && deck_1.second != deck_2.second) {
            message = "Корабль может находиться только на одной полосе!";
        } else if (deck_1.first == deck_2.first && abs(deck_1.second - deck_2.second) + 1 >= 5) {
            message = "Длина корабля не может превышать 4!";
        } else if (deck_1.second == deck_2.second && abs(deck_1.first - deck_2.first) + 1 >= 5) {
            message = "Длина корабля не может превышать 4!";
        }

        if (message != "") {

            move_cursor(13, i + 19);
            std::cout << "                                                                                                       ";

            move_cursor(13, i + 19);
            std::cout << message;
            Sleep(2000);

            move_cursor(13, i + 19);
            std::cout << "                                                                                                       ";

            move_cursor(13, i + 19);
            i -= 1;
            shift -= 2;

            continue;

        }



        bool check_bump = true;

        for (int deck_1_index = 1; deck_1_index < shift; ++deck_1_index) {
            for (int deck_2_index = 0; deck_2_index < deck_1_index; ++deck_2_index) {

                if (deck_1_index - deck_2_index != 1 || deck_2_index % 2 != 0) {

                    deck_1 = coordinates_array[deck_1_index], deck_2 = coordinates_array[deck_2_index];

                    if (abs(deck_1.first - deck_2.first) <= 1 && abs(deck_1.second - deck_2.second) <= 1) {

                        move_cursor(13, i + 19);
                        std::cout << "                                                                                           ";

                        move_cursor(13, i + 19);
                        std::cout << "Два корабля сталкиваются!";
                        check_bump = false;
                        Sleep(2000);

                        move_cursor(13, i + 19);
                        std::cout << "                                                                                           ";

                        move_cursor(13, i + 19);
                        i -= 1;
                        shift -= 2;
                        break;

                    }

                }

            }

            if (check_bump == false) {
                break;
            }

        }

        if (check_bump == false) {
            continue;
        }



        deck_1 = coordinates_array[shift - 2], \
        deck_2 = coordinates_array[shift - 1];

        int length_of_ship = 0;

        if (deck_1.first == deck_2.first) {
            length_of_ship = abs(deck_1.second - deck_2.second) + 1;
        } else if (deck_1.second == deck_2.second) {
            length_of_ship = abs(deck_1.first - deck_2.first) + 1;
        }

        if (x_decks_ships_count[length_of_ship - 1] >= 5 - length_of_ship) {

            move_cursor(13, i + 19);
            std::cout << "                                                                                                       ";

            move_cursor(13, i + 19);
            std::cout << "Количество " << length_of_ship << "-палубных кораблей уже " << 5 - length_of_ship << "!";
            Sleep(2000);

            move_cursor(13, i + 19);
            std::cout << "                                                                                                       ";

            move_cursor(13, i + 19);
            i -= 1;
            shift -= 2;

            continue;

        } else {

            x_decks_ships_count[length_of_ship - 1] += 1;

        }



        make_board(home_board, coordinates_array, shift);

        move_cursor(0, 3);

        draw_boards(home_board, home_board, true, false);

    }

    move_cursor(0, 29);

    std::cout << '\n';

    for (size_t i = 0; i < 10; ++i) {
        delete [] home_board[i];
    }

    delete [] home_board;

}