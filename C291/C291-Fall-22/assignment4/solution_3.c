#include <stdio.h>

void isPerfectNumber(int num); 
int main(void) {
int num = 0;
printf("Enter a number: ");
scanf("%d", &num);
isPerfectNumber(num);
}
void isPerfectNumber(int num){
	int count = 1; 
	int sum = 0;
	while (count < num){
		if ((num % count)== 0){
			sum += count;
			count++;
		}else {
			count++;
		}
	}
	if ((num - sum) == 0){
		printf("%d is a perfect number\n",num);
	} else {
		printf("%d is not a perfect number\n",num);
	}
}

		
		
	

