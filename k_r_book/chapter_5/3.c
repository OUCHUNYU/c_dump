#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _strcat(char *s, char *t);

int main() {
    char test1[100] = {"hi, "};
    char test2[100] = {"my name is."};

    _strcat(test1, test2);

    printf("%s\n", test1);

    return 0;
}

void _strcat(char *s, char *t) {
    int s_len = strlen(s);
    int t_len = strlen(t);

    for (int i = 0; i < t_len; i++) {
        s[s_len + i] = t[i];
    }
}
