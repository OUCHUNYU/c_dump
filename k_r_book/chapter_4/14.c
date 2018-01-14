#include <stdio.h>

#define swap(t, x, y) do {t z = x; x = y; y = z;} while (0)

int main() {

    int a = 5;
    int b = 100;

    swap(int, a, b);
    printf("beforee\n a = 5, b = 100\n after\n a = %i, b = %i\n", a, b);

    return 0;
}
