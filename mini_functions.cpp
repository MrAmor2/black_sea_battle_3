#include <iostream>
#include <conio.h>
#include <windows.h>

void move_cursor(int x, int y) {  
    COORD coord;  
    coord.X = x;  
    coord.Y = y;  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  
}

void print_unicode(char x) {
    if (x == '#') {
        std::cout << "❎";
    }
    if (x == '.') {
        std::cout << "🌊";
    }
    if (x == 'x') {
        std::cout << "❌";
    }
    if (x == ' ') {
        std::cout << "🌊";
    }
}