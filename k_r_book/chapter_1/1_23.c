#include <stdio.h>
#include <string.h>
#define MAXCHAR 100000

int fetch_file(char content[], int max_char_count);
void remove_single_line_comment(char *input, char *output);
void remove_multi_line_comment(char *input, char *output);

int main() {

    char input_content[MAXCHAR];
    char output_content[MAXCHAR];

    fetch_file(input_content, MAXCHAR);
    remove_single_line_comment(input_content, output_content);
    remove_multi_line_comment(input_content, output_content);
    
    printf("%s", output_content);

    return 0;
}


int fetch_file(char content[], int max_char_count) {
    int current_char;
    int size = 0;
    while ((current_char = getchar()) != EOF && size <= max_char_count) {
        content[size] = current_char;
        size ++;
    }

    content[size] = '\0';
    return size;
} 


void remove_single_line_comment(char *input, char *output) {
    int length = strlen(input); 
    int current,
        ahead;
    int in_comment = 0;
    int output_index = 0;

    for (int i = 0; i < length; i++) {
        current = input[i];
        
        if (in_comment && current == '\n') {
           in_comment = 0;
           continue;
        }

        if (in_comment) {
            continue;
        }

        if ((i + 1) >= length) {
            break;
        }

        ahead = input[i + 1];

        if (current == '/' && ahead == '/') {
            in_comment = 1;
            continue;
        }

        output[output_index] = current;
        output_index ++;
    }
}


void remove_multi_line_comment(char *input, char *output) {
    return;
}





