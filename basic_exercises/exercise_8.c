//
// Created by Chunyu Ou on 11/18/17.
//

/**
 * Write a C program to convert specified days into years, weeks and days.
 *
 * Test Data:
 * Number of days: 1329
 *
 * Expected Output:
 * Years: 3
 * Weeks: 33
 * Days: 3
 */

#include <stdio.h>
#include "exercise_8.h"

void break_down_days_in_ywd(const int *days) {
    int years = *days / 365;
    int year_mod = *days % (365 * years);
    int weeks = year_mod / 7;
    int remained_days = year_mod % (weeks * 7);
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d\n", remained_days);
}

void exercise_8() {
    int total_days = 1329;
    break_down_days_in_ywd(&total_days);
}