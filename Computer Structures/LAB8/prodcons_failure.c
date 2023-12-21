#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//max input user is allowed
#define MAX_N 100
//share variable
int global_variable;
//should produce incorrect outputs, often repeating
void *writer_function(void *arg) {
    int n = *(int*)arg;
    for (int i = 0; i <n;i++) {
        int random_number = rand() % n;
        global_variable = random_number;
        printf("writer wrote: %d\n", random_number);
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr,"Invalid number of arguments!");
        return 1;
    }
    int n = atoi(argv[1]);
    if (n <= 0 || n> MAX_N) {
            //max of 100
        fprintf(stderr,"n must be a positive integer less than the max.");
        return 1;
    }

    pthread_t writer_thread;
    //if thread creation fails for this.
    if (pthread_create(&writer_thread, NULL, writer_function, &n)) {
        fprintf(stderr,"error creating writer thread");
        return 1;
    }
//will fail
    for (int i = 0; i < n; i++) {
        printf("main read: %d\n", global_variable);
    }

    pthread_exit(NULL);
}
~
~
