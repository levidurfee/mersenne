#include <stdio.h>
#include <math.h>
#include <string.h>
#include "mersenne.h"

void get_binary(int num, char *str) {
    *(str+5) = '\0';
    int mask = 0x10 << 1;
    while(mask >>= 1) {
        *str++ = !!(mask & num) + '0';
    }
}

int main() {
    double m;
    m = 23;
    int d = 47;
    char bits[6];
    get_binary(m, bits);
    printf("%s\n", bits);

    int remainder = 1;
    int i = 0;
    int square;
    int result;
    do {
        square = pow(remainder, 2);
        //printf("Remainder: %i Squared: %i\n", remainder, square);
        if(bits[i] == '\0') {
            break;
        }
        if(bits[i] == '1') {
            printf("mul\n");
            result = square * 2;
        } else {
            printf("no mul\n");
            result = square;
        }
        //printf("Result: %i Mod: %i\n", result, d);
        remainder = fmod(result, d);
        i++;
        printf("%i\n", remainder);
    } while(remainder != 1);
}
