#include <stdio.h>
#include <math.h>
#include<string.h>
int number = 0;
//checks whether or not first 1 has been reached, zero for off, 1 for on
int first = 0;
int i = 0; 
int binary[32];
int main(void){
	printf("Enter a number for reverse binary conversion:");
	scanf("%d",&number);
if (number < 0)
	puts("Enter a positive number"); 
if (number==0)		
printf("0");

while (number > 0) {
	binary[i++] = number % 2;
	number /= 2;
}
//reverse number
for(int b = 0; b <= i-1; b++)
printf("%d",binary[b]);
printf("\n");
}



