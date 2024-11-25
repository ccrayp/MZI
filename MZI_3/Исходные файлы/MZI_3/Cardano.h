#pragma once
class Cardano
{
public:
    Cardano() : temporary(std::vector<std::vector<char>>(8, std::vector<char>(8, 'x'))) {}

    int encode(std::string filepath) {
        std::ifstream in(filepath);
        if (!in.is_open())
            return 1;

        std::ofstream out(filepath.erase(filepath.find('.') + 1).append("cipher.txt"));

        char c;
        std::string block;
        for (int i = 0; in >> c; i++) {
            if (i != 0 && i % 16 == 0) {
                write(block, out);
                block.clear();
            }
            block += c;
        }
        if (!block.empty()) {
            status = 3;
            write(block, out);
            status = 0;
            clear(temporary);
        }
        reset_grid();
        in.close();
        out.close();

        return 0;
    }

    void write(std::string data, std::ofstream &out) {
        unsigned short int counter = 0;
        for (int i = 0; i < grid.size() && counter != data.size(); i++) {
            for (int j = 0; j < grid.size() && counter != data.size(); j++) {
                if (grid[i][j]) {
                    temporary[i][j] = data[counter++];
                }
            }
        }
        status++;
        rotate();
        if (status == 4) {
            for (int i = 0; i < temporary.size(); i++) {
                for (int j = 0; j < temporary.size(); j++) {
                    out << temporary[i][j];
                }
            }
            status = 0;
            clear(temporary);
        }
    }

    int decode(std::string filepath) {
        std::ifstream in(filepath);
        if (!in.is_open())
            return 1;

        std::ofstream out(filepath.erase(filepath.find('.') + 1).append("public.txt"));

        char c;
        std::string block;
        for (int i = 0; in >> c; i++) {
            if (i != 0 && i % 64 == 0) {
                read(block, out);
                block.clear();
            }
            block += c;
        }
        if (!block.empty()) {
            status = 3;
            read(block, out);
            status = 0;
            clear(temporary);
        }
        reset_grid();
        in.close();
        out.close();
        
        return 0;
    }

    void read(std::string data, std::ofstream& out) {
        unsigned short int counter = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                temporary[i][j] = data[counter++];
            }
        }
        reset_grid();
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (grid[i][j] && temporary[i][j] != 'x')
                        out << temporary[i][j];
                }
            }
            rotate();
        }
        status = 0;
        reset_grid();
    }

private:
    void reset_grid() {
        grid = { { 0, 1, 0, 1, 0, 0, 1, 0 }, { 0, 0, 0, 0, 1, 0, 0, 0 }, { 1, 0, 1, 0, 0, 0, 1, 0 }, { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0, 1, 0, 0 }, { 1, 0, 0, 0, 1, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0, 1, 0 }, { 0, 0, 0, 1, 0, 0, 0, 1 } };
    }

    void rotate() {
        std::vector<std::vector<bool>> temp(grid.size(), std::vector<bool>(grid.size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = grid.size() - 1; j > -1; j--) {
                temp[(j - 7)*-1][i] = grid[i][j];
            }
        }
        grid = temp;
    }

    void clear(std::vector<std::vector<char>> test) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                test[i][j] = 'x';
            }
        }
    }

    std::vector<std::vector<bool>> grid = { { 0, 1, 0, 1, 0, 0, 1, 0 },
                                            { 0, 0, 0, 0, 1, 0, 0, 0 },
                                            { 1, 0, 1, 0, 0, 0, 1, 0 },
                                            { 0, 0, 0, 1, 0, 0, 0, 0 },
                                            { 0, 1, 0, 0, 0, 1, 0, 0 },
                                            { 1, 0, 0, 0, 1, 0, 0, 0 },
                                            { 0, 0, 1, 0, 0, 0, 1, 0 },
                                            { 0, 0, 0, 1, 0, 0, 0, 1 } };

    std::vector<std::vector<char>> temporary;
    unsigned short int status = 0;
    std::string filepath;
};

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
//                                            { 0, 0, 0, 0, 0, 0, 0, 1 },
//                                            { 0, 0, 0, 0, 0, 0, 0, 0 },
//                                            { 0, 0, 0, 0, 0, 0, 0, 0 },
//                                            { 0, 0, 0, 0, 0, 0, 0, 0 },
//                                            { 0, 0, 0, 0, 0, 0, 0, 0 },
//                                            { 0, 0, 0, 0, 0, 0, 0, 0 },
//                                            { 0, 0, 0, 0, 0, 0, 0, 0 } };
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