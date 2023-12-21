#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_random_lower() {
        //generate rand number between 0 and 25 and add it to a, which will result in a diff letter
    char random_char = 'a' + (rand() %26);
    printf("%c\n",random_char);
}

void print_random_upper() {
    char random_char = 'A' + (rand() %  26);
    printf("%c\n", random_char);
}

int main(int argc, char *argv[]) {
        //seeds a random number generator between 0 and 25 and add to 'A'
    srand(time(NULL));

    if (argc != 2) {
        perror("invalid number of arguments");
        return -1;
    }

    //check if second arg is -l, ie lowercase
    if (argv[1][0] == '-' && argv[1][1] == 'l') {
        for (int i = 0; i < 10; i++) {
            print_random_lower();
        }
        //check for -u, ie uppercase
    } else if (argv[1][0] == '-' && argv[1][1] == 'u') {
        for (int i = 0; i < 10; i++) {
            print_random_upper();
        }
    } else {
            //if second arg isn't -1 or -u, print error message
        perror("invalid second argument");
        return -1;
    }
    return 0;
}
~
~
