#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>

#include "Cardano.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char choice = ' ';
    Cardano Cardano;
    while (choice != '3') {
        system("cls");
        std::cout << "1. Зашифровать\n2. Расшифровать\n3. Выход\n>> ";
        std::cin >> choice;
        system("cls");
        switch (choice) {
        case '1': {
            std::cout << "Введите путь к файлу для зашифровки\n>> ";
            std::string filepath;
            std::cin >> filepath;
            if (!filepath.empty())
                Cardano.encode(filepath); break;
        }
        case '2': {
            std::cout << "Введите путь к файлу для расшифровки\n>> ";
            std::string filepath;
            std::cin >> filepath;
            if(!filepath.empty())
                Cardano.decode(filepath); break;
        }
        }
    }

    return 0;
}