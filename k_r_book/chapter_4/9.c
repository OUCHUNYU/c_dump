#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MATH_OP '1'
#define MAXVAL 100
#define BUFSIZE 1 
#define MAX_STACK_VAR_NAME 36
#define MAXVARS 100

int getop(char s[]);
int getch();
void ungetch(int c);
void ungets(char *s);

struct s_var {
    char name[MAX_STACK_VAR_NAME];
    double value;
};

/*
 * Stack functions
 */
void push(double d);
double pop();
void print_top();
void swap_top_two();
void stack_clear();
void parse_math_op(char *op);
void get_var(char *name);

/*
 * states
 */
int sp = 0;
double val[MAXVAL];
int buf[BUFSIZE];
int bufp = 0;
struct s_var last_var;
int var_position = 0;
struct s_var var[MAXVARS];

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case MATH_OP:
                parse_math_op(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push(fmod(pop(), op2));
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                break;
            case '?':
                print_top();
                break;
            case '@':
                swap_top_two();
                break;
            case '!':
                stack_clear();
                break;
            case '=':
                var[var_position].value = pop();
                last_var.value = var[var_position].value;
                push(last_var.value);
                printf("assign %s with value %lf\n", last_var.name, last_var.value);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

void push(double d) {
    if (sp < MAXVAL) {
        val[sp++] = d;
    } else {
        printf("error: stack full, can't push %g\n", d);
    }
}

double pop() {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void print_top() {
    if (sp > 0) {
        printf("Top element of the stack: %lf\n", val[sp - 1]); 
    } else {
        printf("error: stack empty\n");
    }
}

void swap_top_two() {
    double item1 = pop();
    double item2 = pop();

    push(item1);
    push(item2);
}

void stack_clear() {
    sp = 0;
    printf("Stack is cleared.\n");
}

void parse_math_op(char *op) {
   double op2;

   if(0 == strcmp(op, "sin")) {
       push(sin(pop()));
   } else if( 0 == strcmp(op, "cos")) {
       push(cos(pop()));
   } else if (0 == strcmp(op, "exp")) {
       push(exp(pop()));
   } else if(!strcmp(op, "pow")) {
       op2 = pop();
       push(pow(pop(), op2));
   } else {
       get_var(op);
   }
}

/*
 * search name in the var list, if found assign it to the last var
 * else make a new var and assign the new var to the last var for 
 * later operations.
 */
void get_var(char *name) {
    int var_i;
    for (var_i = 0; var[var_i].name[0] != '\0' && var_i < MAXVARS - 1; var_i++) {
        if (!strcmp(name, var[var_i].name)) {
            strcpy(last_var.name, name);
            last_var.value = var[var_i].value;
            push(var[var_i].value);
            var_position = var_i;
            return;
        }

        var_i++;
    }

    strcpy(var[var_i].name, name);
    strcpy(last_var.name, name);
    last_var.value = var[var_i].value;
    push(var[var_i].value);
    var_position = var_i;
}

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') { }

    s[1] = '\0';

    if (isalpha(c)) {
        i = 0;
        while (isalpha(s[++i] = c = getch())) { }
        s[i] = '\0';
        if (c != EOF) {
            ungetch(c);
        }
        return MATH_OP;
    }

    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    i = 0;

    if (c == '-') {
        int next = getch();
        if (!isdigit(next) && next != '.') {
            return c;
        }
        c = next;
    } else {
        c = getch();
    }

    s[++i] = c;

    if (isdigit(c)) {
       while (isdigit(s[++i] = c = getch())) { }
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) { }
    }

    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}

int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

void ungets(char *s) {
    for (int i = strlen(s) - 1; i > 0; i--) {
        ungetch(s[i]);
    }
}



