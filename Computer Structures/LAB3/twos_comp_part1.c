#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
        int mask;
        unsigned char bitsarray[8];
        int carrybit = 1;
         if (argc != 2) {
                 fprintf(stderr, "Incorrect nunber of argument");
                 return -1;
         }
         int num = atoi(argv[1]);
         if (num < -128 || num > 127) {
                 fprintf(stderr, "Value out of range for 8 bit integers\n");
                 return -1;
         }
         if (num < 0) {
                mask = 1;
                //make the number positive
                num = -num;
         } else {
                mask = 0;
         }
         for (int i = 0; i < 8; i++) {
                        //convert the number to 8 binary by repeatedly dividing it by two
                        bitsarray[i] = num % 2;
                        num = num/2;
         }
         //if the integer turns out to be negative
         if (mask) {
                for (int i = 0; i < 8; i++) {
                //flip each bit
                //if the number is negative
                //to get complement of it
                bitsarray[i] = !bitsarray[i];
         }
                for (int i = 0; i < 8; i++) {
                        if (carrybit == 1 && bitsarray[i] == 0) {
                        bitsarray[i] = 1;
                        carrybit = 0;
                        //combine the carry with the 1 in the binary rep
                        //and move it over until there is a zero
                        //thus resulting in a two's complement
                 } else if (bitsarray[i] == 1 && carrybit == 1) {
                        bitsarray[i] = 0;
                        carrybit = 1;
            }
        }
    }
        for (int i = 7; i >= 0; i--) {
        //print bits in reverse
                printf("%d", bitsarray[i]);
    }
        printf("\n");
}
~
