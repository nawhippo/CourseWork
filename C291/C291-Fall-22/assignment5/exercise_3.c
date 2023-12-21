#include <stdio.h>
void printUniqueElements(int elements[], int lenArray);
int main(void){
	int input = 0;
	int lenArray = 0; 
	printf("Input Size of Array: ");
	scanf("%d",&lenArray);
	int elements[lenArray];
	puts("Enter each element of the array");
	for (int i = 0; i < lenArray; i++){
		scanf("%d",&input);
		elements[i] = input;
	}
	printUniqueElements(elements,lenArray);
}
void printUniqueElements(int elements[],int lenArray){
	for(int i = 0; i < lenArray; i++){
		//if its not equal to the next term then print it
		if(elements[i] != elements[i+1]){
			printf("%d",elements[i]);
		}
	}
}

