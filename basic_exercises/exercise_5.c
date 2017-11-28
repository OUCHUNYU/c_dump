//
// Created by Chunyu Ou on 11/18/17.
//

/**
 * Write a C program to compute the perimeter and area of a rectangle with a height of 7 inches. and width of 5 inches.
 *
 * Expected Output:
 * Perimeter of the rectangle = 24 inches
 * Area of the rectangle = 35 square inches
 */

#include <stdio.h>
#include "exercise_5.h"

int get_rectangle_perimeter(const int *width, const int *height) {
    return (*width + *height) * 2;
}

int get_rectangle_area(const int *width, const int *height) {
    return (*width) * (*height);
}

void exercise_5() {
    int width = 5;
    int height = 7;

    int perimeter = get_rectangle_perimeter(&width, &height);
    int area = get_rectangle_area(&width, &height);

    printf("Perimeter of the rectangle = %d inches\n", perimeter);
    printf("Area of the rectangle = %d square inches\n", area);
}