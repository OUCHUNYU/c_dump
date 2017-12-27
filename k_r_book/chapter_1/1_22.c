#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int fetch_line(char line[], int max_char_count);
void empty_line(char *line);
void fold(char *input_line, char *result_line);

int main() {

    char current_line[MAXLINE];
    char fold_line[MAXLINE];
    int string_size = 0;

    while (1) {
        string_size = fetch_line(current_line, MAXLINE);

        if (string_size > 80) {
            fold(current_line, fold_line);
            printf("%s", fold_line);
        } else {
            printf("%s", current_line);
        }

        empty_line(current_line);
        empty_line(fold_line);
        string_size = 0;
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

void empty_line(char *line) {
    int size = strlen(line);
    for (int i = 0; i < size; i ++) {
        line[i] = '\0';
    }
}

void fold(char *input_line, char *result_line) {
    // TODO: Implementation goes here 
}
