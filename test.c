#include <stdio.h>
#include <time.h>
#include "mersenne.h"

int main() {
    time_t current_time;
    char *r_str;
    int result;
    current_time = time(NULL);
    power(55);
    r_str = random(current_time, 64);
    printf("%s\n", r_str);
    result = is_prime(r_str);
    printf("%i\n", result);
}
