#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv) {
    // check if there is exactly one command-line argument
    if (argc != 2) {
                printf("Incorrect input argument\n");
                return -1;
    }

    // get binary string from command-line argument
  char *binstr = argv[1];

  int len = strlen(binstr);

    // check if binary string has exactly 32 bits
    if (len != 32) {
                printf("Incorrect input argument\n");
                return -1;
    }
    // check if binary string has only 0s and 1s
    for (int i = 0; i < len; i++) {
        if ((binstr[i] != '0') && (binstr[i] != '1')) {
                printf("Incorrect input argument\n");
                return -1;
        }
    }

    // get sign bit
    int sign = (binstr[0] - '0');

    // get exponent bits and convert to decimal
    int exp_bits = 0;
    for (int i = 1; i <= 8; i++) {
                exp_bits = exp_bits + (binstr[i] - '0') * pow(2, 8-i);
    }
                int exponent = exp_bits - 127;

    // get mantissa bits and convert to decimal
    double mantissa = 0.0;
    double base = 0.5;
    if (exp_bits == 0) {
        // denormalized value
        for (int i = 9; i < len; i++) {
                mantissa += (binstr[i] - '0') * base;
                base /= 2.0;
        }
                exponent = -126;
    } else {
        // normalized value
        for (int i = 9; i < len; i++) {
                mantissa += (binstr[i] - '0')* base;
                base /= 2.0;
        }
        // add implicit leading 1 bit for normalized values
                mantissa += 1.0;
    }
    double number = pow(-1,sign) * mantissa * pow(2,exponent);
    //Fix exponents post calculation
    if(exponent == -126){
        
            //denormalized
                exponent += 126;
    } else {
            //normalized
                exponent += 127;
    }
    // print results
    printf("Sign: %d\n", sign);
    printf("Exponent: %d\n", exponent);
    printf("Mantissa: %.17g\n", mantissa);
    printf("Number: %.7g\n", number);

    return 0;
}

