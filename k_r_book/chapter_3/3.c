#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(char *s1, char *s2);

int main() {
    char *test = "Expand a to z:\na-z\n-a-z\nA-Z0-9\na-f-j\n";
    char expanded[1000];

    expand(test, expanded);

    printf("Test data: \n%s", test);
    printf("-------------------------------------\n");
    printf("\n\nExpanded data:\n%s", expanded);

    return 0;
}

void expand(char *s1, char *s2) {
    int s1_len = strlen(s1);
    int i, j;
    int c, left, right;

    for (i = 0, j = 0; i < s1_len; i ++, j ++) {
        c = s1[i];

        int not_dash = c != '-';
        int no_left_or_right = (i < 1) || ((i + 1) >= s1_len);
        if (not_dash || no_left_or_right) {
            s2[j] = c;
            continue;
        }

        right = s1[i + 1];
        left = s1[i - 1];
        int wrong_order = left >= right;
        if (!isalnum(right) || !isalnum(left) || wrong_order) {
            s2[j] = c;
            continue;
        }

        int ascii_off_set = right - left;
        for (int in_i = 1; in_i < ascii_off_set; in_i ++) {
            c = left + in_i;
            s2[j] = c;
            j ++;
        }
       
        j -= 1;
    }

}
