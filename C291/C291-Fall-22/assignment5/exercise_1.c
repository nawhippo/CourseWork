#include <stdio.h>
void generateKGrams(int n,int k,char kGrams[][k+1],char input[],int l);//function prototype
void printKGrams(int l, int k, char kGrams[][k+1]);//function prototype
int length(char str[]); //function prototype
int  main(void){
	//assuming a user doesn't exceed this number with their input.
char input [300];

//storing user input as a string. 
//
printf("Please input the string: ");
scanf("%s",input);

printf("Input length of kgrams: ");
int k;
scanf("%d",&k);

//user inputs valid k gram, smaller than input;
if(k<length(input)){
	int n = length(input) - k + 1;
	char KGrams[n][k+1];
	int l = 0;
	generateKGrams(n,k,KGrams,input,l);
	for(int i = 0;i<n;i++){
		printf("%s",KGrams[i]);
	}
}else{ 
printf("The k gram is larger than the string itself");
}
}





//+1 accounts for the null value
void generateKGrams(int n, int k, char KGrams[][k+1],char input[], int l){
//as the length l is less than the number of k grams
//
	for(l;(l<n);l++){
		//k gram limiter, moving forward by one each time.
		//generates a string to be appended to the list.
		//when it reaches k, it moves to the next of the first dimensions index and makes a new k gram.
		for(int i = 0; i<k; i++)
		KGrams[l][i] = input[l+i];
		}
		//when its at length of the input, then it adds the null value. 
		KGrams[l][k]='\0';
		}
		


void printKGrams(int n, int k, char KGrams[][k+1]){
	for(int i =0;(i < n); i++){
	printf("%s",KGrams[i]);
}
}
int length(char str[]){
	int i = 0;
	int length = 0;
	//char str[] to check length
	////returns length of the string
	while(str[i]!='\0'){
		i++;
		length++;		
}
return length;
}

