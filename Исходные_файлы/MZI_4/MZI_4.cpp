#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

#include "DES.h"
#include "Feistel.h"

const std::string outFile = "data";
const std::string reset = "\033[0m";
const std::string red = "\033[31m";
const std::string green = "\033[32m";

std::string ECB_key = "Пустой колос голову кверху носит";
std::string CBC_key = "Пустой колос голову кверху носит";
std::string CFB_key = "Пустой колос голову кверху носит";
std::string OFB_key = "Пустой колос голову кверху носит";
std::string feistel_key = "Пустой колос голову кверху носит";

std::string CBC_IV = "аб";
std::string CFB_IV = "аб";
std::string OFB_IV = "аб";

void DES_menu();
void ECB_menu();
void CBC_menu();
void CFB_menu();
void OFB_menu();
void feistel_menu();

std::string cipher(char mode, std::string data);
std::string get_data();
void save(std::string data);

void test_Feistel(std::string data, std::string key, float entropy);
void test_DES();

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char choice = 0;
    while (choice != '3') {
        system("cls");
        std::cout << "1. Сеть Фейстеля\n2. DES (4 режима)\n3. Выход\n>> ";
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case '1': feistel_menu(); break;
        case '2': DES_menu(); break;
        }
    }
    return 0;
}

void DES_menu() {
    char choice = 0;
    while (choice != '6') {
        system("cls");
        std::cout << "1. ECB - Electronic Coding Book (Электронная книга кодирования)\n2. CBC - Cipher Block Chaining (Цепочка блоков шифрования)\n3. CFB - Cipher FeedBack (Обратная связь по шифру)\n4. OFB - Output FeedBack (Обратная связь по выходу)\n5. Проверка корректности работы режимов\n6. Выход\n>> ";
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case '1': ECB_menu(); break;
        case '2': CBC_menu(); break;
        case '3': CFB_menu(); break;
        case '4': OFB_menu(); break;
        case '5': test_DES(); break;
        }
    }
}

void feistel_menu() {
    char choice = 0;
    while (choice != '6') {
        system("cls");
        std::cout << "1. Зашифровать\n2. Расшифровать\n3. Изменить ключ\n4. Вывести текущий ключ\n5. Достижение задаваемой энтропии\n6. Выход\n>> ";
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case '1': {
            std::string data = get_data();
            if (data == "")
                break;
            std::cout << red << "\nИсходный текст:\n" << reset << data;
            std::string result = cipher(0, data);
            std::cout << green << "\n\nЗашифрованный текст:\n" << reset << result << std::endl << std::endl;
            save(result);
            break;
        }
        case '2': {
            std::string data = get_data();
            if (data == "")
                break;
            std::cout << red << "\nИсходный текст:\n" << reset << data;
            std::string result = cipher(1, data);
            std::cout << green << "\n\nРасшифрованный текст:\n" << reset << result << std::endl << std::endl;
            save(result);
            break;
        }
        case '3': {
            std::cout << "Текущий ключ: " << feistel_key << "\n\nВведине новый ключ\n>> ";
            std::cin.ignore();
            getline(std::cin, feistel_key);
            break;
        }
        case '4': {
            std::cout << "Текущий ключ: " << feistel_key << "\n\n";
            system("pause");
            break;
        }
        case '5': {
            std::string data = get_data();
            if (data == "")
                break;
            float entropy = 0.0;
            std::cout << "\nВведите целевую энтропию\n>> ";
            std::cin >> entropy;
            std::cout << red << "\nИсходный текст:\n" << reset << data;
            test_Feistel(data, feistel_key, entropy);
            break;
        }
        }
    }
}

void ECB_menu() {
    char choice = 0;
    while (choice != '5') {
        system("cls");
        std::cout << "1. Зашифровать\n2. Расшифровать\n3. Изменить ключ\n4. Вывести текущий ключ\n5. Выход\n>> ";
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case '1': {
            std::string data = get_data();
            if (data == "")
                break;
            std::cout << red << "\nИсходный текст:\n" << reset << data;
            std::string result = DES::ECB::encode(data, ECB_key);
            std::cout << green << "\n\nЗашифрованный текст:\n" << reset << result << std::endl << std::endl;
            save(result);
            break;
        }
        case '2': {
            std::string data = get_data();
            if (data == "")
                break;
            std::cout << red << "\nИсходный текст:\n" << reset << data;
            std::string result = DES::ECB::decode(data, ECB_key);
            std::cout << green << "\n\nРасшифрованный текст:\n" << reset << result << std::endl << std::endl;
            save(result);
            break;
        }
        case '3': {
            std::cout << "Текущий ключ: " << ECB_key << "\n\nВведине новый ключ\n>> ";
            std::cin.ignore();
            getline(std::cin, ECB_key);
            break;
        }
        case '4': {
            std::cout << "Текущий ключ: " << ECB_key << "\n\n";
            system("pause");
            break;
        }
        }
    }
}

void CBC_menu() {
    char choice = 0;
    while (choice != '7') {
        system("cls");
        std::cout << "1. Зашифровать\n2. Расшифровать\n3. Изменить ключ\n4. Вывести текущий ключ\n5. Изменить вектор инициализации\n6. Вывести вектор инициализация\n7. Выход\n>> ";
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case '1': {
            std::string data = get_data();
            if (data == "")
                break;
            std::cout << red << "\nИсходный текст:\n" << reset << data;
            std::string result = DES::CBC::encode(data, CBC_key, "ab");
            std::cout << green << "\n\nЗашифрованный текст:\n" << reset << result << std::endl << std::endl;
            save(result);
            break;
        }
        case '2': {
            std::string data = get_data();
            if (data == "")
                break;
            std::cout << red << "\nИсходный текст:\n" << reset << data;
            std::string result = DES::CBC::decode(data, CBC_key, "ab");
            std::cout << green << "\n\nРасшифрованный текст:\n" << reset << result << std::endl << std::endl;
            save(result);
            break;
        }
        case '3': {
            std::cout << "Текущий ключ: " << CBC_key << "\n\nВведине новый ключ\n>> ";
            std::cin.ignore();
            getline(std::cin, CBC_key);
            break;
        }
        case '4': {
            std::cout << "Текущий ключ: " << CBC_key << "\n\n";
            system("pause");
            break;
        }
        case '5': {
            std::cout << "Текущий вектор инициализации: " << CBC_IV << "\n\nВведите новый вектор инициализации\n>> ";
            std::cin.ignore();
            getline(std::cin, CBC_IV);
            break;
        }
        case '6': {
            std::cout << "Текущий вектор инициализации: " << CBC_IV << "\n\n";
            system("pause");
            break;
        }
        }
    }
}

void CFB_menu() {
    char choice = 0;
    while (choice != '7') {
        system("cls");
        std::cout << "1. Зашифровать\n2. Расшифровать\n3. Изменить ключ\n4. Вывести текущий ключ\n5. Изменить вектор инициализации\n6. Вывести вектор инициализация\n7. Выход\n>> ";
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case '1': {
            std::string data = get_data();
            if (data == "")
                break;
            std::cout << red << "\nИсходный текст:\n" << reset << data;
            std::string result = DES::CFB::encode(data, CFB_key, "ab");
            std::cout << green << "\n\nЗашифрованный текст:\n" << reset << result << std::endl << std::endl;
            save(result);
            break;
        }
        case '2': {
            std::string data = get_data();
            if (data == "")
                break;
            std::cout << red << "\nИсходный текст:\n" << reset << data;
            std::string result = DES::CFB::decode(data, CFB_key, "ab");
            std::cout << green << "\n\nРасшифрованный текст:\n" << reset << result << std::endl << std::endl;
            save(result);
            break;
        }
        case '3': {
            std::cout << "Текущий ключ: " << CFB_key << "\n\nВведине новый ключ\n>> ";
            std::cin.ignore();
            getline(std::cin, CFB_key);
            break;
        }
        case '4': {
            std::cout << "Текущий ключ: " << CFB_key << "\n\n";
            system("pause");
            break;
        }
        case '5': {
            std::cout << "Текущий вектор инициализации: " << CBC_IV << "\n\nВведите новый вектор инициализации\n>> ";
            std::cin.ignore();
            getline(std::cin, CBC_IV);
            break;
        }
        case '6': {
            std::cout << "Текущий вектор инициализации: " << CBC_IV << "\n\n";
            system("pause");
            break;
        }
        }
    }
}

void OFB_menu() {
    char choice = 0;
    while (choice != '7') {
        system("cls");
        std::cout << "1. Зашифровать\n2. Расшифровать\n3. Изменить ключ\n4. Вывести текущий ключ\n5. Изменить вектор инициализации\n6. Вывести вектор инициализация\n7. Выход\n>> ";
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case '1': {
            std::string data = get_data();
            if (data == "")
                break;
            std::cout << red << "\nИсходный текст:\n" << reset << data;
            std::string result = DES::OFB::encode(data, OFB_key, "ab");
            std::cout << green << "\n\nЗашифрованный текст:\n" << reset << result << std::endl << std::endl;
            save(result);
            break;
        }
        case '2': {
            std::string data = get_data();
            if (data == "")
                break;
            std::cout << red << "\nИсходный текст:\n" << reset << data;
            std::string result = DES::OFB::decode(data, OFB_key, "ab");
            std::cout << green << "\n\nРасшифрованный текст:\n" << reset << result << std::endl << std::endl;
            save(result);
            break;
        }
        case '3': {
            std::cout << "Текущий ключ: " << OFB_key << "\n\nВведине новый ключ\n>> ";
            std::cin.ignore();
            getline(std::cin, OFB_key);
            break;
        }
        case '4': {
            std::cout << "Текущий ключ: " << OFB_key << "\n\n";
            system("pause");
            break;
        }
        case '5': {
            std::cout << "Текущий вектор инициализации: " << CBC_IV << "\n\nВведите новый вектор инициализации\n>> ";
            std::cin.ignore();
            getline(std::cin, CBC_IV);
            break;
        }
        case '6': {
            std::cout << "Текущий вектор инициализации: " << CBC_IV << "\n\n";
            system("pause");
            break;
        }
        }
    }
}

void test_Feistel(std::string data, std::string key, float entropy) {
    Feistel Feistel;
    Feistel.test(data, key, entropy);
    system("pause");
}

std::string cipher(char mode, std::string data) {
    Feistel Feistel;
    std::vector<std::string> result_v;

    if(!mode)
        result_v = Feistel.encode(data, feistel_key);
    else
        result_v = Feistel.decode(data, feistel_key);

    for (int i = 0; i < result_v.size(); i++) {
        std::ofstream out(outFile + "_" + std::to_string(i + 1) + "_round", std::ios::binary);
        for (char it : result_v[i]) {
            out.write(&it, sizeof(char));
        }
        out.close();
    }

    return result_v.back();
}

std::string get_data() {
    std::cout << "Введите путь к файлу\n>> ";
    std::string filepath;
    std::cin >> filepath;
    std::string data;
    if (filepath == "-m") {
        std::cin.ignore();
        std::cout << "\nВведите текст вручную\n>> ";
        getline(std::cin, data);
        return data;
    }
    std::ifstream in(filepath, std::ios::binary);
    if (!in.is_open()) {
        std::cout << red << "\nНе удалось открыть файл (неверный путь)!\n\n" << reset;
        system("pause");
        return std::string();
    }
    char temp = 0;
    while (in.read(&temp, sizeof(char))) {
        data += temp;
    }
    in.close();
    return data;
}

void save(std::string data) {
    std::cout << "Сохранить полученный текст в файл " << outFile << "? (Y/N, m для ручного выбора файла)\n>> ";
    char ch;
    std::cin >> ch;
    if (std::toupper(ch) == 'Y') {
        std::ofstream out(outFile, std::ios::binary);
        for (auto it : data) {
            out.write(&it, sizeof(char));
        }
        out.close();
        system("cls");
        std::cout << green << "Данные были успешно сохранены в " << outFile << "\n\n" << reset;
        system("pause");
    }
    else if (ch == 'm') {
        std::string filepath;
        std::cout << "\nВведите путь к файлу для сохранения\n>> ";
        std::cin.ignore();
        getline(std::cin, filepath);
        std::ofstream out(filepath, std::ios::binary);
        for (auto it : data) {
            out.write(&it, sizeof(char));
        }
        out.close();
        system("cls");
        std::cout << green << "Данные были успешно сохранены в " << filepath << "\n\n" << reset;
        system("pause");
    }
}

static void test_DES() {
    std::string key = ECB_key, iv = "аб";
    std::string temp = DES::ECB::encode("test", key);
    temp = DES::ECB::decode(temp, key);
    if (temp != "test")
        std::cout << "\033[31mECB. Тест провален\033[0m\n";
    else
        std::cout << "\033[32mECB. Тест пройден\033[0m\n";

    temp = DES::CBC::encode("test", key, iv);
    temp = DES::CBC::decode(temp, key, iv);
    if (temp != "test")
        std::cout << "\033[31mCBC. Тест провален\033[0m\n";
    else
        std::cout << "\033[32mCBC. Тест пройден\033[0m\n";

    temp = DES::CFB::encode("test", key, iv);
    temp = DES::CFB::decode(temp, key, iv);
    if (temp != "test")
        std::cout << "\033[31mCFB. Тест провален\033[0m\n";
    else
        std::cout << "\033[32mCFB. Тест пройден\033[0m\n";

    temp = DES::OFB::encode("test", key, iv);
    temp = DES::OFB::decode(temp, key, iv);
    if (temp != "test")
        std::cout << "\033[31mOFB. Тест провален\033[0m\n";
    else
        std::cout << "\033[32mOFB. Тест пройден\033[0m\n";
    std::cout << std::endl;
    system("pause");
}