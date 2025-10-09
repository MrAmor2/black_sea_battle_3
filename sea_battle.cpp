#include <iostream>
#include <windows.h>

#include "include\get_coordinates.hpp"
#include "include\make_board.hpp"
#include "include\draw_boards.hpp"
#include "include\fill_list_of_ships.hpp"
#include "include\check_board.hpp"
#include "include\make_move.hpp"

int main() {

    SetConsoleOutputCP(CP_UTF8);

    system("cls");

    std::string player_1_name, player_2_name;

    std::cout << "Player #1, enter your name" << "\n\n";
    getline(std::cin, player_1_name);
    std::cout << '\n';

    Sleep(2000);

    system("cls");

    std::cout << "Player #2, enter your name" << "\n\n";
    getline(std::cin, player_2_name);
    std::cout << '\n';

    Sleep(2000);

    system("cls");
    
    // Здесь могут быть правила

    // Здесь может быть пустая доска с числами и буквами

    /*

    На своем поле:

    ' ' - нет палубы, не нанесен удар

    '.' - нет палубы, нанесен удар или точно не будет нанесен

    '#' - есть целая палуба

    'х' - есть уничтоженная палуба

    В атаке:

    ' ' - удар не нанесен
    
    '.' - нанесен удар, мимо

    'x' - нанесен удар, попадание

    */

    std::vector <std::pair <int, int>> coordinates_1;
    std::vector <std::pair <int, int>> coordinates_2;

    // По воpможности поменяю на std::pair <int, int> **

    std::vector <std::vector <std::pair <int, int>>> list_of_ships_1(10);
    std::vector <std::vector <std::pair <int, int>>> list_of_ships_2(10);

    // И здесь

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

    while (true) {

        std::cout << player_1_name << ", arrange your ships on the game board by specifying the coordinates of the extreme decks ";
        std::cout << "in the format \"letternumber letternumber\"\n\n";

        coordinates_1 = get_coordinates();

        fill_list_of_ships(list_of_ships_1, coordinates_1, ships_number_by_coordinates_1);

        Sleep(2000);

        system("cls");

        if (check_board(list_of_ships_1)) {
            break;
        }

    }

    while (true) {

        std::cout << player_2_name << ", arrange your ships on the game board by specifying the coordinates of the extreme decks ";
        std::cout << "in the format \"letternumber letternumber\"\n\n";

        coordinates_2 = get_coordinates();

        fill_list_of_ships(list_of_ships_2, coordinates_2, ships_number_by_coordinates_2);

        Sleep(2000);

        system("cls");

        if (check_board(list_of_ships_2)) {
            break;
        }

    }

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

    make_board(board_player_1, coordinates_1);
    make_board(board_player_2, coordinates_2);

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



    std::cout << player_1_name << ", press enter to see the location of your ships and tell your opponent not to look\n\n";

    std::cin.ignore();
    std::cin.ignore();

    system("cls");

    std::cout << player_1_name << ", your location of the ships:\n\n";
    draw_boards(attack_board_player_1, board_player_1, true, false);

    std::cout << "Press enter to continue\n";
    std::cin.ignore();

    system("cls");



    std::cout << player_2_name << ", press enter to see the location of your ships and tell your opponent not to look\n\n";

    std::cin.ignore();

    system("cls");

    std::cout << player_2_name << ", your location of the ships:\n\n";
    draw_boards(attack_board_player_2, board_player_2, true, false);

    std::cout << "Press enter to continue\n";
    std::cin.ignore();

    system("cls");



    std::cout << "Fight starts!\n\n";

    Sleep(2000);
    
    system("cls");

    int decks_count_1 = 20, decks_count_2 = 20;
    int move = 1;

    while (true) {

        std::cout << player_1_name << ": " << decks_count_1 << '\n';
        std::cout << player_2_name << ": " << decks_count_2 << '\n';
        std::cout << '\n';

        if (move == 1) {
            std::cout << player_1_name << " moves\n\n";
            make_move(list_of_ships_2, decks_count_2, move, board_player_2, attack_board_player_1, \
            ships_number_by_coordinates_2, board_player_1);
        } else {
            std::cout << player_2_name << " moves\n\n";
            make_move(list_of_ships_1, decks_count_1, move, board_player_1, attack_board_player_2, \
            ships_number_by_coordinates_1, board_player_2);
        }

        //std::cout << player_1_name << ": " << decks_count_1 << '\n';
        //std::cout << player_2_name << ": " << decks_count_2 << '\n';
        //std::cout << '\n';

        if (decks_count_1 == 0) {

            std::cout << player_1_name << ": " << decks_count_1 << '\n';
            std::cout << player_2_name << ": " << decks_count_2 << '\n';
            std::cout << '\n';

            std::cout << player_2_name << ", you're a winner!!!\n";
            std::cout << player_1_name << ", you're a loser.\n";
            break;

        } else if (decks_count_2 == 0) {

            std::cout << player_1_name << ": " << decks_count_1 << '\n';
            std::cout << player_2_name << ": " << decks_count_2 << '\n';
            std::cout << '\n';

            std::cout << player_1_name << ", you're a winner!!!\n";
            std::cout << player_2_name << ", you,re a loser.\n";
            break;
            
        }

    }

    // system("cls");



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