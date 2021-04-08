#include "pascal.h"

uint8_t get_int(uint8_t min, uint8_t max) {
	uint8_t r;
	do {
		printf("Please enter a number between [%hhu, %hhu]: ", min,max);
//		uint8_t r;
		scanf("%hhu",&r);
//		if (r != 1) t = 0;
//		_flushall();
//		char temp;
//		while ((temp = getchar()) != EOF && temp != '\n');
	} while (r < min || r > max);
	return r;
}