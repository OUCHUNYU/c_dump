#include <stdio.h>

int main() {
    
    int c;
    int blank_count = 0,
        tab_count = 0,
        newline_count = 0;

    while ((c = getchar()) != '\n') {
        if (c == ' ') {
            blank_count ++;
        } else if (c == 9) {
            tab_count ++;
        } 
    }

    newline_count ++;

    printf("blank: %d\n", blank_count);
    printf("tab: %d\n", tab_count);
    printf("new line: %d\n", newline_count);

    return 0;
}

