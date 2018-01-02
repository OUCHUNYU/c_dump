#include <stdio.h>

/*
 * Returns x with the n bits that begin at position p set 
 * to the rightmost n bits of y.
 */
unsigned long *setbits(unsigned long *x, int p, int n, int y);

int main() {
    unsigned long test = 1;

    unsigned long *t_p = setbits(&test, 3, 3, 1);

    printf("%ld\n", *t_p);

    return 0;
}

unsigned long *setbits(unsigned long *x, int p, int n, int y) {
    for (int i = 0; i < n; i++) {
        *x ^= (-y ^ *x) & (1UL << (p + i));
    }
    return x;
}
