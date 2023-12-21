#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//binary printer helper function
void binaryprinthelper(uint32_t input){
    int i = 0;
    for (i = 31; i >= 0; i--){
        printf("%d", (input >> i)&1);
    }
}

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("no input given");
        return -1;
    }

    //convert the input to a double
    double input = atof(argv[1]);

    //calculate sign bit
    uint32_t sign = 0;
    if (input < 0){
        sign = 1;
        input = -input;
    }

    //calculate exponent and mantissa bits
    uint32_t exponent = 0;
    uint32_t mantissa = 0;
    if (input != 0){
        //normalize input to range to between 1 and 2
        while (input >=2.0){
            input /= 2.0;
            exponent++;
        }
        while (input <1.0){
            input *= 2.0;
            exponent--;
        }

        //calculate mantissa bits
        input -= 1.0;
        int i;
        for (i = 0; i < 23; i++){
            input *= 2.0;
            if (input >= 1.0){
                mantissa |= (1 <<(22 - i));
                input -= 1.0;
            }
        }

        //add bias to exponent
        exponent += 127;
    } else {
        //input is zero
        exponent = 0;
        mantissa = 0;
    }

    //construct single precision floating point number
    uint32_t floating_point = ((sign << 31)|(exponent << 23)|mantissa);
    //print binary representation
    binaryprinthelper(floating_point);
    printf("\n");

    return 0;
}
