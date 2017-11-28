//
// Created by Chunyu Ou on 11/19/17.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "exercise_aio.h"


int sum_two_int(const int *f, const int *s) {
    return *f + *s;
}

int product_two_int(const int *f, const int *s) {
    return *f * *s;
}

int calculate_salary(const int *employee_id, const float *hours, const double *per_din) {
    printf("Employees ID = %d\n", *employee_id);
    printf("Salary = U$ %lf\n", (*hours) * (*per_din));
}

int find_max_in_three_int(const int *a, const int *b, const int *c) {
    int max = 0;
    if (*a > max) {
        max = *a;
    }

    if (*b > max) {
        max = *b;
    }

    if (*c > max) {
        max = *c;
    }

    return max;
}

double length_between_two_point(const int *x1, const int *y1, const int *x2, const int *y2) {
    int y = *y2 - *y1;
    int x = *x2 - *x1;
    return sqrt((y * y) + (x * x));
}

void print_single_bank_note(int *total, const int *amount) {
    bool stop = false;
    int times = 1;
    int amount_copy = *amount;

    while (!stop) {
        if ((*total % times * amount_copy) < amount_copy) {
            stop = true;
            continue;
        }

        times ++;
        amount_copy = amount_copy * times;
    }

    *total = *total - amount_copy;
    printf("%d Note(s) of %f \n", times, *amount * 1.00);
}

void print_bank_note(const int *total) {
    int total_copy = *total;
    int amount_type[7] = {100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < sizeof(amount_type) / sizeof(int); i++) {
        print_single_bank_note(&total_copy, &amount_type[i]);
    }
}