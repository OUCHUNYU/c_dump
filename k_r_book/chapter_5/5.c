#include <stdio.h>
#include <string.h>

void _strncpy(char *s, const char *t, int n);
void _strncat(char *s, const char *t, int n);
int _strncmp(char *s, const char *t, int n);

int main() {

    char test1[100];
    char *target1 = "haha, ni hao ma";
    _strncpy(test1, target1, strlen(target1));
    printf("test _strncpy: %s\n", test1);

    char test2[100] = {"lala haha."};
    char test3[100] = {"dada wawa."};
    _strncat(test2, test3, strlen(test3));
    printf("test _strncat: %s\n", test2);
    
    char test4[100] = {"hello there"};
    char test5[100] = {"hello there, nothing"};
    int result = _strncmp(test4, test5, strlen(test4));
    printf("test _strncmp: %i\n", result);

    return 0;
}


void _strncpy(char *s, const char *t, int n) {
    while (n > 0) {
        *s = *t;
        s++;
        t++;
        n--;
    }
}

void _strncat(char *s, const char *t, int n) {
    while (*s != '\0')
        s++;
    _strncpy(s, t, n);
}

int _strncmp(char *s, const char *t, int n) {
    while (n && *s && (*s == *t)) {
        s++;
        t++;
        n--;
    }
    if (n == 0) {
        return n;
    }
    return *(unsigned char *)s - *(unsigned char *)t;
}
