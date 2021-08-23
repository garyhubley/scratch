
#include <stdio.h>
#include <stdint.h>


int main() {
	int16_t x = 0xaaaa;
	printf( "%x %d\n", x, x );
	x = x >> 1;
	printf( "%x %d\n", x, x );
	return 0;
}
