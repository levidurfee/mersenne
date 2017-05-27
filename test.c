#include <stdio.h>
#include <math.h>
#include <string.h>
#include "mersenne.h"

char * reverse(char *str) {
    char tmp, *src, *dst;
    size_t len;
    if (str != NULL) {
        len = strlen (str);
        if (len > 1) {
            src = str;
            dst = src + len - 1;
            while (src < dst) {
                tmp = *src;
                *src++ = *dst;
                *dst-- = tmp;
            }
        }
    }
    return str;
}

void get_binary(int n, char *str) {
    while (n) {
        if (n & 1) {
            *str++ = '1';
        } else {
            *str++ = '0';
        }
        n >>= 1;
    }
    str = reverse(str);
}

int main() {
    double m;
    m = 929;
    int divider = 47;
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
        remainder = fmod(result, divider);
        i++;
        printf("%i\n", remainder);
    } while(remainder != 1);
}
