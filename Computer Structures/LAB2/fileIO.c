#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char*  argv[]) {
    FILE *fp;
    char line[300];
    int count = 0;

    if (argc != 3) {
        printf("Error: Incorrect Number of arguments\n");
        exit(EXIT_FAILURE);
    } else {
        fp = fopen(argv[1], "r");
        if(fp == NULL) {
            printf("The file could not be opened");
            exit(EXIT_FAILURE);
        }
        while (fgets(line, sizeof(line), fp)) {
            if(strstr(line, argv[2]) != NULL) {
                count++;
            }
        }
        if(line[strlen(line) - 1] != EOF) {
            if(strstr(line, argv[2]) != NULL) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    exit(EXIT_SUCCESS);
}
