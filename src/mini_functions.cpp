#include <iostream>
#include <conio.h>
#include <windows.h>

void move_cursor(int x, int y) {

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void print_unicode(char c) {

    if (c == '#') {
        std::cout << "❎";
    }
    if (c == '.') {
        std::cout << "🌊";
    }
    if (c == 'x') {
        std::cout << "❌";
    }
    if (c == ' ') {
        std::cout << "🌊";
    }

}