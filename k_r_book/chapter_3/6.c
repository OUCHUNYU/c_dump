#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[], int min_width);
void reverse(char s[]);

int main() {
    char result[10000];

    itoa(500, result, 8);

    printf("%i, %s\n", 500, result);

    return 0;
}

void itoa(int n, char s[], int min_width) {
    int i, sign;
    unsigned int n2;
    i = 0;

    if ((sign = n) < 0) {
        n2 = -n;
    }
    else {
        n2 = n;
    }

    do {
        s[i++] = (n2 % 10) + '0';
    }
    while ((n2 /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }

    while (i < min_width) {
        s[i++] = ' '; 
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
