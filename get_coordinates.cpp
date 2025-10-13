#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "include\draw_boards.hpp"
#include "include\make_board.hpp"

int abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

void move_cursor(int x, int y) {  
    COORD coord;  
    coord.X = x;  
    coord.Y = y;  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  
}

std::vector <std::pair <int, int>> get_coordinates() {

    std::string upper_letters = "QWERTYUIOPASDFGHJKLZXCVBNM";

    std::string input_coordinates_1, input_coordinates_2;
    std::vector <std::pair <int, int>> coordinates_array(20);
    std::vector <int> x_decks_ships_count(4, 0);

    char ** board = new char* [10];
    for (size_t i = 0; i < 10; ++i) {
        board[i] = new char [10];
    }

    bool flag = false;

    while (flag != true) {

        for (size_t i = 0; i < 10; ++i) {
            for (size_t j = 0; j < 10; ++j) {
                board[i][j] = ' ';
            }
        }

        move_cursor(0, 2);

        draw_boards(board, board, true, false);

        for (int i = 0; i < 10; ++i) {
            int number = i + 1;
            if (i == 9) {
                std::cout << "Ship #" << i + 1 << ":\n";
            } else {
                std::cout << "Ship #0" << i + 1 << ":\n"; 
            }
        }

        int shift = 0;

        for (size_t i = 0; i < 10; ++i) {

            move_cursor(10, i + 18);

            std::cin >> input_coordinates_1 >> input_coordinates_2;
            
            if (upper_letters.find(input_coordinates_1[0]) == std::string::npos) {

                if (input_coordinates_1.size() == 3) {
                    coordinates_array[shift] = {10 - 1, (int) input_coordinates_1[0] - 'a'};
                } else {
                    coordinates_array[shift] = {input_coordinates_1[1] - '1', \
                        (int) input_coordinates_1[0] - 'a'};
                }

            } else {

                if (input_coordinates_1.size() == 3) {
                    coordinates_array[shift] = {10 - 1, (int) input_coordinates_1[0] - 'A'};
                } else {
                    coordinates_array[shift] = {input_coordinates_1[1] - '1', \
                        (int) input_coordinates_1[0] - 'A'};
                }

            }

            shift += 1;

            if (upper_letters.find(input_coordinates_2[0]) == std::string::npos) {

                if (input_coordinates_2.size() == 3) {
                    coordinates_array[shift] = {10 - 1, (int) input_coordinates_2[0] - 'a'};
                } else {
                    coordinates_array[shift] = {input_coordinates_2[1] - '1', \
                        (int) input_coordinates_2[0] - 'a'};
                }

            } else {

                if (input_coordinates_2.size() == 3) {
                    coordinates_array[shift] = {10 - 1, (int) input_coordinates_2[0] - 'A'};
                } else {
                    coordinates_array[shift] = {input_coordinates_2[1] - '1', \
                        (int) input_coordinates_2[0] - 'A'};
                }

            }

            shift += 1;

            // Проверка корректности



            std::pair <int, int> deck_1 = coordinates_array[shift - 2], \
            deck_2 = coordinates_array[shift - 1];

            std::string message = "";

            if (deck_1.first != deck_2.first && deck_1.second != deck_2.second) {
                message = "The ship can only be on one line!";
            } else if (deck_1.first == deck_2.first && abs(deck_1.second - deck_2.second) >= 5) {
                message = "The ship cannot be longer than 4!";
            } else if (deck_1.second == deck_2.second && abs(deck_1.first - deck_2.first) >= 5) {
                message = "The ship cannot be longer than 4!";
            } else if (deck_1.first < 0 || deck_1.first > 9 || deck_2.first < 0 || deck_2.first > 9) {
                message = "The ship must be completely within the 10x10 board!";
            } else if (deck_1.second < 0 || deck_1.second > 9 || deck_2.second < 0 || deck_2.second > 9) {
                message = "The ship must be completely within the 10x10 board!";
            }

            if (message != "") {

                move_cursor(10, i + 18);
                std::cout << "                                                                                                       ";

                move_cursor(10, i + 18);
                std::cout << message;
                Sleep(2000);

                move_cursor(10, i + 18);
                std::cout << "                                                                                                       ";

                move_cursor(10, i + 18);
                i -= 1;
                shift -= 2;

                continue;

            }



            bool check_bump = true;

            for (int deck_1_index = 1; deck_1_index < (i + 1) * 2; ++deck_1_index) {
                for (int deck_2_index = 0; deck_2_index < deck_1_index; ++deck_2_index) {

                    if (deck_1_index - deck_2_index != 1 || deck_2_index % 2 != 0) {

                        deck_1 = coordinates_array[deck_1_index], deck_2 = coordinates_array[deck_2_index];

                        if (abs(deck_1.first - deck_2.first) <= 1 && abs(deck_1.second - deck_2.second) <= 1) {

                            move_cursor(10, i + 18);
                            std::cout << "                                                                                           ";

                            move_cursor(10, i + 18);
                            std::cout << "Two ships bump!";
                            check_bump = false;
                            Sleep(2000);

                            move_cursor(10, i + 18);
                            std::cout << "                                                                                           ";

                            move_cursor(10, i + 18);
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



            int length_of_ship = 0;

            if (deck_1.first == deck_2.first) {
                length_of_ship = abs(deck_1.second - deck_2.second) + 1;
            } else if (deck_1.second == deck_2.second) {
                length_of_ship = abs(deck_1.first - deck_2.first) + 1;
            }

            if (x_decks_ships_count[length_of_ship - 1] == 5 - length_of_ship) {

                move_cursor(10, i + 18);
                std::cout << "                                                                                                       ";

                move_cursor(10, i + 18);
                std::cout << "The count of " << length_of_ship << "-deck ships is already " << 5 - length_of_ship << "!";
                Sleep(2000);

                move_cursor(10, i + 18);
                std::cout << "                                                                                                       ";

                move_cursor(10, i + 18);
                i -= 1;
                shift -= 2;

                continue;

            } else {

                x_decks_ships_count[length_of_ship - 1] += 1;

            }



            make_board(board, coordinates_array, shift);

            move_cursor(0, 2);

            draw_boards(board, board, true, false);

        }

        std::cout << '\n';

        std::cout << "Correctly\n\n";
        flag = true;

    }

    for (size_t i = 0; i < 10; ++i) {
        delete [] board[i];
    }

    delete [] board;

    return coordinates_array;
}