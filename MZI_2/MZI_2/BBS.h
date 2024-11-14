#pragma once

#include <vector>
#include <limits>
#include <stdexcept>

class BBS {
public:
    BBS() : seed(255), p(3571), q(3559), M(p* q), last_generated((seed* seed) % M) {
        if (!is_coprime(M, seed))
            throw std::invalid_argument("M и seed не взаимнопростые\n");
    }

    bool generate() {
        last_generated = (last_generated * last_generated) % M;
        return std::bitset<1>(last_generated)[0];
    }

private:
    bool is_coprime(size_t a, size_t b) {
        while (b != 0) {
            size_t temp = b;
            b = a % b;
            a = temp;
        }
        return a == 1;
    }

    size_t seed;
    size_t p;
    size_t q;
    size_t M;
    size_t last_generated;
};