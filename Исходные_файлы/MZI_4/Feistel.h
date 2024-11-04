#pragma once

#include <bitset>
#include <vector>
#include <string>
#include <algorithm>

#include "entropy.h"

class Feistel {
public:

	void test(std::string data, std::string key, float target_entropy) {
		Key Key(key);

		if (data.size() % 2 == 1)
			data += 'x';

		size_t counter = 0;
		std::cout << "\n\nИсходный текст. Энтропия: " << entropy(data);
		while(entropy(data) < target_entropy) {
			if (counter % 1000 == 0 && counter != 0) {
				std::cout << "\n\nПродолжить вычисления? (y/n)\n>> ";
				char ch = 0;
				std::cin >> ch;
				if (std::tolower(ch) == 'n')
					break;
			}
			data = F_round(data, Key.generate());
			std::cout << "\nRound #" << counter + 1 << " Энтропия: " << entropy(data);
			counter++;
		}
		std::cout << "\n";
	}

	std::vector<std::string> encode(std::string data, std::string key) {
		std::vector<uint8_t> keys;
		Key Key(key);
		for (int i = 0; i < 8; i++) {
			keys.push_back(Key.generate());
		}
		return cipher(data, keys);
	}

	std::vector<std::string> decode(std::string data, std::string key) {
		std::vector<uint8_t> keys;
		Key Key(key);
		for (int i = 0; i < 8; i++) {
			keys.push_back(Key.generate());
		}
		std::reverse(keys.begin(), keys.end());
		return cipher(data, keys);
	}

private:
	std::vector<std::string> cipher(std::string data, std::vector<unsigned char> keys) {
		std::vector<std::string> result;
		if (data.size() % 2 == 1)
			data += 'x';
		for(int i = 0; i < 7; i++) {
			result.push_back(F_round(data, keys[i]));
			data = result.back();
		}
		result.push_back(last_F_round(data, keys[7]));
		data = result.back();
		return result;
	}

	std::string F_round(std::string data, unsigned char key) {
		for (size_t i = 0; i < data.size(); i += 2) {
			unsigned char a = (unsigned char)data[i];
			unsigned char b = (unsigned char)data[i + 1];

			unsigned char temp = b;
			b = F(b, key) ^ a;
			a = temp;

			data[i] = (char)a;
			data[i + 1] = (char)b;
		}
		return data;
	}

	std::string last_F_round(std::string data, unsigned char key) {
		for (size_t i = 0; i < data.size(); i += 2) {
			unsigned char a = (unsigned char)data[i];
			unsigned char b = (unsigned char)data[i + 1];

			unsigned char temp = b;
			b = F(b, key) ^ a;
			a = temp;

			data[i] = (char)b;
			data[i + 1] = (char)a;
		}
		return data;
	}

	unsigned char F(int byte, int key) {
		unsigned char res = (byte + key) % 256; // Наложение раундового ключа по модулю алфавита
		res = (res << 1) | (res >> (8 - 1)); // Циклический сдвиг
		return res;
	}

	class Key {
	public:
		Key(std::string str) : last_generated(0) {
			if (str.size() % 2 != 0)
				str += 'x';
			this->str = str;
		}

		uint8_t generate() {
			uint8_t key = 0;
			for (int j = 0; j < str.size(); j += 2) {
				std::swap(str[j], str[j + 1]);
			}

			for (int j = 0; j < str.size(); j += 2) {
				key = (key + (unsigned char)str[j]) % 256;
			}

			str = str.substr(1) + (char)key;
			std::reverse(str.begin(), str.end());

			last_generated = key;
			return last_generated;
		}

	private:
		std::string str;
		uint8_t last_generated;
	};
};