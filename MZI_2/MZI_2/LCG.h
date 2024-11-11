#pragma once

#include <vector>
#include <limits>
#include <stdexcept>

#define MAX std::numeric_limits<uint>::max()
typedef unsigned int uint;

class LCG {
public:
    LCG() {}

    LCG(uint seed) : seed(seed), last_generated(seed) {}

    LCG(uint seed, uint module, uint multiplier, uint increment) : seed(seed), m(module), a(multiplier), c(increment), last_generated(seed) {
        if (m < 2) {
            throw std::invalid_argument("Too little value of m");
        }
        if (a >= m || a <= 0) {
            throw std::invalid_argument("Incorrect value of a");
        }
        if (c >= m || c < 0) {
            throw std::invalid_argument("Incorrect value of c");
        }
        if (!is_coprime(c, m)) {
            throw std::invalid_argument("c and m are not coprime");
        }
        int b = a - 1;
        if (m % 4 == 0 && b % 4 != 0) {
            throw std::invalid_argument("Invalid parameters: m and a");
        }
    }

    uint generate() {
        last_generated = (a * last_generated + c) % m;
        return last_generated;
    }

    std::vector<uint> generate(uint quantity) {
        std::vector<uint> generated(quantity);
        for (uint i = 1; i < quantity; i++) {
            generated[i] = generate();
        }
        return generated;
    }

    uint set_seed(uint seed) {
        this->seed = seed;
        last_generated = seed;
        return this->seed;
    }

    uint set_module(uint module) {
        if (module < 2) {
            throw std::invalid_argument("Too little value of module");
        }
        m = module;
        last_generated = seed;
        return this->m;
    }

    uint set_multiplier(uint multiplier) {
        if (multiplier >= m || multiplier == MAX || (m % 4 == 0 && (multiplier - 1) % 4 != 0)) {
            throw std::invalid_argument("Invalid value of multiplier");
        }
        a = multiplier;
        last_generated = seed;
        return this->a;
    }

    uint set_increment(uint increment) {
        if (increment >= m || increment < 0) {
            throw std::invalid_argument("Incorrect value of c");
        }
        if (!is_coprime(increment, m)) {
            throw std::invalid_argument("c and m are not coprime");
        }
        c = increment;
        last_generated = seed;
        return this->c;
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
    uint m = 2147483647;
    uint a = 1664525;
    uint c = 1013904223;
    uint last_generated = seed % m;
};