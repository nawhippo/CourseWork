#include <stdio.h>
#include <stdlib.h>
typedef struct Array Array;
struct Array {
    int* data;
    size_t length;
};

Array* new_array(size_t len);
int array_get(Array* arr, int index);
void array_set(Array* arr, int index, int value);
void delete_array(Array* arr);




int main()
{
Array* arr = new_array(5); 

array_set(arr, 0, 2); 
array_set(arr, 1, 3); 
array_set(arr, 2, 5); 
array_set(arr, 3, 7); 
array_set(arr, 4, 11); 
 
for (int i = 0; i < arr->length; i++) { 
    printf("%d ", array_get(arr, i)); 
} 
 
delete_array(arr);
}

Array* new_array(size_t len){
    //an array's memory is the size of itself.
    Array* output = malloc(sizeof(Array));
    //given the length of the array, mallocs the data.
    output->data = calloc(sizeof(int), len);
    output->length = len;
    //initalizes all array elements as zero
    //elements are initialized as zero by default.
    return output;
}

int array_get(Array* input, int index){
    //returns one data point from the array.
    return input->data[index];
}


void array_set(Array* input, int index, int value){
     //returns one data point from the array.
    input->data[index] = value;
}

void delete_array(Array* input){
    //an array's data must be freed before it itself. 
    free(input->data);
    //now free the array itself.
    free(input);
}


