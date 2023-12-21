#include <stdio.h>
int num1 = 0;
int num2 = 0;
int findGCD(int num1, int num2);
void main (void){
printf("Enter 1st positive integer: ");
scanf("%d", &num1);
printf("Enter 2nd positive integer: ");
scanf("%d", &num2);
findGCD(num1, num2);
printf("GCD of %d and %d is %d\n",num1, num2, (findGCD(num1, num2)));
}

int findGCD(int num1, int num2) {
	if (num1 == num2) {
		return num1;
	}else if (num1 > num2) {
		findGCD(num1 - num2, num2);
	}else {
		findGCD(num1, num2 - num1); 
	}
}
