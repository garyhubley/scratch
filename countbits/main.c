
#include <stdio.h>

const char binary[][5] = {
	"0000", "0001", "0010", "0011",
	"0100", "0101", "0110", "0111",
	"1000", "1001", "1010", "1011",
	"1100", "1101", "1110", "1111"
};

int main(int argc, char **argv){

	unsigned int v; // count the number of bits set in v
	unsigned int c; // c accumulates the total bits set in v
	unsigned char nibbles[8], pnibbles[8];

	printf("Enter test value (hex): ");
	scanf("%x", &v);

	for (c = 0; v; c++)
	{
		nibbles[0] = (v >> 0) & 0xF;
		nibbles[1] = (v >> 4) & 0xF; 
		nibbles[2] = (v >> 8) & 0xF; 
		nibbles[3] = (v >> 12) & 0xF;
		nibbles[4] = (v >> 16) & 0xF;
		nibbles[5] = (v >> 20) & 0xF;
		nibbles[6] = (v >> 24) & 0xF;
		nibbles[7] = (v >> 28) & 0xF;

		pnibbles[0] = ((v - 1) >> 0) & 0xF;
		pnibbles[1] = ((v - 1) >> 4) & 0xF; 
		pnibbles[2] = ((v - 1) >> 8) & 0xF; 
		pnibbles[3] = ((v - 1) >> 12) & 0xF;
		pnibbles[4] = ((v - 1) >> 16) & 0xF;
		pnibbles[5] = ((v - 1) >> 20) & 0xF;
		pnibbles[6] = ((v - 1) >> 24) & 0xF;
		pnibbles[7] = ((v - 1) >> 28) & 0xF;

		printf("c : %d\n", c);

		printf("v : 0x%X - ", v);
		for(int i = 7; i >= 0; i--) {
			/*printf("%d: %s ", nibbles[i], binary[nibbles[i]]);*/
			printf("%s ", binary[nibbles[i]]);
		}
		printf("\n");

		printf("v': 0x%X - ", v-1);
		for(int i = 7; i >= 0; i--) {
			/*printf("%d: %s ", pnibbles[i], binary[pnibbles[i]]);*/
			printf("%s ", binary[pnibbles[i]]);
		}
		printf("\n\n");

		v &= v - 1; // clear the least significant bit set
	}

	printf( "# bits set: %d\n", c);
	return 0;
}
