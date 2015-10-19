#include <stdio.h>
#include <wchar.h>

int main() {
	wchar_t x;

	printf("This program tries to echoe text for you\n\n");

	printf("Enter text you want echoed: ");
	scanf("%s", &x);

	printf("you wrote: %s \n", x);

return 0;
}
