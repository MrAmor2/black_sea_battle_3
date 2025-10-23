#include <iostream>
#include <string>

void draw_boards(char ** attack_board, char ** board, bool show_your_board, bool show_opponents_board) {

    std::string letters = "ABCDEFGHIJ";

    if (show_your_board && show_opponents_board) {

        std::cout << "Поле соперника: ";

        for (int i = 0; i < 32; ++i) {
            std::cout << " ";
        }

        std::cout << "Твое поле: ";

        std::cout << "\n\n";





        std::cout << "   ";

        for (int i = 0; i < 24; ++i) {

            if (i >= 3 && i <= 21 && i % 2 == 1) {
                std::cout << letters[(i - 1) / 2 - 1];
            } else {
                std::cout << ' ';
            }

        }

        for (int i = 0; i < 24; ++i) {
            std::cout << " ";
        }

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

        for (int i = 0; i < 24; ++i) {
            std::cout << " ";
        }

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

               if (attack_board[i][j] == '#') {
                    std::cout << "❎";
                }
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

            for (int j = 0; j < 24; ++j) {
                std::cout << " ";
            }

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

        for (int i = 0; i < 24; ++i) {
            std::cout << " ";
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

        std::cout << "\n\n";
        
    }

    else if (show_your_board) {
        
        std::cout << "Твое поле:\n\n";

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

        std::cout << "\n\n";

    }

    else if (show_opponents_board) {

        std::cout << "Поле соперника:\n\n";

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

        std::cout << "\n\n";

    }

}