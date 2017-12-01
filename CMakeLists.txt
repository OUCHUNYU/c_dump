cmake_minimum_required(VERSION 3.8)
project(c_dump)

set(CMAKE_C_STANDARD 99)

set(
        SOURCE_FILES
        main.c
        exercise_helpers/exercise_runner.c exercise_helpers/exercise_runner.h
        basic_exercises/exercise_1.c basic_exercises/exercise_1.h
        basic_exercises/exercise_2.c basic_exercises/exercise_2.h
        basic_exercises/exercise_3.c basic_exercises/exercise_3.h
        basic_exercises/exercise_4.c basic_exercises/exercise_4.h
        basic_exercises/exercise_5.c basic_exercises/exercise_5.h
        basic_exercises/exercise_6.c basic_exercises/exercise_6.h
        basic_exercises/exercise_7.c basic_exercises/exercise_7.h
        basic_exercises/exercise_8.c basic_exercises/exercise_8.h
        basic_exercises/exercise_aio.c basic_exercises/exercise_aio.h
        variable_type_exercises/variable_type_aio.c variable_type_exercises/variable_type_aio.h
)

add_executable(c_dump ${SOURCE_FILES})