#include <stdio.h>
int main(void){
int year = 0; 
int month = 0;
int day = 0;
puts("Enter a year:");
scanf("%d",&year);
puts("Enter a month"); 
scanf("%d",&month);
puts("Enter a day");
scanf("%d",&day);

if ((month == (1|3|5|7|8|10|12)) & (day <= 31)){
	puts("The date is valid");
}else if (((month == 2) && (day <=28))||((year%4==0) && (month == 2) && (day<=29))) {
        puts("The date is valid");
}else if((month == (9|4|6|11)) && (day <= 30)){
	puts("The date is valid");
} else {
puts("The date is invalid.");
}
}

