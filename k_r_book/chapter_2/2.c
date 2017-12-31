#include <stdio.h>

int main() {
    int c,
        lim = 1000000;
    char s[lim];

    for (int i = 0; i < lim - 1; i++) {
        c = getchar();
        
        if (c == '\n' || c == EOF) {
            break;
        }

        s[i] = c;
    }

    printf("%s", s);
    
    return 0;
}
