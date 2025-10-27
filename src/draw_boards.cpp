#include <iostream>
#include <string>

void draw_letters_line() {

    std::string letters = "ABCDEFGHIJ";

    std::cout << "   ";

    for (int x = 0; x < 24; ++x) {

        if (x >= 3 && x <= 21 && x % 2 == 1) {
            std::cout << letters[(x - 1) / 2 - 1];
        } else {
            std::cout << ' ';
        }

    }

}

void draw_upper_line() {

    for (int x = 0; x < 24; ++x) {

        if (x == 0) {
            std::cout << "   ┌";
        } else if (x == 23) {
            std::cout << "┐";
        } else {
            std::cout << "─";
        }

    }

}

void draw_lower_line() {

    for (int x = 0; x < 24; ++x) {

        if (x == 0) {
            std::cout << "   └";
        } else if (x == 23) {
            std::cout << "┘";
        } else {
            std::cout << "─";
        }

    }

}

void draw_empty_line(int len) {

    for (int x = 0; x < len; ++x) {
        std::cout << " ";
    }

}

void draw_your_decks_line(int y, char ** board) {

    if (y != 9) {
        std::cout << " " << y + 1;
    } else {
        std::cout << y + 1;
    }

    std::cout << " │ ";

    for (int x = 0; x < 10; ++x) {

        if (board[y][x] == '#') {
            std::cout << "❎";
        }
        if (board[y][x] == '.') {
            std::cout << "💥";
        }
        if (board[y][x] == 'x') {
            std::cout << "❌";
        }
        if (board[y][x] == ' ') {
            std::cout << "🌊";
        }

    }

    std::cout << " │";

}

void draw_opponents_decks_line(int y, char ** attack_board) {

    if (y != 9) {
        std::cout << " " << y + 1;
    } else {
        std::cout << y + 1;
    }

    std::cout << " │ ";

    for (int x = 0; x < 10; ++x) {

        if (attack_board[y][x] == '.') {
            std::cout << "🌊";
        }
        if (attack_board[y][x] == 'x') {
            std::cout << "❌";
        }
        if (attack_board[y][x] == ' ') {
            std::cout << "⬛";
        }

    }

    std::cout << " │";

}

void draw_boards(char ** attack_board, char ** board, bool show_your_board, bool show_opponents_board) {

    if (show_your_board && show_opponents_board) {

        std::cout << "Поле соперника: ";
        draw_empty_line(35);
        std::cout << "Твое поле: ";

        std::cout << "\n\n";

        draw_letters_line();
        draw_empty_line(24);
        draw_letters_line();

        std::cout << "\n";

        draw_upper_line();
        draw_empty_line(24);
        draw_upper_line();

        std::cout << "\n";

        for (int y = 0; y < 10; ++y) {

            draw_opponents_decks_line(y, attack_board);

            draw_empty_line(24);

            draw_your_decks_line(y, board);

            std::cout << "\n";

        }

        draw_lower_line();
        draw_empty_line(24);
        draw_lower_line();

        std::cout << "\n\n";
        
    }

    else if (show_your_board) {
        
        std::cout << "Твое поле:\n\n";

        draw_letters_line();

        std::cout << "\n";

        draw_upper_line();

        std::cout << "\n";

        for (int y = 0; y < 10; ++y) {

            draw_your_decks_line(y, board);
            std::cout << "\n";

        }

        draw_lower_line();

        std::cout << "\n\n";

    }

    else if (show_opponents_board) {

        std::cout << "Поле соперника:\n\n";

        draw_letters_line();

        std::cout << "\n";

        draw_upper_line();

        std::cout << "\n";

        for (int y = 0; y < 10; ++y) {

            draw_opponents_decks_line(y, attack_board);
            std::cout << "\n";

        }

        draw_lower_line();

        std::cout << "\n\n";

    }

}