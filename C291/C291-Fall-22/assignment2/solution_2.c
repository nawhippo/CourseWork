#include <stdio.h>
int main(void) {
int a_one = 0;
int a_two = 0;
int a_three = 0;
int iso = 0;
int equi = 0;
puts("Enter angle one:");
scanf("%d",&a_one);
puts("Enter angle two;"); 
scanf("%d",&a_two);
puts("Enter angle three;");
scanf("%d",&a_three);

if(((a_one | a_two | a_three)<1)||(a_one + a_two + a_three != 180)){
	puts("Invalid triangle");
}else {
puts("The triangle is valid.");	
if (a_one ==  a_two && a_three){
	equi = 1;
}
if((a_one == a_two) || (a_one == a_three) || (a_two == a_three)) {
	iso = 1; 
}
if ((a_one && a_two && a_three) < 90){
	puts("It's an acute triangle");
}else if((a_one || a_two || a_three) > 90){
	puts("It's an obtuse triangle");
}else if((a_one || a_two || a_three) == 90){
	puts("It's a right triangle");
}
}
if(iso == 1){
	puts("It's isosceles.");
}
if(iso==0){
	puts("It's not isosceles.");
}
if(equi==1){
	puts("It's equilateral.");
}
}


