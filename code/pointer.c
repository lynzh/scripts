#include <stdio.h>

int main() {
	int x;
	int pointer*;

	pointer* = &x;
	for(x = 1; x <= 10; x++)
		printf("%d\n", sizeof(pointer*));
		return 0;
}

