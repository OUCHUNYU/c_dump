#include <stdio.h>
#include <string.h>

void reverse(char *s);

int main() {
   
    char test[1000];
    strcpy(test, "hello");
    reverse(test);

    printf("%s\n", test);

    return 0;
}

void reverse(char *s) {
    int len = strlen(s);

    if (len <= 1) {
        return;
    }
    
    int i0 = s[0];
    reverse(s + 1);

    for (int i = 1; i < len; i++) {
        s[i - 1] = s[i];
    }

    s[len - 1] = i0;
}
