#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000
#define SPACE_NUM 4

int fetch_line(char line[], int max_char_count);
void empty_line(char *line);
void entab(char *input_line, char *result_line, int space_num);

int main() {

    char current_line[MAXLINE];
    char entab_line[MAXLINE];
    int string_size = 0;

    while (1) {
        string_size = fetch_line(current_line, MAXLINE);

        if (string_size <= 0) {
            continue;
        }

        entab(current_line, entab_line, SPACE_NUM);

        printf("result: %s", entab_line);

        empty_line(current_line);
        empty_line(entab_line);
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


void entab(char *input_line, char *result_line, int space_num) {
    int length = strlen(input_line);
    int c;
    int input_index = 0;
    int result_index = 0;
    
    while (input_index < length) {

        c = input_line[input_index];

        if (c != ' ') {
            result_line[result_index] = c;
            result_index ++;
            input_index ++;
            continue;
        }

        int start = input_index;
        int end;

        while (c == ' ') {
            input_index ++;
            if (input_index >= length) {
                break;
            }
            c = input_line[input_index];
        }

        end = input_index;

        int total_tabs = (end - start) / space_num;
        int total_blank = (end - start) % space_num;
        printf("total tabs: %d\n", total_tabs);
        printf("total blanks: %d\n", total_blank);

        while (total_tabs > 0) {
            result_line[result_index] = 9;
            total_tabs --;
            result_index ++;
        }

        while (total_blank > 0) {
            result_line[result_index] = ' ';
            total_blank --;
            result_index ++;
        }
    }
}



