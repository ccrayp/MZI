#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>

#include "Cardano.h"
#include "Caesar.h"

void method_menu();
void Caesar_number();
void Caesar_text();
void Caesar_LFSR();
std::string get_data();
void save(std::string data);

size_t constanta;
std::string text = "";
std::string seed = "00000000";

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char choice = ' ';
    while (choice != '3') {
        system("cls");
        std::cout << "МЕНЮ\n\n1. Шифрование решёткой Кардано\n2. Шифрование Цезарем (3 метода)\n3. Выход\n>> ";
        std::cin >> choice;
        system("cls");
        switch (choice) {
        case '1': std::cout << "Приложение открыто в другом окне\n\n"; system("MZI_3G.exe"); break;
        case '2': method_menu(); break;
        }
    }

    return 0;
}

void method_menu() {
    char choice = ' ';
    while (choice != '4') {
        system("cls");
        std::cout << "МЕНЮ ШИФР ЦЕЗАРЯ\n\n1. Ключ - константа\n2. Ключ поговорка\n3. Ключ ПСП\n4. Вернутся в основное меню\n>> ";
        std::cin >> choice;
        system("cls");
        switch (choice) {
        case '1': Caesar_number(); break;
        case '2': Caesar_text(); break;
        case '3': Caesar_LFSR(); break;
        }
    }
}

void Caesar_number() {
    system("cls");
    Caesar Caesar;
    char choice = ' ';
    while (choice != '4') {
        system("cls");
        std::cout << "КЛЮЧ КОНСТАНТА\n\n1. Зашифровать\n2. Расшифровать\n3. Изменить ключ\n4. Вернутся в меню Цезаря\n>> ";
        std::cin >> choice;
        system("cls");
        std::string data = "1";
        if (choice == '1' || choice == '2') {
            data = get_data();
            if(!data.empty())
                std::cout << "\nИсходный текст:\n" << data;
        }
        if(!data.empty())
        switch (choice) {
        case '1': {
            data = Caesar.encode(data, constanta);
            std::cout << "\n\nЗашифрованный текст:\n" << data << std::endl << std::endl;
            save(data);
            break;
        }
        case '2': {
            data = Caesar.decode(data, constanta);
            std::cout << "\n\nРасшифрованный текст:\n" << data << std::endl << std::endl;
            save(data);
            break;
        }
        case '3': {
            std::cout << "Текущий ключ: " << constanta << "\n\nВведите новых ключ\n>> ";
            std::cin >> constanta;
        }
        }
        data = "1";
    }
}

void Caesar_text() {
    system("cls");
    Caesar Caesar;
    char choice = ' ';
    while (choice != '4') {
        system("cls");
        std::cout << "КЛЮЧ ПОГОВОРКА\n\n1. Зашифровать\n2. Расшифровать\n3. Изменить ключ\n4. Вернутся в меню Цезаря\n>> ";
        std::cin >> choice;
        system("cls");
        std::string data = "1";
        if (choice == '1' || choice == '2') {
            data = get_data();
            if (!data.empty())
                std::cout << "\nИсходный текст:\n" << data;
        }
        if (!data.empty())
            switch (choice) {
            case '1': {
                data = Caesar.encode_text_key(data, text);
                std::cout << "\n\nЗашифрованный текст:\n" << data << std::endl << std::endl;
                save(data);
                break;
            }
            case '2': {
                data = Caesar.decode_text_key(data, text);
                std::cout << "\n\nРасшифрованный текст:\n" << data << std::endl << std::endl;
                save(data);
                break;
            }
            case '3': {
                std::cout << "Текущий ключ: " << text << "\n\nВведите новых ключ\n>> ";
                std::cin.ignore();
                getline(std::cin, text);
            }
            }
        data = "1";
    }
}

void Caesar_LFSR() {
    system("cls");
    Caesar Caesar;
    char choice = ' ';
    while (choice != '4') {
        system("cls");
        std::cout << "КЛЮЧ ПСП\n\n1. Зашифровать\n2. Расшифровать\n3. Изменить ключ\n4. Вернутся в меню Цезаря\n>> ";
        std::cin >> choice;
        system("cls");
        std::string data = "1";
        if (choice == '1' || choice == '2') {
            data = get_data();
            if (!data.empty())
                std::cout << "\nИсходный текст:\n" << data;
        }
        if (!data.empty())
            switch (choice) {
            case '1': {
                data = Caesar.encode_LFSR(data, std::bitset<8>(seed).to_ulong());
                std::cout << "\n\nЗашифрованный текст:\n" << data << std::endl << std::endl;
                save(data);
                break;
            }
            case '2': {
                data = Caesar.decode_LFSR(data, std::bitset<8>(seed).to_ulong());
                std::cout << "\n\nРасшифрованный текст:\n" << data << std::endl << std::endl;
                save(data);
                break;
            }
            case '3': {
                std::cout << "Текущий ключ: " << seed << "\n\nВведите новых ключ\n>> ";
                std::cin.ignore();
                getline(std::cin, seed);
            }
            }
        data = "1";
    }
}

std::string get_data() {
    std::cout << "Введите путь к файлу\n>> ";
    std::string filepath;
    std::cin >> filepath;
    std::string temp, data;
    if (filepath == "-m") {
        std::cin.ignore();
        std::cout << "\nВведите текст вручную\n>> ";
        getline(std::cin, data);
        return data;
    }
    std::ifstream in(filepath);
    if (!in.is_open()) {
        std::cout << "Файл не был открыть (неверный путь)!\n";
        system("pause");
        return std::string();
    }
    while (getline(in, temp)) {
        data += temp;
    }
    in.close();
    return data;
}

void save(std::string data) {
    std::cout << "Сохранить полученный текст в файл out.txt? (Y/N)\n>> ";
    char ch;
    std::cin >> ch;
    if (std::toupper(ch) == 'Y') {
        std::ofstream out("out.txt");
        out << data;
        out.close();
    }
}