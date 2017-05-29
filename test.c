#include <stdio.h>
#include <math.h>
#include "mersenne.h"
#include "factor.h"
#include "science.h"

int main() {
    int i;
    i = factor(29, 233);
    //printf("%i\n", i);
    get_science();
    int a = 50567;
    for (int i = 1; i <= a; i *= 2) {
    	if(a&i) {
    		printf("1");
    	} else {
    		printf("0");
    	}
    }
}
