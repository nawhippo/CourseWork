#include <stdio.h>

int main(){
    //size of array
    printf("Enter size: ");
    int size;
    scanf("%d", &size); 
    //manually enter the elements in the array
    printf("Enter elements: ");
    //initialize the array
    int arr[size];
    
    for(int i = 0; i < size; i++){
        //iterate through the array
        scanf("%d", &arr[i]);
    }
    int out = 1;
    
    for(int i = 2; i < size; i++){
        out = out ^ i;
    }
    for(int i = 0; i < size; i++){
        out = out ^ arr[i];
    }
    printf("%d", out);
}
