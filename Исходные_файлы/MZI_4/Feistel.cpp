#include "DES.h"

// Round of Feistel net
std::string DES::Feistel::round(std::string data, uint8_t key) {
	uint8_t a = (uint8_t)data[0];
	uint8_t b = (uint8_t)data[1];

	uint8_t temp = b;
	b = F(b, key) ^ a;
	a = temp;

	data[0] = (char)a;
	data[1] = (char)b;
	return data;
}

// Last round of Feistel net
std::string DES::Feistel::last_round(std::string data, uint8_t key) {
	uint8_t a = (uint8_t)data[0];
	uint8_t b = (uint8_t)data[1];

	uint8_t temp = b;
	b = F(b, key) ^ a;
	a = temp;

	data[0] = (char)b;
	data[1] = (char)a;
	return data;
}

// Crypto function of Feistel net
uint8_t DES::Feistel::F(uint8_t byte, uint8_t key) {
	uint8_t res = (byte + key) % 256;
	res = (res << 1) | (res >> (8 - 1));
	return res;
}