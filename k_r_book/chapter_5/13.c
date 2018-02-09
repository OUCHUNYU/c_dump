#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT_N 10
#define MAX_CHAR_LINE 10000
#define MAX_CHAR_STORE 100000

static int tail_n = DEFAULT_N;
static char _char_store[MAX_CHAR_STORE];

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
        line[++i] = '\n';
    }

    line[++i] = '\0';
    return i;
}

void _parse_flag(int argc, char *argv[]) {
    if (**argv != '-') {
        return;
    }
    if (!isdigit(*(*argv + 1))) {
        return;
    }
    tail_n = *(*argv + 1) - '0';
}

void _store_line(char *line_store[], char *char_store) {

}

void _print_line_store(char *line_store[], int count) {
    for (int i = 0; i < count; i++)
        printf("%s", ((*line_store) + i));
}



