#include "Diffie_Hellman.h"

// Find a common secret key for futher communication
uint32_t Diffie_Hellman::find_common_key(uint32_t first_abonent_secret_key, uint32_t second_abonent_secret_key, uint32_t modulo) {
	uint32_t primitive_element = find_primitive_element(modulo);
	uint32_t first_abonent_public_key = degree(primitive_element, first_abonent_secret_key, modulo);
	uint32_t common_key = degree(first_abonent_public_key, second_abonent_secret_key, modulo);
	return common_key;
}

// Find a priminive element of finite field by a given public element (modulo of GF)
uint32_t Diffie_Hellman::find_primitive_element(uint32_t public_element) {
	for (uint32_t i = 2; i < public_element; i++) {
		uint32_t temp = i;
		for (uint32_t j = 0; j < public_element; j++) {

			if (temp == 1 && j == public_element - 1)
				return i;
			else if (temp == 1 && j != public_element - 1)
				continue;

			temp = temp * i % public_element;
		}
	}
	return 0;
}

// Raise to a given degree by modulo
uint32_t Diffie_Hellman::degree(uint32_t value, uint32_t degree, uint32_t modulo) {
	uint32_t result = 1;
	value %= modulo;
	for (size_t i = 0; i < degree; i++) {
		result = (result * value) % modulo;
	}
	return result;
}
