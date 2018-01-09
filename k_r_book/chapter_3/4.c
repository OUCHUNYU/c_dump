#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    char result[10000];

    itoa(INT_MIN, result);

    printf("%i, %s\n", INT_MIN, result);

    return 0;
}

void itoa(int n, char s[]) {
    int i = 0;
    int sign;

    if (n < -INT_MAX) {
        int offset = n + INT_MAX;

        do {
            s[i ++] = offset % 10 + '0';
        } while ((offset /= 10) > 0);

        n = -INT_MAX;
    }
    
    if ((sign = n) < 0) {
        n = -n;
    }

    do {
        s[i ++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    
    if (sign < 0) {
        s[i ++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
