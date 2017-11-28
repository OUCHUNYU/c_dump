//
// Created by Chunyu Ou on 11/12/17.
//

#include <stdio.h>
#include "exercise_runner.h"

void run_exercise(int exercise_num, void (*exercise)()) {
    printf("*********** exercise %d **************\n\n", exercise_num);
    (*exercise)();
    printf("\n*************************************\n\n");
}