#include <stdio.h>

unsigned long *invert(unsigned long *x, int p, int n);

int main() {
    unsigned long test = 1;

    unsigned long *t_p = invert(&test, 1, 1);

    printf("%ld\n", *t_p);

    return 0;
}

unsigned long *invert(unsigned long *x, int p, int n) {

    for (int i = 0; i < n; i ++) {
        *x ^= 1UL << (p + i);
    }

    return x;
}
