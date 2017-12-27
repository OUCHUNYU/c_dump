#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000
#define SPACE_NUM 4

int fetch_line(char line[], int max_char_count);
void empty_line(char *line);
void detab(char *input_line, char *result_line, int space_num);

int main() {

    char current_line[MAXLINE];
    char detab_line[MAXLINE];
    int string_size = 0;

    while (1) {
        string_size = fetch_line(current_line, MAXLINE);

        if (string_size <= 0) {
            continue;
        }

        detab(current_line, detab_line, SPACE_NUM);

        printf("%s", detab_line);

        empty_line(current_line);
        empty_line(detab_line);
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


void detab(char *input_line, char *result_line, int space_num) {
    int length = strlen(input_line);
    int result_line_index = 0;

    for (int count = 0; count < length; count ++) {
        int c = input_line[count];

        if (c != 9) {
            result_line[result_line_index] = c;
            result_line_index ++;
            continue;
        }
        
        for (int i = 0; i < space_num; i ++) {
           result_line[result_line_index] = ' ';
           result_line_index ++;
        }
    }
}



