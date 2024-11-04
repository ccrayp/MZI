#include <iostream>
#include "Feistel.h"

int main() {
    setlocale(0, "");
    char choice = 0;
    while (choice != '5') {
        system("cls");
        std::cout << "1. Зашифровать\n2. Расшифровать\n3. Изменить ключ\n4. Вывести текущий ключ\n5. Выход\n>> " << std::endl;
        std::cin >> choice;
        std::cout << choice;
        system("pause");
    }
}
