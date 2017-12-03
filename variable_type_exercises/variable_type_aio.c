//
// Created by Chunyu Ou on 11/30/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

/**
 * Write a C program to convert a string to a long integer.
 */
static void exercise_3() {
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

/**
 * Write a C program to convert a string to a double.
 */
static void exercise_4() {
    char *data = "20.30300 hahaha";

    double target = strtod(data, NULL);
    printf("\n Got a double from a string: %lf\n", target);
}

/**
 * Write a C program to generate a random number.
 */
static void exercise_5() {
    srand((unsigned int) time(0));
    printf("\n\n");
    for (int i = 0; i < 5; i++) {
        printf("random %d: %d\n", i, rand() % 100);
    }
    printf("\n\n");
}

int compare_int(const void *x, const void *y) {
    return *(int *)x > *(int *)y;
}

static void exercise_6() {
    int data[5] = {15, 26, 42, 82, 35};
    size_t data_size = sizeof(data) / sizeof(data[0]);
    qsort(data, data_size, sizeof(data[0]), &compare_int);
    printf("\nAfter quick sort\n");
    for (int i = 0; i < data_size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void variable_type_aio() {
    printf("<<<<<<<<<<<< Variable Types <<<<<<<<<<<<\n\n");
    exercise_2();
    exercise_3();
    exercise_4();
    exercise_5();
    exercise_6();
    printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
}