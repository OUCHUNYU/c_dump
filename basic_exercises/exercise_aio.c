//
// Created by Chunyu Ou on 11/19/17.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "exercise_aio.h"


static int sum_two_int(const int *f, const int *s) {
    return *f + *s;
}

static int product_two_int(const int *f, const int *s) {
    return *f * *s;
}

static int calculate_salary(const int *employee_id, const float *hours, const double *per_din) {
    printf("Employees ID = %d\n", *employee_id);
    printf("Salary = U$ %lf\n", (*hours) * (*per_din));
}

static int find_max_in_three_int(const int *a, const int *b, const int *c) {
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

static double length_between_two_point(const int *x1, const int *y1, const int *x2, const int *y2) {
    int y = *y2 - *y1;
    int x = *x2 - *x1;
    return sqrt((y * y) + (x * x));
}

static void print_single_bank_note(int *total, const int *amount) {
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

static void print_bank_note(const int *total) {
    int total_copy = *total;
    int amount_type[7] = {100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < sizeof(amount_type) / sizeof(int); i++) {
        print_single_bank_note(&total_copy, &amount_type[i]);
    }
}

static void print_seconds_in_h_m_s(const int *total_sec) {
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

static void print_days_in_y_m_d(const int *days) {
    int total_days_copy = *days;
    int year = 0;
    int month = 0;

    while (total_days_copy >= 365) {
        year ++;
        total_days_copy -= 365;
    }

    while (total_days_copy >= 30) {
        month ++;
        total_days_copy -= 30;
    }

    printf("\n%d Year(s)\n", year);
    printf("%d Month(s)\n", month);
    printf("%d Day(s)\n\n", total_days_copy);
}

static void print_range(const int *input) {
    if (*input > 80 || *input < 0) {
        printf("ERROR: input is less than 0 or out of range");
        return;
    }

    int left_bound = 0;
    int right_bound = 20;
    bool found = false;

    while (!found) {
        if (*input >= left_bound && *input <= right_bound) {
            found = true;
        } else {
            left_bound += 20;
            right_bound += 20;
        }
    }

    printf("\nRange [%d, %d]\n\n", left_bound, right_bound);
}

static int add_odd_bin(int x, int y) {
    int start = x > y ? y : x;
    int end = x > y ? x : y;

    int total = 0;
    while (start < end) {
        if (start % 2 == 0) {
            total += start;
        }
        start ++;
    }
    return total;
}

static int add_odd(int a, int b, int c, int d, int e) {
    return add_odd_bin(a, b) + add_odd_bin(b, c) + add_odd_bin(c, d) + add_odd_bin(d, e);
}

static bool is_valid_triangle(float x, float y, float z) {
    return (x + y > z) && (x + z > y) && (z + y > x);
}

static void is_multiplied(int x, int y) {
    int left_o = x > y ? x : y;
    int right_o = x > y ? y : x;
    if (left_o % right_o == 0) {
        printf("\n\nMultiplied!\n");
    }
}

static long int rand_in_range(long min, long max) {
    long r;
    long range = max - min + 1;
    long bins = RAND_MAX / range;
    long limit = bins * range;

    do {
        r = random();
    } while (r >= limit);

    return min + (r / bins);
}

static void print_even_in_range(int min, int max) {
    while (min <= max) {
        if (min % 2 == 0) {
            printf("%d ", min);
        }
        min ++;
    }
}

static void print_p_and_n(int a, int b, int c, int d, int e) {
    int p = 0;
    int n = 0;
    int param_arr[5] = {a, b, c, d, e};
    for (int i = 0; i < 5; i++) {
        if (param_arr[i] > 0) {
            p ++;
        } else if (param_arr[i] < 0) {
            n ++;
        }
    }

    printf("\n\nNumber of positive numbers: %d\n", p);
    printf("Number of negative numbers: %d\n", n);
}

// aio runner function
void exercise_aio() {
    int exercise_16_input_data = 375;
    print_bank_note(&exercise_16_input_data);

    int exercise_17_input_data = 25300;
    print_seconds_in_h_m_s(&exercise_17_input_data);

    int exercise_18_input_data = 2535;
    print_days_in_y_m_d(&exercise_18_input_data);

    int exercise_21_input_data = 15;
    print_range(&exercise_21_input_data);

    printf("\n\nSum of all odd values: %d\n", add_odd(11, 17, 13, 12, 5));

    if (!is_valid_triangle(5, 7, 9)) {
        printf("\n\n\n\nFAILED VERY VERY HARD!\n\n\n\n");
        exit(EXIT_FAILURE);
    }

    is_multiplied(5, 15);
    is_multiplied(15, 5);

    printf("\n\nRandom month number %ld", rand_in_range(1, 12));

    printf("\n\n");
    print_even_in_range(1, 50);
    printf("\n\n");
    print_p_and_n(5, -4, 10, 15, -1);
}