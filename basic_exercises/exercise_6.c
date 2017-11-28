//
// Created by Chunyu Ou on 11/18/17.
//

/**
 * Write a C program to compute the perimeter and area of a circle with a radius of 6 inches.
 * Expected Output:
 * Perimeter of the Circle = 37.680000 inches
 * Area of the Circle = 113.040001 square inches
 */

#include <stdio.h>
#include <math.h>
#include "exercise_6.h"

double get_circle_perimeter(const int *radius) {
    return 2 * M_PI * (*radius);
}

double get_circle_area(const int *radius) {
    return M_PI * (*radius) * (*radius);
}

void exercise_6() {
    int r = 6;

    double perimeter = get_circle_perimeter(&r);
    double area = get_circle_area(&r);

    printf("Perimeter of the Circle = %f inches\n", perimeter);
    printf("Area of the Circle = %f square inches\n", area);
}