#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT_TABSTOP 8
#define MAX_TABSTOPS 10
#define MAX_LINE 10000

int parse_tabstops(int argc, char *argv[], int *arguments);
int fetch_line(char *line, int max_char_count);
void entab(char *in, char *out, int *tabstops, int ts_count);
void detab(char *in, char *out, int *tabstops, int ts_count);

int main(int argc, char *argv[]) {
    int user_provided_tabstops[MAX_TABSTOPS] = {0};
    int argument_count = parse_tabstops(argc, argv, user_provided_tabstops);
    int *tabstops = malloc(argument_count * sizeof(int));
    memcpy(tabstops, user_provided_tabstops, argument_count * sizeof(int));

    char current_line[10000];
    char output_line[10000];
    
    while (fetch_line(current_line, MAX_LINE) > 0) {
        puts("-------------- start -----------------\n");
        printf("original: %s\n", current_line);
        entab(current_line, output_line, tabstops, argument_count);
        printf("entabed: %s\n", output_line);
        detab(current_line, output_line, tabstops, argument_count);
        printf("detabed: %s\n", output_line);
        puts("--------------- end ------------------\n");
    }

    free(tabstops);

    return 0;
}

int parse_tabstops(int argc, char *argv[], int *arguments) {
    // skip file name part
    argc--;
    argv++;

    if (argc <= 0) {
        return 0;
    }

    if (**argv != '-' || *(*argv + 1) != 't') {
        printf("Flag %s not recognized\n", *argv);
        exit(-1);
    }

    argv++; // Move to next
    
    char *tabstop_list = *argv;
    char current_c;
    char found_tabstop_str[100];
    int last_found_index = 0;
    int i;
    int counter = 0;

    for (i = 0; (current_c = *(tabstop_list + i)) != '\0'; i++) {
        if (current_c != ',' && !isdigit(current_c)) {
            puts("Invalid argument\n"); 
            exit(-1); 
        } else if (current_c != ',' && isdigit(current_c)) {
            continue;
        } else {
            strncpy(found_tabstop_str, tabstop_list + last_found_index, i - last_found_index);
            *(found_tabstop_str + i - last_found_index) = '\0'; // add a terminator to copied str
            last_found_index = i + 1;
            *arguments = atoi(found_tabstop_str);            
            arguments++;
            counter++;
        }
    }
    // add last num before \0
    strncpy(found_tabstop_str, tabstop_list + last_found_index, i - last_found_index);
    *(found_tabstop_str + i - last_found_index) = '\0';
    *arguments = atoi(found_tabstop_str);            
    counter++;
    return counter;
}

int fetch_line(char *line, int max_char_count) {
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

void entab(char *in, char *out, int *tabstops, int ts_count) {
    int current_tabstop;
    int current_char;
    int space_fill = 0;
    int space_count = 0;

    while ((current_char = *in++) && current_char != '\0') {
        if (current_char == ' ') {
            space_count++;
            *out = current_char;
            out++;
        } else if (current_char == '\t') {
            if (ts_count > 0) {
                current_tabstop = *tabstops;
                tabstops++;
                ts_count--;
            } else {
                current_tabstop = DEFAULT_TABSTOP;
            }

            space_fill = current_tabstop - space_count % current_tabstop;

            while (space_fill > 0) {
                *out = ' ';
                out++;
                space_fill--;
            }

            space_count = 0;
        } else {
            space_count = 0;
            *out = current_char;
            out++;
        }
    }

    *out = '\0';
}

void detab(char *in, char *out, int *tabstops, int ts_count) {
    int current_tabstop;
    int current_char;
    int space_count = 0;
    int space_fill = 0;
    int tabchar_fill = 0;

    while ((current_char = *in++) && current_char != '\0') {
        if (current_char == ' ') {
            space_count++;
        } else {
            if (ts_count > 0) {
                current_tabstop = *tabstops;
            } else {
                current_tabstop = DEFAULT_TABSTOP;
            }
            
            space_fill = space_count % current_tabstop;
            tabchar_fill = space_count / current_tabstop;

            if (tabchar_fill > 0) {
                ts_count--;
                tabstops++;
            }

            while (tabchar_fill > 0) {
                *out = '\t';
                out++;
                tabchar_fill--;
            }

            while (space_fill > 0) {
                *out = ' ';
                out++;
                space_fill--;
            }

            space_count = 0;

            *out = current_char;
            out++;
        }
    }

    *out = '\0';
}



