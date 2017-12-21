#include <stdio.h>

int main() {

    int in_word = 1;
    int out_word = 0;

    int previous = 0;
    int current = 0;

    int c;

    while((c = getchar()) != EOF) {

        if (c == ' ' || c == '\n' || c == '\t') {
            current = out_word;
        } else {
            current = in_word;
        }

        if (previous && !current) {
            putchar('\n');
            previous = out_word;
        } else if (!previous && !current) {
            continue;
        } else {
            putchar(c);
            previous = in_word;
        }

    }

    return 0;
}
