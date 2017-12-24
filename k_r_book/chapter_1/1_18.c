#include <stdio.h>
#define MAXLINE 1000

int fetch_line(char line[], int max_char_count);
void remove_trailing_blanks(char line[]);
int is_blank(char line[]);

int main() {
    
    int current_line_size = 0;
    char current_line[MAXLINE];

    while (1) {
        current_line_size = fetch_line(current_line, MAXLINE);
        if (current_line_size <= 0) {
            continue;
        }

        remove_trailing_blanks(current_line);
        
        if (is_blank(current_line)) {
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

