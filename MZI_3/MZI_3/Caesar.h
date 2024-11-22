#pragma once

#include <Windows.h>
#include <fstream>
#include "LFSR.h"

typedef unsigned char symbol;

class Caesar {
public:

	std::string encode(std::string data, unsigned int key) {
		std::string result;
		for (symbol c : data) {
			result += encode(c, key);
		}
		return result;
	}

	std::string decode(std::string data, unsigned int key) {
		std::string result;
		for (symbol c : data) {
			result += decode(c, key);
		}
		return result;
	}

	std::string encode_text_key(std::string data, ...) {
		return std::string();
	}

	std::string decode_text_key(std::string data, ...) {
		return std::string();
	}

	std::string encode_LFSR(std::string data, unsigned int seed) {
		LFSR LFSR(seed);
		std::string result;
		for (int i = 0; i < data.size(); i++) {
			result += encode((symbol)data[i], LFSR.generate().to_ulong());
		}
		return result;
	}

	std::string decode_LFSR(std::string data, unsigned int seed) {
		LFSR LFSR(seed);
		std::string result;
		for (char c : data) {
			result += decode(c, LFSR.generate().to_ulong());
		}
		return result;
	}

private:
	unsigned char encode(unsigned char c, long long int offset) {
		if (c >= 'a' && c <= 'z') {
			c += offset;
			c %= 'z' + 1;
			if (c < 'a')
				c += 'z' - 'a';
		}
		else if (c >= 'A' && c <= 'Z') {
			c += offset;
			c %= 'Z' + 1;
			if (c < 'A')
				c += 'Z' - 'A';
		} 
		else if (c >= 'à' && c <= 'ÿ') {
			c += offset;
			c %= 'ÿ' + 1;
			if (c < 'à')
				c += 'ÿ' - 'à';
		}
		else if (c >= 'À' && c <= 'ß') {
			c += offset;
			c %= 'ß' + 1;
			if (c < 'À')
				c += 'ß' - 'À';
		}

		/*c = (c + offset);
		if (c >= ' ' && c <= 255) {
			c %= 255 + 1;
			if (c < ' ') {
				c += 223;
			}
		}*/
		return c;
	}

	unsigned char decode(unsigned char c, long long int offset) {
		offset *= -1;
		if (c >= 'a' && c <= 'z') {
			c += offset;
			c %= 'z' + 1;
			if (c < 'a')
				c += 'a';
		}
		else if (c >= 'A' && c <= 'Z') {
			c += offset;
			c %= 'Z' + 1;
			if (c < 'A')
				c += 'A';
		}
		else if (c >= 'à' && c <= 'ÿ') {
			c += offset;
			c %= 'ÿ' + 1;
			if (c < 'à')
				c += 'à';
		}
		else if (c >= 'À' && c <= 'ß') {
			c += offset;
			c %= 'ß' + 1;
			if (c < 'À')
				c += 'À';
		}

		/*c = (c + offset);
		if (c >= ' ' && c <= 255) {
			c %= 255 + 1;
			if (c < ' ') {
				c += ' ';
			}
		}*/
		return c;
	}
};