#include <stdio.h>

int main() {
    
    char current_char;

    int tab = 9,
        backslash = 92,
        backspace = 8;

    while ((current_char = getchar()) != EOF) {
        if (current_char == tab) {
            putchar(backslash);
            putchar('t');
        } else if (current_char == backspace)  {
            putchar(backslash);
            putchar('b');
        } else if (current_char == backslash) {
            putchar(backslash);
            putchar(backslash);
        } else {
            putchar(current_char);
        }
    }


    return 0;
}
