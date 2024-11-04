#include "DES.h"

// Encoding by DES ECB mode
std::string DES::ECB::encode(std::string data, std::string key) {
	data.size() % 2 == 1 ? data += "x" : data += "";
	std::vector<uint8_t> keys = Key::generate_keys(key);

	std::string result;
	for (size_t i = 0; i < data.size(); i += 2) {
		std::string block = data.substr(i, 2);

		for (uint8_t j = 0; j < 7; j++) {
			block = Feistel::round(block, keys[j]);
		}

		block = Feistel::last_round(block, keys[7]);
		result += block;
	}
	return result;
}

// Decoding by DES ECB mode
std::string DES::ECB::decode(std::string data, std::string key) {
	data.size() % 2 == 1 ? data += "x" : data += "";
	std::vector<uint8_t> keys = Key::generate_keys(key);
	std::reverse(keys.begin(), keys.end());

	std::string result;
	for (size_t i = 0; i < data.size(); i += 2) {
		std::string block = data.substr(i, 2);

		for (uint8_t j = 0; j < 7; j++) {
			block = Feistel::round(block, keys[j]);
		}

		block = Feistel::last_round(block, keys[7]);
		result += block;
	}
	return result;
}