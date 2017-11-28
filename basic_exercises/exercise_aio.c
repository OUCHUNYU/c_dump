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

    if (*total - amount_copy < 0) {
        printf("%d Note(s) of %f \n", 0, *amount * 1.00);
        return;
    }

    while (!stop) {
        if (*total - amount_copy < *amount) {
            stop = true;
            continue;
        }

        times ++;
        amount_copy = *amount * times;
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

void print_seconds_in_h_m_s(const int *total_sec) {
    int total_sec_copy = *total_sec;
    int hour = 0;
    int minute = 0;

    while (total_sec_copy >= 3600) {
        hour += 1;
        total_sec_copy -= 3600;
    }

    while (total_sec_copy >= 60) {
        minute += 1;
        total_sec_copy -= 60;
    }

    printf("\nH:M:S - %d:%d:%d\n", hour, minute, total_sec_copy);
}

// aio runner function
void exercise_aio() {
    int exercise_16_input_data = 375;
    print_bank_note(&exercise_16_input_data);

    int exercise_17_input_data = 25300;
    print_seconds_in_h_m_s(&exercise_17_input_data);
}