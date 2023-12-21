#include <stdio.h>
int main(void) {
	int radius = 0; 
	printf("Enter the radius\n");
	scanf("%d", &radius);
	double pi = 3;
	double diameter = 2 * radius;
	double circumference = 2 * pi * radius;
	double area = pi * radius * radius; 
	printf("The Area of a circle with radius %d is %f\n",radius,area);
	printf("The Diameter of a circle with radius %d is %f\n",radius, diameter);
	printf("The Circumference of a circle with radius %d is %f\n",radius, circumference);  
}

