#pragma once

#include <iostream>

class Diffie_Hellman {
public:
	// Find a common secret key for futher communication
	static uint32_t find_common_key(uint32_t first_abonent_secret_key, uint32_t second_abonent_secret_key, uint32_t public_element);

private:
	// Find a priminive element of finite field by a given public element (modulo of GF)
	static uint32_t find_primitive_element(uint32_t public_element);

	// Raise to a given degree by modulo
	static uint32_t degree(uint32_t value, uint32_t degree, uint32_t modulo);
};