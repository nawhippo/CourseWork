#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void *printA(void *arg) {
    (void)arg;
    sem_wait(&semaphore);
    printf("A\n");
    sem_post(&semaphore); // FIX for code issue
    return NULL;
}

void *printB(void *arg) {
    (void)arg;
    sem_wait(&semaphore);
    printf("B\n");
    sem_post(&semaphore); // FIX for code issue
    return NULL;
}

void *printC(void *arg) {
    (void)arg;
    sem_wait(&semaphore);
    printf("C\n");
    sem_post(&semaphore); // FIX for code issue
    return NULL;
}

int main(int argc, char *argv[]) {
        //fixes unused parameter warning
    (void)argv[0];
    (void)argc;
    sem_init(&semaphore, 0, 2);
    pthread_t threadA, threadB, threadC;
    pthread_create(&threadA, NULL, printA, NULL);
    pthread_create(&threadB, NULL, printB, NULL);
    pthread_create(&threadC, NULL, printC, NULL);
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);
    sem_destroy(&semaphore);
    return 0;
}
~
~
~
~
~
~
~
~
~
~
