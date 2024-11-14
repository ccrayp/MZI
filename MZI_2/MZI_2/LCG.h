#pragma once

#include <vector>
#include <limits>
#include <stdexcept>

#define MAX std::numeric_limits<uint>::max()
typedef unsigned int uint;

class LCG {
public:
    LCG() {}

    bool generate() {
        last_generated = (a * last_generated + c) % m;
        return std::bitset<1>(last_generated)[0];
    }

private:
    bool is_coprime(uint a, uint b) {
        while (b != 0) {
            uint temp = b;
            b = a % b;
            a = temp;
        }
        return a == 1;
    }

    uint seed = 0;
    uint m = 2147483647; // Число Мерсена 2^31 - 1 (2^p - 1)
    uint a = 1664525;
    uint c = 1013904223;
    uint last_generated = seed % m;
};