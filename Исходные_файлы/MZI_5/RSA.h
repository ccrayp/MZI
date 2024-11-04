#pragma once

#include <cmath>
#include <limits>
#include <vector>
#include <string>

class RSA {
public:
	// Constructor of RSA class
	RSA(uint32_t public_key, uint32_t modulo) : public_key(public_key), modulo(modulo) {
		this->secret_key = get_secret_key();
	} 

	std::vector<uint32_t> send(std::string message);

	std::string receive(std::vector<uint32_t> message, RSA &sender);

	// Encode a given message by RSA algorithm
	uint32_t send(uint32_t message, RSA& B);

	// Decode a given ciphered message, then compare the original and encrypted messages, if they are equal return true, else return false
	uint32_t receive(uint32_t message);

private:
	// public_key
	uint32_t public_key;

	// secret key
	uint32_t secret_key;

	// Modulo n
	uint32_t modulo;

	// Find p and q for Euler
	std::pair<uint32_t, uint32_t> factorize(uint32_t modulo);

	// Euler function
	uint32_t Euler(uint32_t p, uint32_t q);

	// Solve a Diophantine equation, returns vector of coefficient
	std::vector<uint32_t> Diophantine(uint32_t public_key, uint32_t modulo);

	// Find a sercret key by a given public key and Euler function with modulo
	uint32_t get_secret_key();

	// Raise to a given degree by modulo
	uint32_t degree(uint32_t value, uint32_t degree, uint32_t modulo);
};
