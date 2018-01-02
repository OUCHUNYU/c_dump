#include <stdio.h>

unsigned long rightrot(unsigned long x, int n);

int main() {
    unsigned long test = 3;

    unsigned long t_p = rightrot(test, 4);

    printf("%ld\n", t_p);

    return 0;
}

unsigned long rightrot(unsigned long x, int n) {
    unsigned long copy = x;
    for (int i = 0; i < n; i ++) {
        x ^= (-(((copy >> (n - i)) & 1U) ^ x) & (1UL << i));
    }
    return x;
}
