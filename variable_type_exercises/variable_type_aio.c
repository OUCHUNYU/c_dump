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

static void exercise3() {
    char *data = "20093 2b4a2d 1001001001101001";
    char *next;
    long l_1, l_2, l_3;
    l_1 = strtol(data, &next, 10);
    l_2 = strtol(next, &next, 16);
    l_3 = strtol(next, &next, 2);

    printf("\n");
    printf("First parse base 10 long: %ld\n", l_1);
    printf("Second parse base 16(hex) long: %ld\n", l_2);
    printf("Third parse base 2(bin) long: %ld\n", l_3);
    printf("\n");
}

void variable_type_aio() {
    printf("<<<<<<<<<<<< Variable Types <<<<<<<<<<<<\n\n");
    exercise_2();
    exercise3();
    printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
}