#include <stdio.h>
void printSortedMergedArray(int array1[], int lenArray1, int array2[], int lenArray2);
int main(void){
	int lenArray1;
	int lenArray2;
	printf("Input array 1 size: ");
	scanf("%d",&lenArray1);
	int array1[lenArray1];
	printf("Input array1: ");
	for (int i = 0; i < lenArray1; i++){
	scanf("%d",&array1[i]);
	}
	printf("input array 2 size: ");
	scanf("%d",&lenArray2);
	printf("Input array2: ");
	int array2[lenArray2];
	for(int i = 0; i < lenArray2; i++){
	scanf("%d", &array2[i]);
	}
	printf("\n");
	printSortedMergedArray(array1, lenArray1, array2, lenArray2);
	}
	
	void printSortedMergedArray(int array1[], int lenArray1, int array2[], int lenArray2){
		int c[lenArray1+lenArray2];
		int i = 0;
		int j = 0;
		int k = 0;

		while(i < lenArray1 && j < lenArray2){
			if (array1[i] < array2[j]){
				c[k] = array1[i];
				i++;
			}else {
				c[k] = array2[j];
				j++;
			}
			k++;
		}
		
		while (i < lenArray1){
			c[k] = array1[i];
			i++;
			k++;
		}
		while (j < lenArray2){
			c[k] = array2[j];
			j++;
			k++;
		}
		for (int g = 0; (g < (lenArray1 + lenArray2)); g++){
			printf("%d ",c[g]);
		}
		printf("\n");
	}
