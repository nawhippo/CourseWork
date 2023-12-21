#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#define BUFFER_SIZE 5


//global bounded buffer
char buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

//keep track of empty slots in buffer
sem_t empty;
//semaphore to keep track of full slots in buffer
sem_t full;
//mutex to protect buffer
pthread_mutex_t mutex;

//function to generate a random lower case character
char rand_lower() {
    return 'a' + (rand() % 26);
}

//function to generate a random upper case character
char rand_upper() {
    return 'A' + (rand() % 26);
}

//function for writer thread to produce 5 random lower case letters and write them to buffer
void *lower_writer(void *arg) {
    int id = *(int *)arg;
    for (int i = 0; i < 5; i++) {
        char c = rand_lower();
        //wait for an empty slot in buffer
        sem_wait(&empty);
        //acquire the lock
        pthread_mutex_lock(&mutex);
        //write the character to buffer
        buffer[in] = c;

        printf("writer ID: %d, char written: %c\n", id, c);

        //update index to write to buffer
        in = (in + 1) % BUFFER_SIZE;
        //release the lock
        pthread_mutex_unlock(&mutex);
        //signal that there is one more full slot in buffer
        sem_post(&full);
    }
    pthread_exit(NULL);
}


//function for writer thread to produce 5 random upper case letters and write them to buffer
void *upper_writer(void *arg) {
    int id = *(int *)arg;
    for (int i = 0; i < 5; i++) {
        char c = rand_upper();
        //wait for an empty slot in buffer
        sem_wait(&empty);
       pthread_mutex_lock(&mutex);
        printf("writer ID: %d, char written: %c\n", id, c);
        buffer[in] = c;
        in = (in +1) % BUFFER_SIZE;
        //update index to write to buffer
 //release the lock
       pthread_mutex_unlock(&mutex);
        //signal that there is one more full slot in buffer
        sem_post(&full);
    }
    pthread_exit(NULL);
}

//function for reader thread to read 5 characters from buffer and print them
void *reader(void *arg) {
    int id = *(int *)arg;
    for (int i = 0; i < 5; i++) {
        //wait for full slot in buffer
        sem_wait(&full);
        //acquire lock
        pthread_mutex_lock(&mutex);
        //read the character from buffer
        char c = buffer[out];
        //update index to read from buffer
        out = (out + 1) % BUFFER_SIZE;
        printf("reader ID: %d, char read: %c\n", id, c);
        //release the lock
        pthread_mutex_unlock(&mutex);
        //signal that there is one more empty slot in buffer
        sem_post(&empty);
    }
    pthread_exit(NULL);
}
int main() {
    //initialize semaphores and mutex
    //intialize to number of empty slots in buffer
    sem_init(&empty , 0, BUFFER_SIZE);
    //initialize to number of full slots in the buffer
    sem_init(&full, 0, 0);

    //initialize the mutex
    pthread_mutex_init(&mutex, NULL);
    //create writer threads
    pthread_t lower_writers[2];
    pthread_t upper_writers[2];
    int lower_ids[2] = {0, 1};
    int upper_ids[2] = {2, 3};
    for (int i =  0; i < 2;  i++) {
        pthread_create(&lower_writers[i],  NULL, lower_writer, &lower_ids[i]);
        pthread_create(&upper_writers[i], NULL, upper_writer, &upper_ids[i]);
    }

    //create reader threads and respective ids
    pthread_t readers[4];
    int reader_ids[4] = {0, 1, 2, 3};

    for (int i = 0; i < 4; i++) {
        pthread_create(&readers[i], NULL, reader,   &reader_ids[i]);
    }

    //wait for all threads to finish
   for (int i = 0; i < 2; i++) {
        pthread_join(lower_writers[i], NULL);
        pthread_join(upper_writers[i], NULL);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(readers[i], NULL);
    }

    //destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    return 0;
}
                                           