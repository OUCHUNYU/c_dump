#include <stdio.h>
#include <ctype.h>

int htoi(char *s);

int main () {

    char *test = "24E";

    printf("HEX: %s -> INT: %d\n", test, htoi(test));

    return 0;
}

int htoi(char *s) {
    int c;
    int i = 0;
    int result = 0;

    while ((c = s[i]) != '\0') {
        if (!isdigit(c) && !isupper(c)) {
            break;
        }
        
        if (isupper(c) && c > 70) {
            break;
        }

        if (isdigit(c)) {
            c = c - '0'; 
        } else {
            c = c - 'A' + 10; 
        }
        
        result = 16 * result + c;
        i ++;
    }

    return result;
}
