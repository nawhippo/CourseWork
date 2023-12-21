    #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        perror("Invalid number of arguments used.");
        return -1;
    }
    //user input
    int inputnumber = atoi(argv[1]);
//PID
    int returnvalue = fork();
    puts("Hello World");
    if(returnvalue >  0){
        //parent process
        inputnumber++;
        printf("Parent: %d\n",inputnumber);
        int status;
        //wait for the child process to terminate
         if (wait(&status) == -1) {
            perror("wait error");
            return -1;
        }
    }
    if(returnvalue == 0){
         //child process
        inputnumber--;
        printf("Child: %d\n", inputnumber);
        //close fork and terminate child process
        return 0;
    }
    return 0;
}
