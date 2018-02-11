#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT_N 10
#define MAX_CHAR_LINE 10000
#define MAX_CHAR_STORE 100000

static int tail_n = DEFAULT_N;

int _get_line(char *line, int limit);
void _parse_flag(int argc, char *argv[]);
void _store_line(char *line_store[], char *char_store);
void _print_line_store(char *line_store[], int count);

int main(int argc, char *argv[]) {
    argc--;
    argv++;
 
    if (argc > 0) {
        _parse_flag(argc, argv); // This should update static tail_n
    }

    char *_line_store[tail_n];
    char _char_store[1000];

    _store_line(_line_store, _char_store);

    _print_line_store(_line_store, tail_n);
    
    return 0;
}

int _get_line(char *line, int limit) {
    int c, i;
    for (i = 0; (i < limit - 1) && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i++] = '\n';
    }

    line[i] = '\0';
    return i;
}

void _parse_flag(int argc, char *argv[]) {
    if (**argv != '-') {
        return;
    }

    int arg_num = atoi((*argv + 1));

    if (arg_num == 0) {
        return;
    }

    tail_n = arg_num;
}

void _store_line(char *line_store[], char *char_store) {
    int char_count;
    char *line_p;
    int line_count = 0;

    while ((char_count = _get_line(char_store, MAX_CHAR_STORE)) > 0) {
        if ((line_p = malloc(char_count)) == NULL) {
            exit(1);
        }

        char_store[char_count - 1] = '\0';
        strcpy(line_p, char_store);

        line_count++;

        if (line_count <= tail_n) {
            line_store[line_count - 1] = line_p;
            continue;
        }

        // free index 0 pointer memory and move every
        // following pointer on position forward
        free(line_store[0]);
        for (int i = 1; i < tail_n; i++) {
            line_store[i - 1] = line_store[i];
        }
        line_store[tail_n - 1] = line_p;
    }
}

void _print_line_store(char *line_store[], int count) {
    char *p;
    for (int i = 0; i < count; i++) {
        if ((p = *(line_store + i)) == NULL) {
            continue;
        }

        printf("%s\n", p);
    }
}



