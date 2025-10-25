#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <utility>
#include <time.h>

#include "..\include\get_coordinates.hpp"
#include "..\include\make_board.hpp"
#include "..\include\draw_boards.hpp"
#include "..\include\make_move.hpp"
#include "..\include\mini_functions.hpp"
#include "..\include\print_rules.hpp"

#define scan_enter(); \
    while (true) { \
        button_code = _getch(); \
        if (button_code == 13) { \
            system("cls"); \
            break; \
        } \
    }

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int button_code;

    system("cls");

    std::cout << "Добро пожаловать в Морской бой на Черном море!\n\n";

    std::string player_1_name, player_2_name;



    std::cout << "Игрок №1, введи свое имя на английском языке:";
    move_cursor(46, 2);
    getline(std::cin, player_1_name);
    
    move_cursor(70, 2);
    if (player_1_name.size() > 24) {
        for (int cut_char_number = 0; cut_char_number < player_1_name.size() - 24; ++cut_char_number) {
            std::cout << ' ';
        }
    }
    player_1_name = player_1_name.substr(0, 24);



    move_cursor(0, 4);

    std::cout << "Игрок №2, введи свое имя на английском языке:";
    move_cursor(46, 4);
    getline(std::cin, player_2_name);

    move_cursor(70, 4);
    if (player_2_name.size() > 24) {
        for (int cut_char_number = 0; cut_char_number < player_2_name.size() - 24; ++cut_char_number) {
            std::cout << ' ';
        }
    }
    player_2_name = player_2_name.substr(0, 24);



    move_cursor(0, 6);
    print_rules();
    std::cout << "Нажмите enter для перехода к расстановке кораблей\n\n";
    scan_enter();



    std::pair <int, int>* coordinates_array_1 = new std::pair <int, int> [20];
    std::pair <int, int>* coordinates_array_2 = new std::pair <int, int> [20];

    std::vector <std::vector <std::pair <int, int>>> list_of_ships_1(10);
    std::vector <std::vector <std::pair <int, int>>> list_of_ships_2(10);

    int ** ships_number_by_coordinates_1 = new int* [10];
    int ** ships_number_by_coordinates_2 = new int* [10];

    for (size_t i = 0; i < 10; ++i) {
        ships_number_by_coordinates_1[i] = new int [10];
        ships_number_by_coordinates_2[i] = new int [10];
    }

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            ships_number_by_coordinates_1[i][j] = -1;
            ships_number_by_coordinates_2[i][j] = -1;
        }
    }

    char ** board_player_1 = new char* [10];
    char ** board_player_2 = new char* [10];

    for (size_t i = 0; i < 10; ++i) {
        board_player_1[i] = new char [10];
        board_player_2[i] = new char [10];
    }

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            board_player_1[i][j] = ' ';
            board_player_2[i][j] = ' ';
        }
    }

    char ** attack_board_player_1 = new char* [10];
    char ** attack_board_player_2 = new char* [10];

    for (size_t i = 0; i < 10; ++i) {
        attack_board_player_1[i] = new char [10];
        attack_board_player_2[i] = new char [10];
    }

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            attack_board_player_1[i][j] = ' ';
            attack_board_player_2[i][j] = ' ';
        }
    }

    
    
    std::cout << player_1_name << ", последовательно расставь свои корабли на поле, для каждого выбрав крайние палубы ";
    std::cout << "(возможно, совпадающие),\n";
    std::cout << "используя клавиши стрелочек для перемещения, enter для подтверждения выбора и Z для ";
    std::cout << "отмены ввода предыдущего корабля:\n\n";

    get_coordinates(coordinates_array_1);

    make_board(board_player_1, coordinates_array_1, 20, list_of_ships_1, ships_number_by_coordinates_1);

    Sleep(2000);

    system("cls");

    

    std::cout << player_2_name << ", последовательно расставь свои корабли на поле, для каждого выбрав крайние палубы ";
    std::cout << "(возможно, совпадающие),\n";
    std::cout << "используя клавиши стрелочек для перемещения, enter для подтверждения выбора и Z для ";
    std::cout << "отмены ввода предыдущего корабля:\n\n";

    get_coordinates(coordinates_array_2);

    make_board(board_player_2, coordinates_array_2, 20, list_of_ships_2, ships_number_by_coordinates_2);

    Sleep(2000);

    system("cls");

    



    std::cout << player_1_name << ", нажми enter, чтобы увидеть расположение своих кораблей, и попроси соперника не смотреть.\n\n";
    scan_enter();

    std::cout << player_1_name << ", расположение твоих кораблей:\n\n";
    draw_boards(attack_board_player_1, board_player_1, true, false);

    std::cout << "Нажми enter, чтобы продолжить\n\n";
    scan_enter();



    std::cout << player_2_name << ", нажми enter, чтобы увидеть расположение своих кораблей, и попроси соперника не смотреть.\n\n";
    scan_enter();

    std::cout << player_2_name << ", расположение твоих кораблей:\n\n";
    draw_boards(attack_board_player_2, board_player_2, true, false);

    std::cout << "Нажми enter, чтобы продолжить\n\n";
    scan_enter();



    std::cout << "Бой начинается!\n\n";

    Sleep(2000);
    
    system("cls");

    int unbroken_decks_count_1 = 20, unbroken_decks_count_2 = 20;
    srand(time(NULL));
    int number_of_moving_player = rand() % 2 + 1;
    int previous_number_of_moving_player = number_of_moving_player;
    bool quit;

    while (true) {

        std::cout << player_1_name << ": " << unbroken_decks_count_1 << '\n';
        std::cout << player_2_name << ": " << unbroken_decks_count_2 << '\n';
        std::cout << '\n';

        if (number_of_moving_player == 1) {
            std::cout << "Ходит " << player_1_name << "\n\n";
            quit = make_move(list_of_ships_2, unbroken_decks_count_2, number_of_moving_player, board_player_2, attack_board_player_1, \
            ships_number_by_coordinates_2, board_player_1);
        } else {
            std::cout << "Ходит " << player_2_name << "\n\n";
            quit = make_move(list_of_ships_1, unbroken_decks_count_1, number_of_moving_player, board_player_1, attack_board_player_2, \
            ships_number_by_coordinates_1, board_player_2);
        }

        system("cls");

        if (unbroken_decks_count_1 == 0 || unbroken_decks_count_2 == 0 || quit) {

            std::cout << "Бой завершен!\n\n";

            std::cout << player_1_name << ": " << unbroken_decks_count_1 << '\n';
            std::cout << player_2_name << ": " << unbroken_decks_count_2 << '\n';
            std::cout << '\n';

            if (unbroken_decks_count_1 == 0) {

                std::cout << player_2_name << ", ты победитель!!! (красава жестко)\n";
                std::cout << player_1_name << ", ты лузер. (бро, тебе надо тренироваться)\n\n";

            } else if (unbroken_decks_count_2 == 0) {

                std::cout << player_1_name << ", ты победитель!!! (красава жестко)\n";
                std::cout << player_2_name << ", ты лузер. (бро, тебе надо тренироваться)\n\n";

            } else {

                if (previous_number_of_moving_player == 1) {
                    std::cout << player_2_name << ", ты победитель!!! (красава жестко)\n";
                    std::cout << player_1_name << ", ты лузер. (бро, тебе надо тренироваться)\n\n";
                } else {
                    std::cout << player_1_name << ", ты победитель!!! (красава жестко)\n";
                    std::cout << player_2_name << ", ты лузер. (бро, тебе надо тренироваться)\n\n";
                }

            }
            
            break;

        }

        previous_number_of_moving_player = number_of_moving_player;

    }

    std::cout << "Нажмите enter, чтобы выйти из игры\n\n";
    scan_enter();
    


    delete [] coordinates_array_1;
    delete [] coordinates_array_2;



    for (size_t i = 0; i < 10; ++i) {
        delete [] attack_board_player_1[i];
        delete [] attack_board_player_2[i];
    }

    delete [] attack_board_player_1;
    delete [] attack_board_player_2;



    for (size_t i = 0; i < 10; ++i) {
        delete [] board_player_1[i];
        delete [] board_player_2[i];
    }

    delete [] board_player_1;
    delete [] board_player_2;



    for (size_t i = 0; i < 10; ++i) {
        delete [] ships_number_by_coordinates_1[i];
        delete [] ships_number_by_coordinates_2[i];
    }

    delete [] ships_number_by_coordinates_1;
    delete [] ships_number_by_coordinates_2;

    return 0;
}