#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int fetch_line(char line[], int max_char_count);
void reverse_str(char *reversed, char *str);
void empty_line(char *line);

int main() {

    int string_size = 0;
    char string[MAXLINE];
    char reversed_str[MAXLINE];

    while (1) {
        string_size = fetch_line(string, MAXLINE);

        if (string_size <= 0) {
            continue;
        }

        reverse_str(reversed_str, string);

        printf("%s", reversed_str);
        
        empty_line(string);
        empty_line(reversed_str);
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

void reverse_str(char *reversed, char *str) {
    int counter = 0;
    int len = strlen(str);
    int newline_char_count = 0;
    int c;
    while (len > 0) {
        len --;
        c = str[len];
        if (c == '\n') {
            newline_char_count ++;
            continue;
        }
        reversed[counter] = c;
        counter ++;
    }

    while (newline_char_count > 0) {
        reversed[counter] = '\n';
        counter ++;
        newline_char_count --;
    }
}

void empty_line(char *line) {
    int size = strlen(line);
    for (int i = 0; i < size; i ++) {
        line[i] = '\0';
    }
}
