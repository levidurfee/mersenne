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
#ifndef LOL_MP
#define LOL_MP 1
#include <limits.h>
#include <gmp.h>
#include <string.h>

char * lol_reverse(char *str) {
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
    str = lol_reverse(str);
}

void mersenne() {
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

int small_lucas_lehmer(int p) {
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

/* from https://rosettacode.org/wiki/Lucas-Lehmer_test#GMP */
int lucas_lehmer(unsigned long p)
{
  mpz_t V, mp, t;
  unsigned long k, tlim;
  int res;
 
  if (p == 2) return 1;
  if (!(p&1)) return 0;
 
  mpz_init_set_ui(t, p);
  if (!mpz_probab_prime_p(t, 25)) /* if p is composite, 2^p-1 is not prime */
    { mpz_clear(t); return 0; }
 
  if (p < 23)                     /* trust the PRP test for these values */
    { mpz_clear(t); return (p != 11); }
 
  mpz_init(mp);
  mpz_setbit(mp, p);
  mpz_sub_ui(mp, mp, 1);
 
  /* If p=3 mod 4 and p,2p+1 both prime, then 2p+1 | 2^p-1.  Cheap test. */
  if (p > 3 && p % 4 == 3) {
    mpz_mul_ui(t, t, 2);
    mpz_add_ui(t, t, 1);
    if (mpz_probab_prime_p(t,25) && mpz_divisible_p(mp, t))
      { mpz_clear(mp); mpz_clear(t); return 0; }
  }
 
  /* Do a little trial division first.  Saves quite a bit of time. */
  tlim = p/2;
  if (tlim > (ULONG_MAX/(2*p)))
    tlim = ULONG_MAX/(2*p);
  for (k = 1; k < tlim; k++) {
    unsigned long q = 2*p*k+1;
    /* factor must be 1 or 7 mod 8 and a prime */
    if ( (q%8==1 || q%8==7) &&
         q % 3 && q % 5 && q % 7 &&
         mpz_divisible_ui_p(mp, q) )
      { mpz_clear(mp); mpz_clear(t); return 0; }
  }
 
  mpz_init_set_ui(V, 4);
  for (k = 3; k <= p; k++) {
    mpz_mul(V, V, V);
    mpz_sub_ui(V, V, 2);
    /* mpz_mod(V, V, mp) but more efficiently done given mod 2^p-1 */
    if (mpz_sgn(V) < 0) mpz_add(V, V, mp);
    /* while (n > mp) { n = (n >> p) + (n & mp) } if (n==mp) n=0 */
    /* but in this case we can have at most one loop plus a carry */
    mpz_tdiv_r_2exp(t, V, p);
    mpz_tdiv_q_2exp(V, V, p);
    mpz_add(V, V, t);
    while (mpz_cmp(V, mp) >= 0) mpz_sub(V, V, mp);
  }
  res = !mpz_sgn(V);
  mpz_clear(t); mpz_clear(mp); mpz_clear(V);
  return res;
}

#endif
