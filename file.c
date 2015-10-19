#include <stdio.h>

// is this all i know? fkn stdio.h....

int main() { // ok, getting somewhere
	int x;   // declared an x as an integer
	// empty space ok

	scanf("%d", &x); // why do i write it like this, scanf %d is looking for a digit, %x hooks it to x.
	// ok so we got that down, now we need some kind of list to print, we want choices in this app
	printf("Rusty programmer listing app\n");
	printf("1. First choice\n");
	printf("2. Second choice\n");
	printf("3. Do we even need this choice?\n"); // choices OK, we need some kind of output for each choice, heading up.

	switch ( x ) {
		case 1;
			break;

		case 2:
			break;
	}

// no, giving up!
