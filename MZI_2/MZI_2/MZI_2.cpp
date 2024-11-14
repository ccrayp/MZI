#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <bitset>

#include "LCG.h"
#include "BBS.h"
#include "LFSR.h"

typedef unsigned int uint;

int LCG_init();
int BBS_init();
int LFSR_init();

int main()
{
    setlocale(0, "");
    unsigned char ch = 0;
    while (ch != '4') {
        system("cls");

        std::cout << "МЕНЮ\n\n1. LCG\n2. BBS\n3. LFSR\n4. Выход\n>> ";
        ch = _getch();
        if (ch < '4') {
            switch (ch) {
            case '1': LCG_init(); break;
            case '2': BBS_init(); break;
            case '3': LFSR_init(); break;
            }
        }
    }
    return 0;
}

int LCG_init() {
    system("cls");
    uint n = 0, seed = 0, a = 0, c = 0, m = 0;
    std::cout << "LCG generator\n\nВведите требуемое количество битов\n>> ";
    std::cin >> n;

    std::ofstream out("generated_LCG.bin", std::ios::binary);
    if (!out.is_open()) {
        std::cout << "File was not opened\n";
        return 1;
    }

    LCG LCG;
    std::vector<bool> binary;
    std::vector<uint8_t> decimal;
    std::bitset<8> b;
    system("cls");
    std::cout << "Сгенерированная LCG последовательность\n\nВ виде битовой строки:\n";
    for (int i = 0; i < n + 1; i++) {
        binary.push_back(LCG.generate());
        std::cout << binary.back();
        if (i % 8 == 0 && i != 0) {
            decimal.push_back(b.to_ulong());
            out.write(reinterpret_cast<const char*>(&decimal.back()), sizeof(uint8_t));
        }
        b[i % 8] = binary.back();
    }
    std::cout << std::endl << "\nВ виде 8-битных чисел:\n";
    for (int i = 0; i < decimal.size(); i++) {
        std::cout << (int)decimal[i] << " ";
    }

    std::cout << std::endl << std::endl;
    out.close();
    system("pause");
    return 0;
}

int BBS_init() {
    system("cls");
    uint n = 0, seed = 0, a = 0, c = 0, m = 0;
    std::cout << "BBS generator\n\nВведите требуемое количество битов\n>> ";
    std::cin >> n;

    std::ofstream out("generated_BBS.bin", std::ios::binary);
    if (!out.is_open()) {
        std::cout << "File was not opened\n";
        return 1;
    }

    BBS BBS;
    std::vector<bool> binary;
    std::vector<uint8_t> decimal;
    std::bitset<8> b;
    system("cls");
    std::cout << "Сгенерированная LCG последовательность\n\nВ виде битовой строки:\n";
    for (int i = 0; i < n + 1; i++) {
        binary.push_back(BBS.generate());
        std::cout << binary.back();
        if (i % 8 == 0 && i != 0) {
            decimal.push_back(b.to_ulong());
            out.write(reinterpret_cast<const char*>(&decimal.back()), sizeof(uint8_t));
        }
        b[i % 8] = binary.back();
    }
    std::cout << std::endl << "\nВ виде 8-битных чисел:\n";
    for (int i = 0; i < decimal.size(); i++) {
        std::cout << (int)decimal[i] << " ";
    }

    std::cout << std::endl << std::endl;
    out.close();
    system("pause");
    return 0;
}

int LFSR_init() {
    system("cls");
    uint n = 0, seed = 0, a = 0, c = 0, m = 0;
    std::cout << "LFSR generator\n\nВведите требуемое количество битов\n>> ";
    std::cin >> n;

    std::ofstream out("generated_LFSR.bin", std::ios::binary);
    if (!out.is_open()) {
        std::cout << "File was not opened\n";
        return 1;
    }

    LFSR LFSR;
    std::vector<bool> binary;
    std::vector<uint8_t> decimal;
    std::bitset<8> b;
    system("cls");
    std::cout << "Сгенерированная LFSR последовательность\n\nВ виде битовой строки:\n";
    for (int i = 0; i < n + 1; i++) {
        binary.push_back(LFSR.generate());
        std::cout << binary.back();
        if (i % 8 == 0 && i != 0) {
            decimal.push_back(b.to_ulong());
            out.write(reinterpret_cast<const char*>(&decimal.back()), sizeof(uint8_t));
        }
        b[i % 8] = binary.back();
    }
    std::cout << std::endl << "\nВ виде 8-битных чисел:\n";
    for (int i = 0; i < decimal.size(); i++) {
        std::cout << (int)decimal[i] << " ";
    }

    std::cout << std::endl << std::endl;
    out.close();
    system("pause");
    return 0;
}