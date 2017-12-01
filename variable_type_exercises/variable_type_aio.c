//
// Created by Chunyu Ou on 11/30/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "variable_type_aio.h"


/**
 * Write a C program to convert a string to an unsigned long integer.
 *
 * For example:
 * given string "2001 haha"
 * expecting unsigned long 2001
 *
 * function reference:
 *
 * char *fgets(char *str, int n, FILE *stream)
 * unsigned long int strtoul(const char *str, char **endptr, int base)
 *
 */
static void exercise_2() {
    char *data = "2000 is an important year.";
    char *sentence;
    unsigned long target;
    target = strtoul(data, &sentence, 0);

    printf("\nPrinting unsigned long from a string %lu\n", target);
    printf("The reset of the string is \"%s\"", sentence);
}

void variable_type_aio() {
    printf("<<<<<<<<<<<< Variable Types <<<<<<<<<<<<\n\n");

    exercise_2();

    printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
}