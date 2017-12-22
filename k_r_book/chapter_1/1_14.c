#include <stdio.h>
#define LOWER_INDEX 0
#define UPPER_INDEX 25

int main() {

    int current_char;
    int a_ascii_offset = 97;    
    int english_char_arr[UPPER_INDEX + 1] = {0};

    while ((current_char = getchar()) != '\n') {
        int current_ascii_offset = current_char - a_ascii_offset;
        if (current_ascii_offset < LOWER_INDEX || current_ascii_offset > UPPER_INDEX) {
            continue;
        }
        english_char_arr[current_ascii_offset] ++; 
    }

    int english_char_arr_length = sizeof(english_char_arr) / sizeof(int);

    for (int i = 0; i < english_char_arr_length; i ++) {
        putchar(i + a_ascii_offset);
        putchar(' ');
        for (int j = 0; j < english_char_arr[i]; j ++) {
            putchar('>');
        }
        putchar('\n');
    }

    return 0;
}

