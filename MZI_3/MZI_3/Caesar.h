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

	std::string encode_text_key(std::string data, std::string key) {
		return std::string();
	}

	std::string decode_text_key(std::string data, std::string key) {
		return std::string();
	}

	std::string encode_LFSR(std::string data, unsigned int key) {
		LFSR LFSR(key);
		std::string result;
		for (symbol c : data) {
			result += encode(c, LFSR.generate().to_ulong());
		}
		return result;
	}

	std::string decode_LFSR(std::string data, unsigned int key) {
		LFSR LFSR(key);
		std::string result;
		for (symbol c : data) {
			result += decode(c, LFSR.generate().to_ulong());
		}
		return result;
	}

private:
	symbol encode(symbol c, long long int offset) {
		if (c >= 'a' && c <= 'z') {
			c = (c - 'a' + (offset % 26) + 26) % 26 + 'a';
		}
		else if (c >= 'A' && c <= 'Z') {
			c = (c - 'A' + (offset % 26) + 26) % 26 + 'A';
		}
		else if (c >= (symbol)'à' && c <= (symbol)'ÿ') {
			c = (c - (symbol)'à' + (offset % 32) + 32) % 32 + (symbol)'à';
		}
		else if (c >= (symbol)'À' && c <= (symbol)'ß') {
			c = (c - (symbol)'À' + (offset % 32) + 32) % 32 + (symbol)'À';
		}
		return c;
	}

	symbol decode(symbol c, long long int offset) {
		offset *= -1;
		if (c >= (symbol)'a' && c <= (symbol)'z') {
			c = (c - (symbol)'a' + (offset % 26) + 26) % 26 + (symbol)'a';
		}
		else if (c >= (symbol)'A' && c <= (symbol)'Z') {
			c = (c - (symbol)'A' + (offset % 26) + 26) % 26 + (symbol)'A';
		}
		else if (c >= (symbol)'à' && c <= (symbol)'ÿ') {
			c = (c - (symbol)'à' + (offset % 32) + 32) % 32 + (symbol)'à';
		}
		else if (c >= (symbol)'À' && c <= (symbol)'ß') {
			c = (c - (symbol)'À' + (offset % 32) + 32) % 32 + (symbol)'À';
		}
		return c;
	}

};