#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define MAX_LEN 1024


void* count_occurrences(void* arg) {
    const char** args = (const char**)arg;
    const char* filename = args[0];
    const char* search_string = args[1];
    int count = 0;

    //open the file
    FILE* fp = fopen(filename,  "r");
    if (fp ==  NULL) {
        perror( "File cannot be opened!");
        return NULL;
    }

    char line[MAX_LEN];
    //search through the file for the word
    while (fgets(line, MAX_LEN, fp)) {
        char* match = strstr(line, search_string);
        //if there is a match add to the count
        while (match != NULL) {
if (strncmp(match, search_string, strlen(search_string)) == 0){
            count++;
}
            match = strstr(match+1, search_string);
        }
    }
//print the count of the words occurences
    printf("> %s Count: %d\n", search_string, count);

    fclose(fp);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        perror("Invalid number of arguments");
        return 1;
    }

    pthread_t threads[2];
    const char* thread1_args[2] = {argv[1],argv[2]};
    const char* thread2_args[2] = {argv[3], argv[4]};

    //initiate all of the clock times
    //clock_t start1, end1, start2, end2, total, main_start, main_end;
    //double cpu_time_used1, cpu_time_used2, main_time_used;
    //main_start = clock();

 //start1 = clock();
 //first thread for argument 1
    pthread_create(&threads[0], NULL, count_occurrences, (void*)thread1_args);
    pthread_join(threads[0],NULL);
   //end1 = clock();

   //start2 = clock();
   //2nd thread for argument 2
 pthread_create(&threads[1], NULL, count_occurrences, (void*)thread2_args);
    pthread_join(threads[1], NULL);
    //end2 = clock();

   //main_end = clock();

    //cpu_time_used1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    //cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    //main_time_used = ((double) (main_end - main_start)) / CLOCKS_PER_SEC;



    //total = ((double) (end2 - start1)) / CLOCKS_PER_SEC;

    //printf("Thread 1 CPU time: %f seconds\n", cpu_time_used1);
    //printf("Thread 2 CPU time: %f seconds\n", cpu_time_used2);
    //printf("Main thread CPU time: %f seconds\n", main_time_used);
    //printf("Total CPU time: %ld seconds\n", total);
    return 0;
}
                                         