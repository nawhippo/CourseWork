#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

int wordcount(char * line, char * keyword);
void filereader(char * filename, char * keyword);

int main (int argc, char*  argv[]){
        double time_spent = 0.0;
        clock_t begin = clock();
        if (argc!= 5){
                printf("Error: Incorrect Number of arguments\n");
                exit(EXIT_FAILURE);
        }else{
        filereader(argv[1],argv[2]);
        filereader(argv[3],argv[4]);
        }
        sleep(3);
        clock_t end = clock();
        time_spent += (double)(end-begin)/ CLOCKS_PER_SEC;

        //should overwrite the files contents each time
        FILE * output = fopen("README.md","w");
        fprintf(output,"The elapsed time is %f seconds", time_spent);
        fclose(output);
        return 0;
}

void filereader(char * filename, char * keyword){
   FILE *fp;
   //reads the line
   char line[800];
   int count = 0;
   fp = fopen(filename,"r");
   if(fp == NULL){
           printf("The file could not be opened\n");
           exit(EXIT_FAILURE);
   }
   //read through file line by line, assign the line to str
   while (fgets(line, sizeof(line), fp)) {
    //add to the word count for every line
     count+= wordcount(line,keyword);
        }
        if(line[strlen(line) - 1] != EOF) {
                count+= wordcount(line,keyword);
            }
        fclose(fp);
        printf("%s Count: %d\n",keyword,count);
        }
//scans through a string to find the occurences of a word
//in this case it would be the lines of our files
int wordcount(char * line, char * keyword){
    int linelen = 0;
    int kwlen = 0;
    int count = 0;
    int match = 0;
    kwlen = strlen(keyword);
    linelen = strlen(line);
    for(int i = 0; i <= (linelen - kwlen); i++){
   //assume there is a match until there isn't
        match = 1;
 for(int j = 0; j < kwlen; j++){
        //if they don't match all of the way through
            if(line[i + j] != keyword[j]){
                match = 0;
                break;
            }
        }
        if(match == 1){
            count++;
        }
    }
    return count;
}

