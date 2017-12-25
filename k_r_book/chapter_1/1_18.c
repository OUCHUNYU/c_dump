#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int fetch_line(char line[], int max_char_count);
void remove_trailing_blanks(char *line);
int is_blank(char *line);
void empty_line(char *line);

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

        empty_line(current_line);
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

void remove_trailing_blanks(char *line) {
    int line_size = strlen(line); 
    int i; // array current index
    int item; // array current item at index i
    
    if (*line == '\0') {
        return;
    }

    if (*line == '\n') {
        *line = '\0';
        return;
    }

    for (i = line_size - 1; i >= 0; i --) {
        item = line[i];

        if (item != ' ' && item != '\n' && item != '\t')  {
            break;
        }

        line[i] = '\0';
    }

    line[i + 1] = '\n';
}

int is_blank(char *line) { 
    int result = 1;
    int size = strlen(line);
    
    for (int i = 0; i < size; i ++) {
        int c = line[i];
        if (c == ' ' || c == '\n' || c == '\t' || c == '\0') {
            continue;
        }
        result = 0;
    }

    return result;
}

void empty_line(char *line) {
    int size = strlen(line);
    for (int i = 0; i < size; i ++) {
        line[i] = '\0';
    }
}




