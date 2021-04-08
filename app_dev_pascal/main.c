#include "pascal.h"

int main(void) {
	uint8_t a;

	a = get_int(MIN, MAX);
	pascal_triangle(a);
	return 0;
}