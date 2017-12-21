#include <stdio.h>

int main() {

    int c;
    int blank_previous = 0,
        blank_current  = 0;

    while ((c = getchar()) != EOF) {
        blank_current = c == ' ';

        if (blank_previous && blank_current) {
            continue;
        }
        
        if (blank_previous) {
            blank_previous = 0;
        }

        if (blank_current) {
            blank_previous = 1;
        }

        blank_current  = 0;
        putchar(c);
    }

    return 0;
}
