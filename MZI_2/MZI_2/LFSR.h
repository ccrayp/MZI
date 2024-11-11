#pragma once

#include <vector>

class LFSR {
public:

	LFSR() {}

	LFSR(uint seed) : seed(seed) {}

	LFSR(uint seed, ...) {}

	uint generate() {

		return 0;
	}

	std::vector<uint> generate(uint quantity) {

		return std::vector<uint>();
	}

	uint set_seed(uint seed) {
		this->seed = seed;
		last_generated = seed;
		return this->seed;
	}

private:
	uint seed = 0;
	uint last_generated = seed;
};