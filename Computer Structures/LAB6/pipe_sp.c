#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 256

int main(int argc, char *argv[]) {
   //two element integer array for the pipe
   int fd[2];
   char buffer[SIZE];
   int piperead;
    if (argc != 3){
            perror("Invalid number of argumets");
            return -1;
    }
    //create the pipe
    if (pipe(fd) == -1){
            perror("pipe error");
            return -1;
    }
    //write the two command-line arguments to the pipe
    write(fd[1], argv[1],strlen(argv[1]));
    //seperate the the arguments by a newline char
    write(fd[1],"\n", 1);
    write(fd[1], argv[2], strlen(argv[2]));
    //read from the pipe and print the arguments
    piperead = read(fd[0], buffer, SIZE);
    if (piperead ==  -1) {
        perror("read error");
        return -1;
    }
    //at the end of the buffer and null terminated
    buffer[piperead] ='\0';
    printf("%s\n", buffer);

    //close the reading end of the pipe
    close(fd[0]);
    //close the write end of the pipe
    close(fd[1]);
    return 0;
}
~
