#include <stdio.h>
#include <hash.h>

int main() {
	uint8_t digest[16] ;
	
	uint8_t text[] = "Coco Jambo";

	size_t n = sizeof(text)-1; //Substract the terminator byte

	printf("[%s] Len: %d \n", text,n);

	calc_digest(text,n, digest);

	for (int i = 0;i < 16;i++) {
		printf("%02X ",digest[i]);
	}
	printf("\n");

	return 0;
}