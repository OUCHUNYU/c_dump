#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {
    
    char *test_1 = "123.456";
    char *test_2 = "123.45e-6";

    printf("test %s: %lf\n", test_1, atof(test_1));
    printf("test %s: %lf\n", test_2, atof(test_2));

    return 0;

}

double atof(char s[]) {
    int i, sign;
    double val, power;

    for (i = 0; isspace(s[i]); i++) {
    }

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    val = sign * val / power;

    if (s[i] == 'e') {
        i++;
        int after_e = s[i];
        i++;
        int counter = s[i] - '0';
        power = 1.0;
        while (counter > 1) {
            power *= 10.0;    
            counter--;
        }

        if (after_e == '-') {
            val /= power;
        } else if (after_e == '+') {
            val *= power;
        }
    }

    return val;
}


