void checkset(int input[], int length);
int findIntersection(int input1_length, int input2_length, int input[], int input2[]);
int findUnion(int input1_length, int input2_length, int input[], int input2[]);
void calculateJaccard(int input1[], int input2[], int input1_length, int input2_length);
#include <stdio.h>
int main (void){
	int input1_length; 
	int input2_length;
	printf("Enter first set length: "); 
	scanf("%d",&input1_length); 
	int input1[input1_length];
	printf("Enter first set: "); 
	for (int i = 0; i < input1_length; i++){
		scanf("%d", &input1[i]);
	}
	checkset(input1, input1_length); 
	printf("Enter second set length: ");
	scanf("%d", &input2_length);
	int input2[input2_length];
	printf("Enter second set: ");
	for (int i = 0; i < input2_length; i++){
		scanf("%d", &input2[i]);
	}
	checkset(input1,input1_length);
	checkset(input2,input2_length);
	calculateJaccard(input1, input2, input1_length, input2_length); 
}
void checkset(int input[], int length){
	if (length == 0){
		puts("\nThe set cannot be empty");
	}
}
int  findIntersection (int input1_length, int input2_length, int input[], int input2[]){
	int intersection[input1_length];
	int count2 = 0;
	for (int i = 0; i < input1_length; i++){
		for (int r = 0; r < input2_length; r++){
			if (input[i] == input2[r]){
				intersection[count2] = input[i];
				count2++;
				break;
			}
		}
	}
	return count2; 
}

int  findUnion(int input1_length, int input2_length, int input[], int input2[]){
	int Union[input1_length + input2_length];
	int count1 = 0;
	for (int i = 0; i < input2_length; i++){{
		count1 = input1_length;
		for (int r = 0; r < input1_length; r++){
			if (input2[i] == Union[r])
				{
					break;
				}else{
					if (r == input1_length - 1){
						Union[count1] = input2[r];
						count1++;
					}
				}
		}
	}
	return count1++; 
	}
	}
void calculateJaccard(int input1[], int input2[], int input1_length, int input2_length){
	float a = findIntersection(input1_length, input2_length, input1, input2);
	float b = findUnion(input1_length, input2_length, input1, input2);
	double c = a/b; 
	printf("Jaccard similarity is %.3lf",c);
}

