#include <stdio.h>
int main(void){
	int start = 0;
	int line_count = 0;
	printf("Enter the starting fizz buzz number: ");
	scanf("%d",&start);
	if(start <= 0) {
		puts("Error: Cannot compute Fizz Buzz of -1");
	} else { 
		while(start > 0) {
			if (line_count == 4) {
				puts("");
				line_count = 0; 
			}
			if((start % 3 == 0) && (start % 5 == 0)) {
				printf("Fizz-buzz ");
				start--;
				line_count++;
			}else if(start % 3 == 0) {
				printf("Fizz ");
				start--;
				line_count++;
			}else if (start % 5 == 0) {
				printf("Buzz ");
		        	start--;	
				line_count++;
			}else {
			printf("%d ",start);
			start--;
			line_count++;
			}
			}

	}
	puts(" ");
}
