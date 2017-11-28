//
// Created by Chunyu Ou on 11/12/17.
//

#include "exercise_helpers/exercise_runner.h"
#include "basic_exercises/exercise_1.h"
#include "basic_exercises/exercise_2.h"
#include "basic_exercises/exercise_3.h"
#include "basic_exercises/exercise_4.h"
#include "basic_exercises/exercise_5.h"
#include "basic_exercises/exercise_6.h"
#include "basic_exercises/exercise_7.h"
#include "basic_exercises/exercise_8.h"

int main() {

    run_exercise(1, &exercise_1);
    run_exercise(2, &exercise_2);
    run_exercise(3, &exercise_3);
    run_exercise(4, &exercise_4);
    run_exercise(5, &exercise_5);
    run_exercise(6, &exercise_6);
    run_exercise(7, &exercise_7);
    run_exercise(8, &exercise_8);

    return 0;
}

