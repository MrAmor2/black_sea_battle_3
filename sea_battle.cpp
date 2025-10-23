#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

#include "include\get_coordinates.hpp"
#include "include\make_board.hpp"
#include "include\draw_boards.hpp"
#include "include\fill_list_of_ships.hpp"
#include "include\make_move.hpp"
#include "include\mini_functions.hpp"
#include "include\print_rules.hpp"

int main() {

    SetConsoleOutputCP(CP_UTF8);

    system("cls");

    std::cout << "Добро пожаловать в Морской бой на Черном море!\n\n";

    std::string player_1_name, player_2_name;

    std::cout << "Игрок №1, введи свое имя на английском языке:" << "\n\n";
    move_cursor(46, 2);
    getline(std::cin, player_1_name);
    std::cout << '\n';

    std::cout << "Игрок №2, введи свое имя на английском языке:" << "\n\n";
    move_cursor(46, 4);
    getline(std::cin, player_2_name);
    std::cout << '\n';

    print_rules();

    int button_code;

    while (true) {

        button_code = _getch();

        if (button_code == 13) {
            system("cls");
            break;
        }

    }

    std::pair <int, int> coordinates_array_1[20], coordinates_array_2[20];

    std::vector <std::vector <std::pair <int, int>>> list_of_ships_1(10), list_of_ships_2(10);

    int ** ships_number_by_coordinates_1 = new int* [10];
    for (size_t i = 0; i < 10; ++i) {
        ships_number_by_coordinates_1[i] = new int [10];
    }
    
    int ** ships_number_by_coordinates_2 = new int* [10];
    for (size_t i = 0; i < 10; ++i) {
        ships_number_by_coordinates_2[i] = new int [10];
    }

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            ships_number_by_coordinates_1[i][j] = -1;
            ships_number_by_coordinates_2[i][j] = -1;
        }
    }

    

    std::cout << player_1_name << ", последовательно расставь свои корабли на поле, для каждого выбрав крайние палубы ";
    std::cout << "(возможно, совпадающие),\n";
    std::cout << "используя клавиши стрелочек для перемещения, enter для подтверждения выбора и z или Z для ";
    std::cout << "отмены ввода последнего корабля:\n\n";

    get_coordinates(coordinates_array_1);

    fill_list_of_ships(list_of_ships_1, coordinates_array_1, ships_number_by_coordinates_1);

    Sleep(2000);

    system("cls");

    

    std::cout << player_2_name << ", последовательно расставь свои корабли на поле, для каждого выбрав крайние палубы ";
    std::cout << "(возможно, совпадающие),\n";
    std::cout << "используя клавиши стрелочек для перемещения, enter для подтверждения выбора и z или Z для ";
    std::cout << "отмены ввода последнего корабля:\n\n";

    get_coordinates(coordinates_array_2);

    fill_list_of_ships(list_of_ships_2, coordinates_array_2, ships_number_by_coordinates_2);

    Sleep(2000);

    system("cls");

    

    char ** board_player_1 = new char* [10];
    for (size_t i = 0; i < 10; ++i) {
        board_player_1[i] = new char [10];
    }
    
    char ** board_player_2 = new char* [10];
    for (size_t i = 0; i < 10; ++i) {
        board_player_2[i] = new char [10];
    }

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            board_player_1[i][j] = ' ';
            board_player_2[i][j] = ' ';
        }
    }

    make_board(board_player_1, coordinates_array_1, 20);
    make_board(board_player_2, coordinates_array_2, 20);

    char ** attack_board_player_1 = new char* [10];
    for (size_t i = 0; i < 10; ++i) {
        attack_board_player_1[i] = new char [10];
    }
    
    char ** attack_board_player_2 = new char* [10];
    for (size_t i = 0; i < 10; ++i) {
        attack_board_player_2[i] = new char [10];
    }

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            attack_board_player_1[i][j] = ' ';
            attack_board_player_2[i][j] = ' ';
        }
    }



    std::cout << player_1_name << ", нажми enter, чтобы увидеть расположение своих кораблей, и попроси соперника не смотреть.\n\n";

    std::cin.ignore();

    system("cls");

    std::cout << player_1_name << ", расположение твоих кораблей:\n\n";
    draw_boards(attack_board_player_1, board_player_1, true, false);

    std::cout << "Нажми enter, чтобы продолжить\n\n";
    std::cin.ignore();

    system("cls");



    std::cout << player_2_name << ", нажми enter, чтобы увидеть расположение своих кораблей, и попроси соперника не смотреть.\n\n";

    std::cin.ignore();

    system("cls");

    std::cout << player_2_name << ", расположение твоих кораблей:\n\n";
    draw_boards(attack_board_player_2, board_player_2, true, false);

    std::cout << "Нажми enter, чтобы продолжить\n\n";
    std::cin.ignore();

    system("cls");



    std::cout << "Бой начинается!\n\n";

    Sleep(2000);
    
    system("cls");

    int decks_count_1 = 20, decks_count_2 = 20;
    int number_of_moving_player = 1;

    while (true) {

        std::cout << player_1_name << ": " << decks_count_1 << '\n';
        std::cout << player_2_name << ": " << decks_count_2 << '\n';
        std::cout << '\n';

        if (number_of_moving_player == 1) {
            std::cout << "Ходит " << player_1_name << "\n\n";
            make_move(list_of_ships_2, decks_count_2, number_of_moving_player, board_player_2, attack_board_player_1, \
            ships_number_by_coordinates_2, board_player_1);
        } else {
            std::cout << "Ходит " << player_2_name << "\n\n";
            make_move(list_of_ships_1, decks_count_1, number_of_moving_player, board_player_1, attack_board_player_2, \
            ships_number_by_coordinates_1, board_player_2);
        }

        if (decks_count_1 == 0) {

            std::cout << "Бой завершен!\n\n";

            std::cout << player_1_name << ": " << decks_count_1 << '\n';
            std::cout << player_2_name << ": " << decks_count_2 << '\n';
            std::cout << '\n';

            std::cout << player_2_name << ", ты победитель!!!\n";
            std::cout << player_1_name << ", ты лузер.\n";
            
            break;

        } else if (decks_count_2 == 0) {

            std::cout << "Бой завершен!\n\n";

            std::cout << player_1_name << ": " << decks_count_1 << '\n';
            std::cout << player_2_name << ": " << decks_count_2 << '\n';
            std::cout << '\n';

            std::cout << player_1_name << ", ты победитель!!!\n";
            std::cout << player_2_name << ", ты лузер.\n";
            break;
            
        }



    }

    Sleep(5000);
    system("cls");

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