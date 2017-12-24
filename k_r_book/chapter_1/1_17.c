#include <stdio.h>
#define MAXLINE 1000

int fetch_line(char line[], int max_char_count);

int main() {
    
    int printable_size = 80; // print any string longer than this
    int current_line_size = 0;
    char current_line[MAXLINE];

    while (1) {
        current_line_size = fetch_line(current_line, MAXLINE);
        if (current_line_size < 80) {
            continue;
        }
        printf("%s", current_line);
    }

    return 0;
}

int fetch_line(char line[], int max_char_count) {
    int current_char;
    int size = 0;
    while ((current_char = getchar()) != EOF && size <= max_char_count) {
        line[size] = current_char;
        size ++;
        if (current_char == '\n') {
            break;
        }
    }

    line[size] = '\0';
    return size;
}

