#include <iostream>
#include <fstream>

#include "LCG.h"
#include "BBS.h"
#include "LFSR.h"

typedef unsigned int uint;

int LCG_init();
int BBS_init();
int LFSR_init();

int main()
{
    return LCG_init();
}

int LCG_init() {
    uint n = 0, seed = 0, a = 0, c = 0, m = 0;
    std::cout << "LCG generator\n\nEnter n: ";
    std::cin >> n;
    std::ofstream out("generated_LCG.txt");
    if (!out.is_open()) {
        std::cout << "File was not opened\n";
        return 1;
    }
    std::cout << std::endl;
    LCG LCG;
    for (int i = 0; i < n; i++) {
        std::cout << LCG.generate() << " ";
    }
    std::cout << std::endl;

    return 0;
}

int BBS_init() {
    std::cout << "BBS generator\n\nEnter n: ";
    uint n = 0;
    std::cin >> n;
    std::ofstream out("generated_BBS.txt");
    if (!out.is_open()) {
        std::cout << "File was not opened\n";
        return 1;
    }
    std::cout << std::endl;
    BBS BBS;
    for (int i = 0; i < n; i++) {
        std::cout << BBS.generate() << " ";
    }
    std::cout << std::endl;

    return 0;
}

int LFSR_init() {
    uint n = 0, seed = 0, p = 0, q = 0;
    std::cout << "LFSR generator\n\nEnter n: ";
    std::cin >> n;
    std::ofstream out("generated_BBS.txt");
    if (!out.is_open()) {
        std::cout << "File was not opened\n";
        return 1;
    }
    std::cout << std::endl;
    LFSR LFSR;
    for (int i = 0; i < n; i++) {
        std::cout << LFSR.generate() << " ";
    }
    std::cout << std::endl;

    return 0;
}