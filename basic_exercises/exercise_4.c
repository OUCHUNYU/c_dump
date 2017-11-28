//
// Created by Chunyu Ou on 11/16/17.
//

/**
 * Write a C program to print the following characters in a reverse way.
 * Test Characters: 'X', 'M', 'L'
 *
 * Expected Output:
 * The reverse of XML is LMX
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercise_4.h"

char *reverse_str(const char *target_str, size_t size) {
    char *result = malloc(size);

    for (int i = 0; i < size; i++) {
        result[i] = target_str[size - sizeof(char) - i];
    }

    return result;
}

void exercise_4() {
    char *string = "XML";
    printf(reverse_str(string, strlen(string)));
}