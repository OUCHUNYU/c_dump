#include <stdio.h>
#include <ctype.h>

int lower(int c);

int main() {

    printf("test 1: U -> %c\n", lower('U'));
    printf("test 2: 8 -> %c\n", lower('8'));
    printf("test 3: r -> %c\n", lower('r'));

    return 0;
}

int lower(int c) {
    return isupper(c) ? c + 32 : c;
}
