#include "DES.h"

// Encoding by DES OFB mode
std::string DES::OFB::encode(std::string data, std::string key, std::string IV) {
    data.size() % 2 == 1 ? data += "x" : data += "";
    std::vector<uint8_t> keys = Key::generate_keys(key);
    std::string result, output = IV;

    for (size_t i = 0; i < data.size(); i += 2) {
        for (uint8_t j = 0; j < 7; j++) {
            output = Feistel::round(output, keys[j]);
        }
        output = Feistel::last_round(output, keys[7]);

        std::string block = data.substr(i, 2);
        for (size_t j = 0; j < block.size(); j++) {
            block[j] ^= output[j];
        }
        result += block;
    }
    return result;
}

// Decoding by DES OFB mode
std::string DES::OFB::decode(std::string data, std::string key, std::string IV) {
    return encode(data, key, IV);
}