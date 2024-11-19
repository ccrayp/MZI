#pragma once

#include <string>
#include <vector>

class Cardano {
public:
    Cardano(std::vector<std::vector<bool>> grid, size_t quantity) : grid(grid), start_grid(grid), quantity(quantity), temporary(std::vector<std::vector<char>>(8, std::vector<char>(8, 'x'))) {}

    void rotate(std::vector<std::vector<bool>>& grid) {
        std::vector<std::vector<bool>> temp(8, std::vector<bool>(8));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = grid.size() - 1; j > -1; j--) {
                temp[(j - 7) * -1][i] = grid[i][j];
            }
        }
        grid = temp;
    }

    void clear(std::vector<std::vector<char>>& test) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                test[i][j] = 'x';
            }
        }
    }

    void reset_grid() {
        grid = start_grid;
    }

    void write(std::string data) {
        unsigned short int counter = 0;
        for (int i = 0; i < grid.size() && counter != data.size(); i++) {
            for (int j = 0; j < grid.size() && counter != data.size(); j++) {
                if (grid[i][j]) {
                    temporary[i][j] = data[counter++];
                }
            }
        }
        status++;
        rotate(grid);
        if (status == 4) {
            for (int i = 0; i < temporary.size(); i++) {
                for (int j = 0; j < temporary.size(); j++) {
                    result += temporary[i][j];
                }
            }
            status = 0;
            clear(temporary);
        }
    }

    std::string encode(std::string data) {
        result.clear();

        std::string block;
        for (int i = 0; i < data.size(); i++) {
            if (i != 0 && i % quantity == 0) {
                write(block);
                block.clear();
            }
            block += data[i];
        }
        if (!block.empty()) {
            status = 3;
            write(block);
            status = 0;
            clear(temporary);
        }
        reset_grid();

        return result;
    }

    void read(std::string data) {
        unsigned short int counter = 0;
        for (int i = 0; i < 8 && counter != data.size(); i++) {
            for (int j = 0; j < 8 && counter != data.size(); j++) {
                temporary[i][j] = data[counter++];
            }
        }
        reset_grid();
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (grid[i][j] && temporary[i][j] != 'x')
                        result += temporary[i][j];
                }
            }
            rotate(grid);
        }
        status = 0;
        reset_grid();
    }

    std::string decode(std::string data) {
        result.clear();

        std::string block;
        for (int i = 0; i < data.size(); i++) {
            if (i != 0 && i % 64 == 0) {
                read(block);
                block.clear();
            }
            block += data[i];
        }
        if (!block.empty()) {
            status = 3;
            read(block);
            status = 0;
            clear(temporary);
        }
        reset_grid();

        return result;
    }

private:
    std::vector<std::vector<bool>> start_grid;
    std::vector<std::vector<char>> temporary;
    unsigned short int status = 0;
    std::string result;
    size_t quantity;
    std::vector<std::vector<bool>> grid;
};

std::string init(char grid_mode, char mode, std::string data/*, std::string key*/) {
    std::vector<std::vector<bool>> grid;
    size_t q = 0;
    switch (grid_mode) {
    case 1: grid = { { 0, 1, 0, 1, 0, 0, 1, 0 },
                     { 0, 0, 0, 0, 1, 0, 0, 0 },
                     { 1, 0, 1, 0, 0, 0, 1, 0 },
                     { 0, 0, 0, 1, 0, 0, 0, 0 },
                     { 0, 1, 0, 0, 0, 1, 0, 0 },
                     { 1, 0, 0, 0, 1, 0, 0, 0 },
                     { 0, 0, 1, 0, 0, 0, 1, 0 },
                     { 0, 0, 0, 1, 0, 0, 0, 1 } }; q = 16; break;

    case 2: grid = { { 0, 1, 0, 1, 0, 0, 1, 0 },
                     { 0, 0, 0, 0, 1, 0, 0, 0 },
                     { 1, 0, 1, 0, 0, 0, 1, 0 },
                     { 0, 0, 0, 1, 0, 0, 0, 0 },
                     { 0, 1, 0, 0, 0, 1, 0, 0 },
                     { 1, 0, 0, 0, 1, 0, 0, 0 },
                     { 0, 0, 1, 0, 0, 0, 1, 0 },
                     { 0, 0, 0, 1, 0, 0, 0, 1 } }; q = 16; break;

    case 3: grid = { { 0, 1, 0, 1, 0, 0, 1, 0 },
                     { 0, 0, 0, 0, 1, 0, 0, 0 },
                     { 1, 0, 1, 0, 0, 0, 1, 0 },
                     { 0, 0, 0, 1, 0, 0, 0, 0 },
                     { 0, 1, 0, 0, 0, 1, 0, 0 },
                     { 1, 0, 0, 0, 1, 0, 0, 0 },
                     { 0, 0, 1, 0, 0, 0, 1, 0 },
                     { 0, 0, 0, 1, 0, 0, 0, 1 } }; q = 16; break;

    case 4: grid = { { 0, 1, 0, 1, 1, 0, 1, 0 },
                     { 0, 1, 0, 0, 0, 1, 1, 1 },
                     { 0, 1, 0, 0, 0, 0, 0, 1 },
                     { 1, 0, 1, 1, 1, 1, 1, 1 },
                     { 1, 0, 0, 0, 1, 1, 0, 0 },
                     { 1, 1, 0, 1, 0, 1, 1, 0 },
                     { 1, 0, 0, 1, 0, 0, 0, 1 },
                     { 1, 1, 0, 1, 0, 0, 0, 0 } }; q = 32; break;
    }

    Cardano Cardano(grid, q);

    switch (mode) {
    case 0: return Cardano.encode(data); break;
    case 1: return Cardano.decode(data); break;
    }
}

//void test() {
//    std::vector<std::vector<int>> test(8, std::vector<int>(8, 0));
//    for (int i = 0; i < 4; i++) {
//        rotate();
//        count(test);
//    }
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 8; j++) {
//            std::cout << test[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}
//
//void print_grid() {
//    std::cout << std::endl;
//    for (int i = 0; i < grid.size(); i++) {
//        for (int j = 0; j < grid.size(); j++) {
//            grid[i][j] ? std::cout << ' ' : std::cout << '#';
//        }
//        std::cout << std::endl;
//    }
//}
//
//std::vector<std::vector<bool>> grid = { { 0, 0, 0, 0, 0, 0, 1, 1 },
//                                        { 0, 0, 0, 0, 0, 0, 0, 1 },
//                                        { 0, 0, 0, 0, 0, 0, 0, 0 },
//                                        { 0, 0, 0, 0, 0, 0, 0, 0 },
//                                        { 0, 0, 0, 0, 0, 0, 0, 0 },
//                                        { 0, 0, 0, 0, 0, 0, 0, 0 },
//                                        { 0, 0, 0, 0, 0, 0, 0, 0 },
//                                        { 0, 0, 0, 0, 0, 0, 0, 0 } };
//
//void count(std::vector<std::vector<int>>& test) {
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 8; j++) {
//            if (grid[i][j])
//                test[i][j]++;
//        }
//    }
//}
//
//void o(std::vector<std::vector<char>> test) {
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 8; j++) {
//            std::cout << test[i][j] << ' ';
//        }
//        std::cout << std::endl;
//    }
//}