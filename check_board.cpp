#include <vector>
#include <iostream>

bool check_board(std::vector <std::vector <std::pair <int, int>>> list_of_ships) {

    if (list_of_ships.size() != 10) {
        std::cout << "The number of ships is not equal to 10!\n\n";
        return false;
    }

    int count_1_deck = 0, count_2_deck = 0, count_3_deck = 0, count_4_deck = 0;

    for (int ship = 0; ship < 10; ++ship) {
        if (list_of_ships[ship].size() == 1) {
            count_1_deck += 1;
        } else if (list_of_ships[ship].size() == 2) {
            count_2_deck += 1;
        } else if (list_of_ships[ship].size() == 3) {
            count_3_deck += 1;
        } else if (list_of_ships[ship].size() == 4) {
            count_4_deck += 1;
        }
    }

    bool check_count_x_deck = true;

    if (count_1_deck != 4) {
        std::cout << "The count of single-deck ships is not equal to 4!\n\n";
        check_count_x_deck = false;
    }
    if (count_2_deck != 3) {
        std::cout << "The count of double-deck ships is not equal to 3!\n\n";
        check_count_x_deck = false;
    }
    if (count_3_deck != 2) {
        std::cout << "The count of three-deck ships is not equal to 2!\n\n";
        check_count_x_deck = false;
    }
    if (count_4_deck != 1) {
        std::cout << "The count of four-deck ships is not equal to 1!\n\n";
        check_count_x_deck = false;
    }

    if (check_count_x_deck == false) {
        return false;
    }

    for (int ship_1 = 0; ship_1 < 10; ++ship_1) {
        for (int ship_2 = 0; ship_2 < ship_1; ++ship_2) {
            for (int i = 0; i < list_of_ships[ship_1].size(); ++i) {
                for (int j = 0; j <list_of_ships[ship_2].size(); ++j) {
                    if (list_of_ships[ship_1][i].first - list_of_ships[ship_2][j].first <= 1 && \
                    list_of_ships[ship_1][i].second - list_of_ships[ship_2][j].second <= 1) {
                        std::cout << "Two ships bump!\n\n";
                        return false;
                    }
                }
            }
        }
    }

    return true;
    
}