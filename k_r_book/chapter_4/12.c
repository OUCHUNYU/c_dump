#include <stdio.h>
#include <string.h>
#define MAX 10000

void itoa(char *a, int i, int *a_len);
void reverse(char *s);

int main() {
     
    char test_a[MAX];
    int test_i = -621838;
    int i = 0;

    itoa(test_a, test_i, &i);

    printf("itoa\n i = %d\n a = %s\n", test_i, test_a);

    return 0;
}

void itoa(char *a, int i, int *a_len) {
    int is_neg = 0;
    int is_entre = *a_len == 0;

    if (i < 0) {
        is_neg = 1;
        i = -i;
    }

    a[*a_len] = (i % 10) + '0';
    i /= 10;
    (*a_len)++;

    if (i == 0) {
        return;
    }

    itoa(a, i, a_len);

    if (is_neg) {
        a[*a_len] = '-';
        (*a_len)++;
    }
    
    if (is_entre) {
        a[*a_len] = '\0';
        reverse(a);
    }
}

void reverse(char *s) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}



