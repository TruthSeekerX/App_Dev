#include "pascal.h"

uint64_t fact(uint8_t num) {
	uint64_t result = 1;
	for (uint8_t i = 1; i <= num; i++) {
		result *= i;
	}
	return result;
}