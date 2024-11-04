#include <fstream>
#include <iostream>
#include <Windows.h>

#include "RSA.h"
#include "Diffie_Hellman.h"

void Diffie_Hellman_menu();
void RSA_menu();
void cipher();
void EDS();
void change();
void test();
std::string get_data();

uint32_t first_public_key = 17;
uint32_t second_public_key = 18;
uint32_t modulo = 29;
uint32_t modulo_A = 667;
uint32_t modulo_B = 377;
uint32_t e_A = 65;
uint32_t e_B = 55;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char choice = 0;
    while (choice != '3') {
        system("cls");
        std::cout << "1. Диффи-Хеллман\n2. RSA\n3. Выход\n>> ";
        std::cin >> choice;
        std::cin.ignore();
        system("cls");
        switch (choice) {
        case '1': Diffie_Hellman_menu(); break;
        case '2': RSA_menu(); break;
        }
    }
    return 0;
}

void Diffie_Hellman_menu() {
    system("cls");
    char choice = 0;
    while (choice != '3') {
        system("cls");
        std::cout << "1. Получить общий секретный ключ\n2. Изменить параметры\n3. Выход\n>> ";
        std::cin >> choice;
        std::cin.ignore();
        system("cls");
        switch (choice) {
        case '1': {
            std::cout << "Общий секретный ключ: " << Diffie_Hellman::find_common_key(first_public_key, second_public_key, modulo) << std::endl;
            system("pause");
        }break;
        case '2': {
            std::cout << "Открытый ключ первого абонента: " << first_public_key << "\nВведите новое значение: ";
            std::cin >> first_public_key;
            std::cout << "\nОткрытый ключ второго абонента: " << second_public_key << "\nВведите новое значение: ";
            std::cin >> second_public_key;
            std::cout << "\nМодуль: " << modulo << "\nВведите новое значение: ";
            std::cin >> modulo;
            system("pause");
        } break;
        }
    }
}

void RSA_menu() {
    char choice = 0;
    while (choice != '5') {
        system("cls");
        std::cout << "1. Шифрование при помощи RSA\n2. Цифровая подпись\n3. Изменить параметра\n4. Тест\n5. Выход\n>> ";
        std::cin >> choice;
        std::cin.ignore();
        system("cls");
        switch (choice) {
        case '1': cipher(); break;
        case '2': EDS(); break;
        case '3': change(); break;
        case '4': test(); break;
        }
    }
}

void cipher() {
    std::string message = get_data();
    if (message == "")
        return;
    std::ofstream out_original("original.dat", std::ios::binary);
    for (auto it : message) {
        out_original.write(reinterpret_cast<const char*>(&it), sizeof(it));
    }
    out_original.close();
    RSA A(e_A, modulo_A);
    RSA B(e_B, modulo_B);
    std::vector<uint32_t> encrypted = A.send(message);
    std::ofstream out("sended.dat", std::ios::binary);
    std::cout << "\nОтправленные данные (в виде десятичных чисел):\n";
    for (size_t i = 0; i < encrypted.size(); i++) {
        if (i % 10 == 0 && i != 0)
            std::cout << "\n";
        out.write(reinterpret_cast<const char*>(&encrypted[i]), sizeof(uint32_t));
        std::cout << encrypted[i] << " ";
    }
    std::cout << std::endl;
    out.close();
    std::cout << "\033[32m\nСообщение было отправлено\033[0m\n\n";
    system("pause");
    char temp = 0;
    std::string original = "";
    std::ifstream in_original("original.dat", std::ios::binary);
    while (in_original.read(&temp, sizeof(temp))) {
        original += temp;
    }
    in_original.close();
    uint32_t temp_int = 0;
    std::vector<uint32_t> sended;
    std::ifstream in("sended.dat", std::ios::binary);
    while (in.read(reinterpret_cast<char*>(&temp_int), sizeof(temp_int))) {
        sended.push_back(temp_int);
    }
    std::string received = B.receive(sended, A);
    std::cout << "\nАбонент B получил сообщение:\n" << received << std::endl << std::endl;
    system("pause");
}

void EDS() {
    std::string message = get_data();
    if (message == "")
        return;
    std::ofstream out_original("original.dat", std::ios::binary);
    for (auto it : message) {
        out_original.write(reinterpret_cast<const char*>(&it), sizeof(it));
    }
    out_original.close();
    RSA A(e_A, modulo_A);
    RSA B(e_B, modulo_B);
    std::vector<uint32_t> encrypted = A.send(message);
    std::ofstream out("sended.dat", std::ios::binary);
    std::cout << "\nОтправленные данные (в виде десятичных чисел):\n";
    for (size_t i = 0; i < encrypted.size(); i++) {
        if (i % 10 == 0 && i != 0)
            std::cout << "\n";
        out.write(reinterpret_cast<const char*>(&encrypted[i]), sizeof(uint32_t));
        std::cout << encrypted[i] << " ";
    }
    std::cout << std::endl;
    out.close();
    std::cout << "\033[32m\nСообщение было отправлено\033[0m\n\n";
    system("pause");
    char temp = 0;
    std::string original = "";
    std::ifstream in_original("original.dat", std::ios::binary);
    if (!in_original.is_open()) {
        std::cout << "\033[31mСообщение не было отправено\033[0m\n";
        return;
    }
    while (in_original.read(&temp, sizeof(temp))) {
        original += temp;
    }
    in_original.close();
    uint32_t temp_int = 0;
    std::vector<uint32_t> sended;
    std::ifstream in("sended.dat", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "\033[31mСообщение не было отправено\033[0m\n";
        return;
    }
    while (in.read(reinterpret_cast<char*>(&temp_int), sizeof(temp_int))) {
        sended.push_back(temp_int);
    }
    std::string received = B.receive(sended, A);
    if (original == received)
        std::cout << "\n\033[32mАбонент B получил верифицированное сообщение:\n\033[0m";
    else
        std::cout << "\n\033[31mАбонент B получил неверифицированное сообщение:\n\033[0m";
    std::cout << received << std::endl << std::endl;
    system("pause");
}

void change() {
    char choice = 0;
    while (choice != '5') {
        system("cls");
        std::cout << "1. Изменить e абонента A\n2. Изменить n абонента A\n3. Изменить e абонента B\n4. Изменить n абонента B\n5. Выход\n>> ";
        std::cin >> choice;
        system("cls");
        switch (choice) {
        case '1': {
            std::cout << "Текущее значение e абонента A: " << e_A << "\nВедите новое значение: ";
            std::cin >> e_A;
        } break;
        case '2': {
            std::cout << "Текущее значение n абонента A: " << modulo_A << "\nВедите новое значение: ";
            std::cin >> modulo_A;
        } break;
        case '3': {
            std::cout << "Текущее значение e абонента B: " << e_B << "\nВедите новое значение: ";
            std::cin >> e_B;
        } break;
        case '4': {
            std::cout << "Текущее значение n абонента B: " << modulo_B << "\nВедите новое значение: ";
            std::cin >> modulo_B;
        } break;
        }
    }
}

void test() {
    RSA A(e_A, modulo_A);
    RSA B(e_B, modulo_B);

    std::cout << "Номер символа ASCII -> Зашифрованный символ -> Расшифрованный символ\n";
    for (size_t i = 0; i < 256; i++) {
        uint32_t en = A.send(i, B);
        uint32_t dec = B.receive(en);
        if (dec != i)
            std::cout << "\033[31m";
        else
            std::cout << "\033[32m";
        std::cout << i << " -> " << en << " -> " << dec << "\033[0m" << "\n";
    }

    std::string original = "Hello, World!";
    std::vector<uint32_t> encrypted = A.send(original);
    std::string decrypted = B.receive(encrypted, A);
    std::cout << "\nПолученное сообщение: " << decrypted;
    if (original == decrypted)
        std::cout << "\n\033[32mАбонент B получил верифицированное сообщение\033[0m\n";
    else
        std::cout << "\n\033[31mАбонент B получил неверифицированное сообщение\033[0m\n";

    std::cout << std::endl;
    system("pause");
}

std::string get_data() {
    std::string data = "";
    std::cout << "Введите текст вручную\n>> ";
    getline(std::cin, data);
    return data;
}