// comment made by Kenneth Olsen
// my very second C program
// date 1 Jul 14

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int NumOfChickens = 3;

	printf("How many chickens do I have?\n"); 
	scanf("%d", &NumOfChickens);
	printf("I have %d chickens.\n", NumOfChickens);
	
	return 0;
}
