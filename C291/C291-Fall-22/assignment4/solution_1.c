#include <stdio.h>
#include <math.h>
long factorial(int number);
float binomialDistribution(int k, int n, float p);
int main(void){
	int k = 0;
	int n = 0; 
	float p = 0;
	printf("Enter k value: ");
	scanf("%d", &k);	
	printf("Enter n value: ");       
	scanf("%d", &n);
	printf("Enter p value: ");
	scanf("%f", &p);
	printf("The answer is %f\n", binomialDistribution(k,n,p));
}
float binomialDistribution(int k, int n, float p) {
k = (float)k;
n = (float)n;
return (((factorial (n))/((factorial(k)) * factorial((n - k))))* pow(p,k)*pow((1-p),(n-k)));
}
long factorial(int f) {
	long total = 0;
	if (f >= 1){
		return f * factorial(f-1);
	}else {
		return 1;
}
}
