#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define MAX_N 100

int global_variable;
//mutexes for reading and writing
pthread_mutex_t r_mutex, w_mutex;

void *writer_function(void *arg) {
    int n = *(int*)arg;

    for (int i = 0; i <n;i++) {
        int random_number = rand() % n;
        //lock the mutext to avoid race conditions
        pthread_mutex_lock(&w_mutex);
        global_variable = random_number;
        printf("writer wrote: %d\n", random_number);
        //unlock the mutex to signal that a new value is available.
        pthread_mutex_unlock(&r_mutex);
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
        //if useers don't enter the correct input
    if (argc != 2) {
        fprintf(stderr, "Invalid number of arguments!");
        return 1;
    }
    int n = atoi(argv[1]);
    if (n <= 0 || n> MAX_N) {
        fprintf(stderr,"n must be a positive integer less than the max: %d", MAX_N);
        return 1;
    }

    pthread_t writer_thread;
    if (pthread_create(&writer_thread, NULL, writer_function, &n)) {
        fprintf(stderr,"error creating writer thread");
        return 1;
    }

    //lock it to wait for initial value
    pthread_mutex_lock(&r_mutex);
    for (int i = 0; i < n; i++) {
            //lock to wait for a new value
        pthread_mutex_lock(&r_mutex);
        //print the read value
        printf("main read: %d\n", global_variable);
        //unlock the write mutex to signal that a new value can be written
        pthread_mutex_unlock(&w_mutex);
    }

    pthread_exit(NULL);
}
~
