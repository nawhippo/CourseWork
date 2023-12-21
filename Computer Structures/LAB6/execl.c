#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        perror("Invalid number of arguments\n");
        return -1;
    }

    char command[100];

    //Commands are concatenated by sprintf
    sprintf(command,"%s %s", argv[1], argv[2]);

    //-c makes it so it can read commands from a string
    execl("/bin/bash", "bash", "-c", command, NULL);

    return 0;
}
