#include <iostream>
#include <string>

void draw_boards(char ** attack_board, char ** board, bool show_your_board, bool show_opponents_board) {

    std::string letters = "ABCDEFGHIJ";

    if (show_your_board) {
        
        std::cout << "Your board:\n\n";

        std::cout << "   ";

        for (int i = 0; i < 24; ++i) {

            if (i >= 3 && i <= 21 && i % 2 == 1) {
                std::cout << letters[(i - 1) / 2 - 1];
            } else {
                std::cout << ' ';
            }

        }

        std::cout << "\n";

        for (int i = 0; i < 24; ++i) {

            if (i == 0) {
                std::cout << "   ┌";
            } else if (i == 23) {
                std::cout << "┐";
            } else {
                std::cout << "─";
            }

        }

        std::cout << "\n";

        for (int i = 0; i < 10; ++i) {

            if (i != 9) {
                std::cout << " " << i + 1;
            } else {
                std::cout << i + 1;
            }

            std::cout << " │ ";

            for (int j = 0; j < 10; ++j) {
                if (board[i][j] == '#') {
                    std::cout << "❎";
                }
                if (board[i][j] == '.') {
                    std::cout << "💥";
                }
                if (board[i][j] == 'x') {
                    std::cout << "❌";
                }
                if (board[i][j] == ' ') {
                    std::cout << "🌊";
                }
            }

            std::cout << " │";
            std::cout << "\n";

        }

        for (int i = 0; i < 24; ++i) {

            if (i == 0) {
                std::cout << "   └";
            } else if (i == 23) {
                std::cout << "┘";
            } else {
                std::cout << "─";
            }

        }

        std::cout << '\n';

    }

    if (show_opponents_board) {

        std::cout << "Opponent's board:\n\n";

        std::cout << "   ";

        for (int i = 0; i < 24; ++i) {

            if (i >= 3 && i <= 21 && i % 2 == 1) {
                std::cout << letters[(i - 1) / 2 - 1];
            } else {
                std::cout << ' ';
            }

        }

        std::cout << "\n";

        for (int i = 0; i < 24; ++i) {

            if (i == 0) {
                std::cout << "   ┌";
            } else if (i == 23) {
                std::cout << "┐";
            } else {
                std::cout << "─";
            }

        }

        std::cout << "\n";

        for (int i = 0; i < 10; ++i) {

            if (i != 9) {
                std::cout << " " << i + 1;
            } else {
                std::cout << i + 1;
            }

            std::cout << " │ ";

            for (int j = 0; j < 10; ++j) {
                if (attack_board[i][j] == '.') {
                    std::cout << "🌊";
                }
                if (attack_board[i][j] == 'x') {
                    std::cout << "❌";
                }
                if (attack_board[i][j] == ' ') {
                    std::cout << "⬛";
                }
            }

            std::cout << " │";
            std::cout << "\n";

        }

        for (int i = 0; i < 24; ++i) {

            if (i == 0) {
                std::cout << "   └";
            } else if (i == 23) {
                std::cout << "┘";
            } else {
                std::cout << "─";
            }

        }

        std::cout << '\n';

    }

}