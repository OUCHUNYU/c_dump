#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STACK 1000

static double operand_stack[MAX_STACK];
static int current_operand_stack_index = -1;

void push(double operand);
double pop();

int main(int argc, char *argv[]) {
    argv++;
    argc--;
    if (argc > MAX_STACK) {
        printf("stack overflow!");
        return -1;
    }

    if (argc < 1) {
        return 0;
    }
    // skip the program name
    int is_operator = 0;
    double right, left;

    while (argc > 0) {
        switch (**argv) {
            case '+':
                right = pop();
                left = pop();
                push(left + right);
                is_operator = 1;
                break;
            case '-':
                right = pop();
                left = pop();
                push(left - right);
                is_operator = 1;
                break;
            case '^':
                right = pop();
                left = pop();
                push(left * right);
                is_operator = 1;
                break;
            case '/':
                right = pop();
                left = pop();
                push(left / right);
                is_operator = 1;
                break;
            default:
                is_operator = 0;
                break;
        }

        if (is_operator) {
            argv++;
            argc--;
            continue;
        }

        for (int i = 0; *((*argv) + i) != '\0'; i++) {
            if (isdigit(*((*argv) + i)) || (*((*argv) + i) == '.')) {
                continue;
            }
            return -1;
        }

        push(atof(*argv));
        argv++;
        argc--;
    }

    printf("result: %lf\n", pop());

    return 0;
}

void push(double operand) {
    current_operand_stack_index++;
    operand_stack[current_operand_stack_index] = operand;
    printf("push to index: %i with operand: %lf\n", current_operand_stack_index, operand);
}

double pop() {
    if (current_operand_stack_index < 0) {
        exit(-1);
    }
    printf("pop to index: %i with operand: %lf\n", current_operand_stack_index - 1, operand_stack[current_operand_stack_index - 1]);
    double temp = operand_stack[current_operand_stack_index];
    current_operand_stack_index--;
    return temp;
}

