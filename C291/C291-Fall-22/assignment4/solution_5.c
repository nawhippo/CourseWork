#include <stdio.h>
#include <math.h>
int X = 0; 
int n = 0;
int L = 0; 
int R = 0 ;
int factorial(int factorable);
int primechecker(int sum); 
int primeNumber(int L, int R);   
float totalsum(int X, int n, int L, int R); 
int main(void){
puts("Enter the value of X: ");
scanf("%d", &X);
puts("Enter the value of n: "); 
scanf("%d", &n);
puts("Enter the value of L: ");
scanf("%d", &L);
puts("Enter the value of R: ");
scanf("%d", &R); 
printf("Sum of series = %f", totalsum(X,n,L,R));
}
int factorial(int factorable){
	if (factorable == 0){
	return 1;
	} else {
	return factorable * factorial(factorable - 1); 	
}
}
int primechecker(int num){
	//checks whether or not a number is prime
      int count = 1;
      int prime = 1;
      if (num = 1){ 
	      prime = 0;
      }
	while (count < num) {
	  if ((num % count == 0)&(count != 1)){
		prime = 0; 
		count++;
	  } else {
	  count ++; 
	  }
	}
	return prime;
}	
int primeNumber(int L, int R){
	//counts the number of prime numbers between two values
	int primesum = 0;
	int btwn = L; 
	while ((btwn >= L) & (btwn < R)){
		if ((primechecker(btwn)) == 1) {
		primesum += btwn; 
		btwn++;
	}else {
		btwn++;
	}
	}
}
float totalsum (int X, int n, int L, int R){
	float result = 0;
	float totalSum = 0;
	int count = 1;
	while (count <= (n)){
		totalSum += ((pow(X,count))/factorial(count));
		count++;
		}
		result = (totalSum + primeNumber(L,R));
		return result;
}
