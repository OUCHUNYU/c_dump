#include <stdio.h>
#include <string.h>

void _strncpy(char *s, const char *t, int n);
void _strncat(char *s, const char *t, int n);
int _strncmp(char *s, const char *t, int n);

int main() {

    char test1[100];
    char *target1 = "haha, ni hao ma";
    _strncpy(test1, target1, strlen(target1));
    printf("test _strncpy: expect test1 is %s\n", test1);

    return 0;
}


void _strncpy(char *s, const char *t, int n) {

}

void _strncat(char *s, const char *t, int n) {

}

int _strncmp(char *s, const char *t, int n) {
    return 1;
}
