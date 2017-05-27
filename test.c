#include <stdio.h>
#include <time.h>
#include "mersenne.h"

int main() {
	time_t current_time;
	current_time = time(NULL);
	power(5555);
	random(current_time, 64);
}
