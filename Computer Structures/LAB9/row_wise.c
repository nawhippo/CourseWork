#include <stdio.h>
#include <sys/time.h>

//changeable
#define SZ 10

float A[SZ][SZ];

int main() {
    int i, j;

    // Initialize the 2D array
    for (i = 0; i < SZ; i++) {
        for (j = 0; j < SZ; j++) {
            A[i][j] = i * j;
        }
    }

    struct timeval start, end;
    long seconds, useconds;

    gettimeofday(&start, NULL);

    // Double-nested for loop
    for (i = 0; i < SZ; i++) {
        for (j = 1; j < SZ; j++) {
            A[i][j] = (A[i][j-1] + A[i][j]) / 2;
        }
    }

    gettimeofday(&end, NULL);

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    printf("Time taken for rows: %ld microseconds\n", seconds * 1000000 + useconds);
    return 0;
}
~
~
~
~
~
~
~
