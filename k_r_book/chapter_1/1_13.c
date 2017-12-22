#include <stdio.h>

void print_hist_bar(int *length);

int main() {

    int c;
    int in = 1,
        out = 0;
    int previous = out,
        current = out;
    int length = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            current = out;
        } else {
            current = in;
        }

        if (previous && !current) {
            print_hist_bar(&length);
            length = 0;
        } else if (previous && current) {
            length ++;
            putchar(c);
        } else if (!previous && current) {
            length ++;
            putchar(c);
        }

        previous = current;
    }

    return 0;
}


void print_hist_bar(int *length) {
    putchar(' ');
    for (int i = 0; i < *length; i ++) {
        putchar('>');
    }
    putchar('\n');
}
