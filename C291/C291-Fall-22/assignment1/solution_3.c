#include <stdio.h>
 int main(void){
	 int a = 0;
	 int b = 0;

	 printf("input a \n");
	 scanf("%d", &a);

	 printf("input b \n");
	 scanf("%d", &b);

	 int sum = 0;
	 sum = a + b;
	 printf("The sum  of %d and %d is %d\n",a,b,sum);
	
	 int dif = 0;
	 dif = a - b;
	 printf("The difference of %d and %d is %d\n",a,b,dif);
	
	 int prod = 0;
	 prod = a * b;
	 printf("The product of %d and %d is %d\n",a,b,prod);
	
	 int mod = 0;
	 mod = a % b; 
	 printf("The remainder of %d and %d is %d\n",a,b,mod);
 }
