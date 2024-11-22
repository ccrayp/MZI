#pragma once

#include <bitset>
#include <string>

std::string init(char mode, std::string data) {
    std::vector<std::vector<bool>> grid = { { 0, 1, 0, 1, 0, 0, 1, 0 },
                                            { 0, 0, 0, 0, 1, 0, 0, 0 },
                                            { 1, 0, 1, 0, 0, 0, 1, 0 },
                                            { 0, 0, 0, 1, 0, 0, 0, 0 },
                                            { 0, 1, 0, 0, 0, 1, 0, 0 },
                                            { 1, 0, 0, 0, 1, 0, 0, 0 },
                                            { 0, 0, 1, 0, 0, 0, 1, 0 },
                                            { 0, 0, 0, 1, 0, 0, 0, 1 } };
    Cardano Cardano(grid, 16);
    switch (mode) {
    case 0: return Cardano.encode(data); break;
    case 1: return Cardano.decode(data); break;
    }
}

int bin_to_int(std::string seed) {
    std::bitset<8> b(seed);
    return b.to_ulong();
}