#include <stdio.h>

int main() {

    for (float upper = 300; upper >= 0; upper -= 20) {
        printf("%3.0f %6.1f\n", upper, (5.0 / 9.0) * (upper - 32.0));
    }

    return 0;
}
