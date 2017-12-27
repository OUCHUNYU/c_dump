#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int fetch_line(char line[], int max_char_count);
void empty_line(char *line);
void fold(char *input_line, char *result_line, int width);

int main() {

    char current_line[MAXLINE];
    char fold_line[MAXLINE];
    int string_size = 0;

    while (1) {
        string_size = fetch_line(current_line, MAXLINE);

        if (string_size > 80) {
            fold(current_line, fold_line, 80);
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

void fold(char *input_line, char *result_line, int width) {
    // iterate thru the long line
    // stops at every 80 char
    // if current char is blank, tab, newline
    // replace with a newline
    // else back track until the first new line
    // add new line
    // continue
    int length = strlen(input_line);
    int i_index = 0,
        s_index = 0,
        counter = 0;
    int c;

    while (i_index < length) {
        // if remainig chars in the buffer is smaller than width
        // directly put them in the result buffer and escape
        if ((i_index + width) >= length) {
            int remaining = length - i_index;
            while (remaining > 0) {
                result_line[s_index] = input_line[i_index];
                s_index ++;
                i_index ++;
                remaining --;
            }
            continue;
        }
       
        counter = width - 1;
        while (counter > 0) {
            c = input_line[i_index + counter];

            if (c == ' ' && c == 9 && c == '\n') {
                break; 
            }

            counter --;
        }

        if (counter <= 0) {
            counter = width - 1;
        }

        while (counter > 0) {
            result_line[s_index] = input_line[i_index];
            s_index ++;
            i_index ++;
            counter --;
        }

        counter = 0;
        
        if (result_line[s_index - 1] == '\n') {
            continue;
        }

        result_line[s_index] = '\n';
        s_index ++;
    }
}








