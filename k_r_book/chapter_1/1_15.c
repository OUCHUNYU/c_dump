#include <stdio.h>

float c_to_f(float *c);

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 20;

    celsius = lower;
    while (celsius <= upper) {
        fahr = c_to_f(&celsius);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}

float c_to_f(float *c) {
    return *c / (5.0 / 9.0) + 32.0;
}
