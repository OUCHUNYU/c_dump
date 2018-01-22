#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT_TABSTOP 8
#define MAX_TABSTOPS 10
#define MAX_LINE 10000

void parse_tabstops(int argc, char *argv[], int *arguments);
int fetch_line(char *line, int max_char_count);
void entab(char *in, char *out, int *tabstops);
void detab(char *in, char *out, int *tabstops);

int main(int argc, char *argv[]) {
    int user_provided_tabstops[MAX_TABSTOPS] = {0};

    parse_tabstops(argc, argv, user_provided_tabstops);

    for (int i = 0; i < MAX_TABSTOPS; i++) {
        printf("argument %i: %i\n", i, user_provided_tabstops[i]);
    }

    // char current_line[10000];
    // char output_line[10000];
    // 
    // while (fetch_line(current_line, MAX_LINE) > 0) {
    //     puts("-------------- start -----------------\n");
    //     printf("original: %s\n", current_line);
    //     entab(current_line, output_line, user_provided_tabstops);
    //     printf("entabed: %s\n", output_line);
    //     entab(current_line, output_line, user_provided_tabstops);
    //     printf("detabed: %s\n", output_line);
    //     puts("--------------- end ------------------\n");
    // }

    return 0;
}

void parse_tabstops(int argc, char *argv[], int *arguments) {
    // skip file name part
    argc--;
    argv++;

    if (argc <= 0) {
        return;
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

    for (i = 0; (current_c = *(tabstop_list + i)) != '\0'; i++) {
        if (current_c != ',' && !isdigit(current_c)) {
            puts("Invalid argument\n"); 
            exit(-1); 
        } else if (current_c != ',' && isdigit(current_c)) {
            continue;
        } else {
            strncpy(found_tabstop_str, tabstop_list + last_found_index, i - last_found_index);
            *(found_tabstop_str + i - last_found_index) = '\0'; // add a terminator to copied str
            printf("copied str: %s\n", found_tabstop_str);
            last_found_index = i + 1;
            *arguments = atoi(found_tabstop_str);            
            arguments++;
        }
    }
    // add last num before \0
    strncpy(found_tabstop_str, tabstop_list + last_found_index, i - last_found_index);
    *(found_tabstop_str + i - last_found_index) = '\0';
    printf("copied str: %s\n", found_tabstop_str);
    *arguments = atoi(found_tabstop_str);            
}


