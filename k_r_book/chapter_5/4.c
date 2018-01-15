#include <stdio.h>
#include <string.h>

int strend(char *s, const char *t);

int main() {

    char *test = "haha my name is";
    char *target = "is";

    int result = strend(test, target);

    (result == 1) ? printf("yes\n") : printf("no\n");

    return 0;
}

int strend(char *s, const char *t) {
    int result = 1;

    int s_len = strlen(s);
    int t_len;
    for (t_len = strlen(t) - 1; t_len >= 0; t_len--) {

        printf("s -> %c, t -> %c\n", s[s_len - 1], t[t_len]);
        if (t[t_len] != s[--s_len]) {
            result = 0;
            break;
        }
    }

    return result;
}
