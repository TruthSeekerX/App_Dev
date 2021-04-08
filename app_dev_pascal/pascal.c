#include "pascal.h"

void pascal_triangle(uint8_t input) {
	//C(N,K) = n!/(n-k)!k!
	uint16_t size = 0;
	for (uint8_t i = 1; i <= input; i++){
		size += i;
	}
	uint64_t *pscl;
	pscl = (uint64_t *)calloc(size, sizeof(uint64_t));

	for (uint8_t n = 0, k = 0, i = 0; n < input; n++) {
		for (k = 0; k < n + 1; k++){
			*(pscl + i) = fact(n) / (fact(n - k) * fact(k));
			i++;
		}
	}

	for (uint8_t n = 0, k = 0, i = 0; n < input; n++) {
		for (k = 0; k < n + 1; k++) {
			printf("%7llu", *(pscl + i));
			i++;
		}
		puts("");
	}
}