#include <iostream>
#include <string>

void draw_boards(char ** attack_board, char ** board, bool show_your_board, bool show_opponents_board) {

    if (show_your_board) {

        std::cout << "Your board:\n\n";

        std::cout << "   A B C D E F G H I J \n";

        for (int i = 0; i < 10; ++i) {

            std::cout << i + 1 << "  ";

            for (int j = 0; j < 10; ++j) {
                std::cout << board[i][j] << ' ';
            }

            std::cout << '\n';

        }

        std::cout << '\n';

    }

    if (show_opponents_board) {

        std::cout << "Opponent's board:\n\n";

        std::cout << "   A B C D E F G H I J \n";

        for (int i = 0; i < 10; ++i) {

            std::cout << i + 1 << "  ";

            for (int j = 0; j < 10; ++j) {
                std::cout << attack_board[i][j] << ' ';
            }

            std::cout << '\n';

        }

        std::cout << '\n';

    }
}