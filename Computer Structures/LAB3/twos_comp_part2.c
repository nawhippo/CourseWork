#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
        int issigned = 0;
        char *binaryentry = argv[1];
        int dec = 0;
    if(strlen(binaryentry) != 8){
        fprintf(stderr, "Binary must be 8 bits long\n");
        return -1;
    }
    if (argc != 3) {
        fprintf(stderr, "Incorrect number of arguments\n");
        return -1;
    }

    // boolean check if it is unsigned
    // case shouldn't matter
    if ((strcmp(argv[2], "signed") == 0) || (strcmp(argv[2], "Signed") == 0)) {
        issigned = 1;
    } else if ((strcmp(argv[2], "unsigned") != 0) && (strcmp(argv[2], "unsigned") != 0)){
        fprintf(stderr, "Enter either unsigned or signed.\n");
        return -1;
    }

    for (int i = 0; i < 8; i++) {
        //convert each bit to binary
        //subtracting 0 converts a char to an integer
        int singlebit = binaryentry[i] -'0';
        //add each
        dec = dec * 2 + singlebit;
    }

    if (issigned) {
            //128 is the seventh bit
            //ie the most significant bit
        if (dec & 128) {
            // take bitwise not
            // add 1 to it
            // do a bitwise and with it with full block of 1s
            //then bitwise not, flipping it
            //this gives our intger representation
            dec = -((~dec + 1) & 255);
        }
    }

    // Print the result
    if (issigned) {
            //print regular int
        printf("%d\n", dec);
    } else {
            //print unsigned int
        printf("%u\n", dec);
    }
    return 1;
}

