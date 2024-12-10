#pragma once

#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

class DES {
public:

	// ECB - Electronic Coding Book 
	class ECB {
	public:
		static std::string encode(std::string data, std::string key);
		static std::string decode(std::string data, std::string key);
	};

	// CBC - Cipher Block Chaining
	class CBC {
	public:
		static std::string encode(std::string data, std::string key, std::string IV);
		static std::string decode(std::string data, std::string key, std::string IV);
	};

	// CFB - Cipher Feed Back
	class CFB {
	public:
		static std::string encode(std::string data, std::string key, std::string IV);
		static std::string decode(std::string data, std::string key, std::string IV);
	};

	// OFB - Output Feed Back
	class OFB {
	public:
		static std::string encode(std::string data, std::string key, std::string IV);
		static std::string decode(std::string data, std::string key, std::string IV);
	};

	class Feistel {
	public:
		static std::string round(std::string data, uint8_t key);
		static std::string last_round(std::string data, uint8_t key);
	private:
		static uint8_t F(uint8_t byte, uint8_t key);
	};

private:
	class Key {
	public:
		static std::vector<uint8_t> generate_keys(std::string key) {
			std::string hash = std::bitset<64>(std::hash<std::string>()(key)).to_string();
			std::vector<uint8_t> keys;
			while (hash.size()) {
				keys.push_back(std::bitset<8>(hash.substr(0, 8)).to_ulong());
				hash.erase(0, 8);
			}
			return keys;
		}
	};
};
