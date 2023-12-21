#include <stdio.h>
#include <math.h>
int main(void) {
	double var1 = 0;
	char operator = 'i';
	double var2 = 0;
	double result = 0;
	puts("Operation");
       	scanf("%lf%c%lf",&var1,&operator,&var2);
		switch(operator) { 
			case '+' :
			result = (var1+var2);
			break;			
			case '-' :
			result = (var1 - var2);
			break;
			case '/':
			if(var2 == 0) {
			puts("division by zero");
			break;
			} else {
			result = (var1/var2);
			break;
			}
		 	case '*':
			result = var1 * var2;
			break;
			case '%':
			result = (var1 - (int)(var1/var2) * var2);
			break;
		        case  '^':
			result = pow(var1,var2);
			break;
			case  'r':
			result = (pow(var1,(1/var2)));
			break;
			default: 
			puts("Invalid operation");			
}
printf("%lf",&result);
}

