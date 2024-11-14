#pragma once

#include <vector>
#include <stdexcept>

class LFSR {
public:
    LFSR() : last_generated(181) {}

    std::vector<std::bitset<8>> generate(uint quantity) {
        std::vector<std::bitset<8>> gen(quantity);
        for (uint i = 0; i < quantity; i++) {
            gen[i] = generate();
        }
        return gen;
    }

    bool generate() {
        std::bitset<8> res(0);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                res[i] = res[i] ^ (matrix[i][j] & last_generated[j]);
            }
        }

        last_generated = res;
        return last_generated[0];
    }

private:
    std::bitset<8> last_generated;
    std::vector<std::vector<bool>> matrix =
    { { 0, 1, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 1, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 1, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 1 },
      { 1, 0, 0, 1, 1, 1, 0, 1 } };
};