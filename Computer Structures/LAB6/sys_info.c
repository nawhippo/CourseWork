#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
        int mypipe[2];
        if (argc != 3) {
        perror("Invalid number of arguments");
        return -1;
    }
        if (pipe(mypipe) == -1) {
        perror("pipe error");
        return -1;
    }

    int returnvalue = fork();
    if (returnvalue == -1) {
        perror("fork error");
        return -1;
    }
    //child process
    if (returnvalue == 0) {
            char buffer[1024];
   //close unused write end of the pipe
        close(mypipe[1]);

        //read the pipe
    int piperead = read(mypipe[0], buffer,1024);
        if (piperead == -1) {
            perror("read error");
            return -1;
        }

        //add a null terminate to the end of read command
        buffer[piperead] ='\0';

        //execute the command
        if (execl("/bin/sh", "sh", "-c", buffer,  NULL) == -1) {
            perror("execl error");
            return -1;
        }

        //probably wont be executed
        return -1;
    } else {
        //parent process
      char command[1024];
      int status;
        //close the read end of the pipe, which isn't used anyway
        close(mypipe[0]);

      //build the gestalt command string
     snprintf(command, 1024, "%s %s", argv[1], argv[2]);
        //write the command to the pipe
        int pipewrite = write(mypipe[1], command, strlen(command));
        if (pipewrite == -1){
        perror("write error");
        return -1;
        }
        //close the write end
        close(mypipe[1]);
        //make child terminate
        if (wait(&status) == -1) {
            perror("wait error");
            return -1;
        }
        }
}
