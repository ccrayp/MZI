#include "RSA.h"

// Encode a given message by RSA algorithm
std::vector<uint32_t> RSA::send(std::string message) {
	std::vector<uint32_t> result;
	for (size_t i = 0; i < message.size(); i++) {
		uint32_t sym = static_cast<uint8_t>(message[i]);
		result.push_back(degree(sym, this->secret_key, this->modulo));
	}
	return result;
}

// Decode a given ciphered message, then compare the original and sended messages, if they are equal return true, else return false
std::string RSA::receive(std::vector<uint32_t> message, RSA &sender) {
	std::string result = "";
	for (size_t i = 0; i < message.size(); i++) {
		result += degree(static_cast<uint32_t>(message[i]), sender.public_key, sender.modulo);
	}
	return result;
}

// Encode a given message by RSA algorithm
uint32_t RSA::send(uint32_t message, RSA& B) {
	return degree(message, B.public_key, B.modulo);
}

// Decode a given ciphered message, then compare the original and sended messages, if they are equal return true, else return false
uint32_t RSA::receive(uint32_t message) {
	return degree(message, this->secret_key, this->modulo);
}

// Find p and q for Euler
std::pair<uint32_t, uint32_t> RSA::factorize(uint32_t modulo) {
	for (size_t i = 2; i < sqrt(modulo); i++) {
		if (modulo % i == 0)
			return { i, modulo / i };
	}
	return std::pair<uint32_t, uint32_t>();
}

// Euler function
uint32_t RSA::Euler(uint32_t p, uint32_t q) {
	return (p - 1) * (q - 1);
}

// Solve a Diophantine equation
std::vector<uint32_t> RSA::Diophantine(uint32_t public_key, uint32_t modulo) {
	std::vector<uint32_t> coefficient;
	while (modulo != 0) {
		coefficient.push_back(public_key / modulo);
		uint32_t temp = public_key;
		public_key = modulo;
		modulo = temp % modulo;
	}

	return coefficient;
}

// Find a sercret key by a given public key and modulo
uint32_t RSA::get_secret_key() {
	std::pair<uint32_t, uint32_t> pq = factorize(this->modulo);
	uint32_t modulo = Euler(pq.first, pq.second);
	std::vector<uint32_t> coefficient = Diophantine(this->public_key, modulo);
	std::vector<uint32_t> temp = {1, 0};

	long long result = 0, prev = 1;
	uint32_t temp_res;
	for (size_t i = 0; i < coefficient.size() - 1; i++) {
		if (i < 2)
			prev = temp[i];
		else
			prev = temp_res;
		temp_res = result;

		result = (coefficient[i] * result) + prev;
	}

	if (coefficient.size() % 2 != 0) {
		result *= -1;
		while (result < 0)
			result += modulo;
	}
	else
		result %= modulo;

	return result;
}

// Raise to a given degree by modulo
uint32_t RSA::degree(uint32_t value, uint32_t degree, uint32_t modulo) {
	uint32_t result = 1;
	value %= modulo;
	for (size_t i = 0; i < degree; i++) {
		result = (result * value) % modulo;
	}
	return result;
}