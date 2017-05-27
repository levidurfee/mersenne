/*
 * Copyright (c) 2017 Levi Durfee <levi.durfee@protonmail.ch>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef LOL_RAND
#define LOL_RAND 1

/* includes */
#include <gmp.h>
void power(unsigned long int exponent) {
    mpz_t result, base, one;
    mpz_init(result);
    mpz_init(base);
    mpz_init(one);

    mpz_set_str(base, "2", 10);
    mpz_set_str(one, "1", 10);

    mpz_pow_ui(result, base, exponent);
    mpz_sub(result, result, one);

    gmp_printf("%Zd\n", result);

    mpz_clear(result);
    mpz_clear(base);
    mpz_clear(one);
}

char* random(unsigned long int seed, int bit_count) {
    mpz_t rand_Num;
    gmp_randstate_t r_state;
    unsigned long int i;
    char *random_str;

    gmp_randinit_default (r_state);
    gmp_randseed_ui(r_state, seed);

    mpz_init(rand_Num);

    mpz_urandomb(rand_Num, r_state, bit_count);
    gmp_printf("%Zd\n", rand_Num);

    random_str = mpz_get_str(random_str, 36, rand_Num);

    gmp_randclear(r_state);
    mpz_clear(rand_Num);

    return random_str;
}

int is_prime(char *str) {
    mpz_t n;
    mpz_set_str(n, str, 36);
    /* fix bug (issue #1) */
    return mpz_probab_prime_p(n, 2);
}

#endif