#include <stdio.h>

int strindex(char s[], char t[]);

int main() {
    
    char *test = "123, haha, there is something to see, haha";
    char *target = "haha";

    int result = strindex(test, target);

    printf("%d\n", result);

    return 0;
}

int strindex(char s[], char t[]) {
    int result = -1;
    
    int i, j, k;
    for (i = 0; s[i] != '\0'; i ++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
        }
        if (k > 0 && t[k] == '\0') {
            result = i;
        }
    }

    return result;
}
