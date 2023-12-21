#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    int i = 0;
    int sum = 0;
    int array[ASIZE];
    int pipefd[2];

    if (argc < 2) {
        perror("Invalid number of arguments!");
        return -1;
    }

    for (i = 0; i < ASIZE; i++) {
        array[i] = i * atoi(argv[1]);
    }

    if (pipe(pipefd) == -1) {
        //pipe failed
        perror("pipe failed!");
        return 1;
    }

    int pid = fork();

    if (pid == 0) {
            //child process
        close(pipefd[0]);
        //close read end of pipe
        for (i = 0; i < ASIZE / 2; i++) {
            sum += array[i];
        }
        //send sum to parent process
        write(pipefd[1], &sum, sizeof(sum)); //send sum to parent process
        //close write end of pipe
        close(pipefd[1]);
        exit(0);
        //parent proces
    } else if (pid > 0){

            //close write end of pipe
        close(pipefd[1]);
        //close write end of pipe
        for (i = ASIZE / 2; i < ASIZE; i++) {
            sum += array[i];
        }
        int child_sum;
        //read sum from child process
        read(pipefd[0], &child_sum, sizeof(child_sum));
        close(pipefd[0]); // close read end of pipe
        sum += child_sum;
        wait(NULL);
    } else {
            //fork failed
        perror("Fork failed\n");
        return -1;
    }
    printf("%d\n", sum);
    return 0;
}
                  
