#include <stdio.h>
#include <math.h>
#include "mersenne.h"

int lucas_lehmer(int p) {
    unsigned long int s = 4;
    int m = pow(2, p) - 1;
    int i = p - 2;
    int j;
    for(j=0; j<i; j++) {
        //s = ((s × s) − 2) mod M
        s = fmod( ((s * s) - 2), m);
        printf("%lu\n", s);
    }
    if(s == 0) {
        return 1;
    }

    return 0; // not prime
}

int main() {
    int t = lucas_lehmer(31);
    printf("%i\n", t);
}
