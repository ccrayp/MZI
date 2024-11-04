#include "DES.h"

// Encoding by DES CFC mode
std::string DES::CFB::encode(std::string data, std::string key, std::string IV) {
	data.size() % 2 == 1 ? data += "x" : data += "";
	std::vector<uint8_t> keys = Key::generate_keys(key);
	std::string result, feedback = IV;

	for (size_t i = 0; i < data.size(); i += 2) {
		for (uint8_t j = 0; j < 7; j++) {
			feedback = Feistel::round(feedback, keys[j]);
		}
		feedback = Feistel::last_round(feedback, keys[7]);

		std::string block = data.substr(i, 2);
		for (size_t j = 0; j < block.size(); j++) {
			block[j] ^= feedback[j];
		}
		result += block;
	}
	return result;
}

// Decoding by DES CFC mode
std::string DES::CFB::decode(std::string data, std::string key, std::string IV) {
	return encode(data, key, IV);
}