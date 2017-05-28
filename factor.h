#ifndef LOL_FACTOR
#define LOL_FACTOR

int factor (int n, int p) {
	int power_of_two = 2; // Running power of two.
	int result = 1; // Result
	for (int i = 1; i <= n; i *= 2) {
		if (n&i) {  // Checks if current bit in the binary expansion of n is a 1.
			result = (result * power_of_two) % p;
		}
		power_of_two = (power_of_two * power_of_two) % p;
	}
	return result;
}

#endif