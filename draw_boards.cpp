#include <iostream>
#include <string>

void draw_boards(char ** attack_board, char ** board) {

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