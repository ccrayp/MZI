#pragma once

#include <limits>

typedef unsigned int uint;

class BBS {
public:

	BBS() {}

	BBS(uint seed) : seed(seed), last_generated((seed* seed) % M) {}

	BBS(uint seed, uint p, uint q) : seed(seed), p(p), q(q), last_generated(seed), M(p * q) {
		if (!is_coprime(seed, M))
			throw std::invalid_argument("x и M не взаимно простые");
		last_generated = (seed * seed) % M;
	}

	uint generate() {
		return last_generated = (last_generated * last_generated) % M;
	}

	std::vector<uint> generate(uint quantity) {
		std::vector<uint> generated(quantity);
		for (uint i = 0; i < quantity; i++) {
			generated[i] = generate();
		}
		return generated;
	}

	uint set_p(uint p, uint x) {
		if(!is_coprime(x, M))
			throw std::invalid_argument("x и M не взаимно простые");
		last_generated = x;
		return p;
	}

	uint set_q(uint q, uint x) {
		if (!is_coprime(x, M))
			throw std::invalid_argument("x и M не взаимно простые");
		last_generated = x;
		return q;
	}

private:
	bool is_coprime(uint a, uint b) {
		uint temp = 0;
		while (b != 0) {
			temp = b;
			b = a % b;
			a = temp;
		}

		return a == 1 ? true : false;
	}

	uint seed = 12345;
	uint p = 61;
	uint q = 53;
	uint M = p * q;
	uint last_generated = seed % M;
};