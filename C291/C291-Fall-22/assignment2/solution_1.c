#include <stdio.h>
int main(void) {
	int number = 0;
	puts("Enter a number:");
	scanf("%d", &number);
	if (number%2 == 0) {
		printf("%d is even number\n", number);
	} else {
		printf("%d is an odd number\n", number);
}
}

