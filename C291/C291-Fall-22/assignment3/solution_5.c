#include <stdio.h>
int main(void){
int number = 0;
int rowcount = 0;
int starcount = 1;
int spacecount = 0;
int count2 = 0;
	printf("Enter number: ");
	scanf("%d",&number); 
	spacecount = number/2; 	
	while (rowcount < number/2){
		for (int i = 0; i < spacecount; i++)
		printf(" ");
	       	for (int i = 0; i < starcount; i++)
		printf("*");
		printf("\n");
		starcount = starcount + 2; 
		spacecount = spacecount - 1;
	       	rowcount++;	
	}
	while ((rowcount >= number/2) & (rowcount < number)){
		for (int i = 0; i < spacecount; i++)
			printf(" ");
		for (int i = 0; i < starcount; i++)
			printf("*");
		printf("\n");
		starcount = starcount - 2; 
		spacecount = spacecount + 1; 
		rowcount++;
	}
}


