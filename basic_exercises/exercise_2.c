//
// Created by Chunyu Ou on 11/12/17.
//

/*
 * Write a C program to print a block F using hash (#), where the F has a height of six characters and width of five
 * and four characters.
 *
 * Expected Output:
 * ######
 * #
 * #
 * #####
 * #
 * #
 * #
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercise_2.h"

static void print_hash(int count) {

    char *hash_str = malloc(count + 1 * sizeof(char));

    for (int i = 0; i < count; ++i) {
        strcat(hash_str, "#");

        if (i == count - 1) {
            strcat(hash_str, "\n");
        }
    }

    printf(hash_str);
}

static void print_hash_f() {
    int height = 6;
    int width_1 = 5;
    int width_2 = 4;

    for (int i = 0; i < height; ++i) {
        if (i == 0) {
            print_hash(width_1);
        } else if (i == 3) {
            print_hash(width_2);
        } else {
            print_hash(1);
        }
    }
}

void exercise_2() {
    print_hash_f();
}

