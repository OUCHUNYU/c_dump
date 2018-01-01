#include <stdio.h>
#include <string.h>

int any(char *s1, char *s2);

int main() {

    char s1[] = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    char s2[] = "z a b";

    printf("found at location %d\n", any(s1, s2));

    return 0;
}

int any(char *s1, char *s2) {
    int result = -1;

    int found = 0;

    int i, j;

    for (i = 0; s1[i] != '\0'; i ++) {

        for (j = 0; s2[j] != '\0'; j ++) {
            if (s1[i] != s2[j]) {
                continue;
            }
            found = 1;
            break;
        }

        if (found) {
            result = i;
            break;
        }

    }

    return result;
}
