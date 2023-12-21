#include <stdio.h>
int main(void){
	int month = 0;
	int year = 0;
	int age = 0;

	printf("Enter current month:\n");
	scanf("%d", &month);
	printf("Enter current year:\n");
	scanf("%d", &year);
	printf("Enter your age:\n");
	scanf("%d", &age);

	printf("It is month %d of the year %d and you are %d years old!\n", month, year, age);
}
 
