#include <iostream>
#include <string>
#include <vector>

int abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

std::vector <std::pair <int, int>> get_coordinates() {

    std::string upper_letters = "QWERTYUIOPASDFGHJKLZXCVBNM";

    std::string input_coordinates;
    std::vector <std::pair <int, int>> coordinates_array(20);

    bool flag = false;

    while (flag != true) {
        for (size_t i = 0; i < 20; ++i) {
            std::cin >> input_coordinates;
            if (upper_letters.find(input_coordinates[0]) == std::string::npos) {

                if (input_coordinates.size() == 3) {
                    coordinates_array[i] = {10 - 1, (int) input_coordinates[0] - 'a'};
                } else {
                    coordinates_array[i] = {input_coordinates[1] - '1', \
                        (int) input_coordinates[0] - 'a'};
                }

            } else {

                if (input_coordinates.size() == 3) {
                    coordinates_array[i] = {10 - 1, (int) input_coordinates[0] - 'A'};
                } else {
                    coordinates_array[i] = {input_coordinates[1] - '1', \
                        (int) input_coordinates[0] - 'A'};
                }

            }
        }

        std::cout << '\n';

        bool check_correctness = true;

        for (int i = 0; i < 20; i += 2) {

            std::pair <int, int> pair_1 = coordinates_array[i], pair_2 = coordinates_array[i + 1];

            if (pair_1.first != pair_2.first && pair_1.second != pair_2.second) {
                check_correctness = false;
                std::cout << "The ship can only be on one line!\n\n";
            }

            if (pair_1.first == pair_2.first && abs(pair_1.second - pair_2.second) >= 5) {
                check_correctness = false;
                std::cout << "The ship cannot be longer than 4!\n\n";
            }

            if (pair_1.second == pair_2.second && abs(pair_1.first - pair_2.first) >= 5) {
                check_correctness = false;
                std::cout << "The ship cannot be longer than 4!\n\n";
            }

            if (pair_1.first < 0 || pair_1.first > 9 || pair_2.first < 0 || pair_2.first > 9) {
                check_correctness = false;
                std::cout << "The ship must be completely within the 10x10 board!\n\n";
            }

            if (pair_1.second < 0 || pair_1.second > 25 || pair_2.second < 0 || pair_2.second > 25) {
                check_correctness = false;
                std::cout << "The ship must be completely within the 10x10 board!\n\n";
            }
        }

        if (check_correctness == false) {
            std::cout << "enter the coordinates of the ships again\n\n";
        } else {
            std::cout << "Correctly\n\n";
            flag = true;
        }
    }

    return coordinates_array;
}