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
void power() {
    mpz_t result, base, one;
    unsigned long int exponent;
    mpz_init(result);
    mpz_init(base);
    mpz_init(one);

    mpz_set_str(base, "2", 10);
    mpz_set_str(one, "1", 10);
    exponent = 500;

    mpz_pow_ui(result, base, exponent);
    mpz_sub(result, result, one);

    gmp_printf("%Zd\n", result);

    mpz_clear(result);
    mpz_clear(base);
    mpz_clear(one);
}

#endif