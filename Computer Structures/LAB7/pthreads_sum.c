#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//global array
int array[ASIZE];
//global sum
int sum = 0;

//function to calculate the sum of sub-arr
void *sum_array(void *arg) {
    int tid = *(int *)arg;
    //starting index of sub-array
    int start = tid * (ASIZE/NTHREADS);
    //ending index of subarray
    int end = start + (ASIZE/NTHREADS);
    //local sum
    int thread_sum = 0;

    //calc sum of sub-array
    for (int i = start; i < end; i++) {
        thread_sum += array[i];
    }

    //update global sum
    sum += thread_sum;

    return NULL;
}

int main(int argc, char *argv[]) {
   if(argc != 2){
           perror("invalid number of arguments used!");
           return -1;
   }
    //init array
    for (int i = 0; i < ASIZE; i++) {
        array[i] = i * atoi(argv[1]);
    }

    //create threads
    pthread_t threads[NTHREADS];
    int thread_ids[NTHREADS];
    for (int i = 0; i < NTHREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, sum_array, &thread_ids[i]);
    }

    //wait for threads to complete
    for (int i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    //print sum
    printf("%d\n", sum);

    return 0;
}
~
