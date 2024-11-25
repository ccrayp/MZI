#pragma once

#include <bitset>
#include <vector>

class LFSR {
public:
    LFSR() : last_generated(85) {}
    LFSR(unsigned char seed) : last_generated(seed) {}

    std::bitset<8> generate() {
        std::bitset<8> res;
        for (int i = 0; i < 8; i++) {
            bool feedback = last_generated[0];
            for (int j = 1; j < 8; j++) {
                feedback ^= (matrix[i][j] ? last_generated[j] : 0);
            }
            res[i] = feedback;
        }
        last_generated = res;
        return last_generated;
    }

private:
    std::bitset<8> last_generated;
    std::vector<std::vector<bool>> matrix = {
        {0, 0, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0}
    };
};