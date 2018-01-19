#include <stdio.h>
#define MAX_GETLINE 100000

int _getline(char *line, int max);
void _reverse(char *s);
int _atoi(char *a);
void _itoa(char *a, int i);
int _strindex(char *s, char *t);

int main() {
    
    char test_getline[MAX_GETLINE]; 
    _getline(test_getline, MAX_GETLINE);
    printf("test _getline()\n%s", test_getline);
    
    _reverse(test_getline);
    printf("test _reverse()\n%s\n", test_getline);

    char test_itoa[100];
    int itoa_i = 1237409;
    _itoa(test_itoa, itoa_i);
    printf("test itoa()\ntest data: %i\nresult: %s\n", itoa_i, test_itoa);

    printf("test atoi()\nresult: %i\n", _atoi(test_itoa));

    char *test_strindex = "This is test for _strindex";
    char *target_strindex = "_strindex";
    int found_index = _strindex(test_strindex, target_strindex);
    if (found_index >= 0) {
        printf("_strindex found the index: %i\n", found_index);
    }

    return 0;
}

int _getline(char *line, int max) {
    int i = 0, c;

    while ((c = getchar()) && c != '\n' && c != EOF && i < max) {
        *line = c;
        line++;
        i++;
    } 

    if (c == '\n') {
        *line = '\n';
        line++;
        i++;
    }

    *line = '\0';

    return i;
}

void _reverse(char *s) {
    int index_counter = 0;

    while (*s != '\0') {
        s++;
        index_counter++;
    }

    s -= index_counter;

    int c, i, j;
    for (i = 0, j = index_counter - 1; i < j; i++, j--) {
        c = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = c;
    }
}

void _itoa(char *a, int i) {
    int counter = 0;
    while (i > 0) {
        *a = (i % 10) + '0';
        a++;
        i /= 10;
        counter++;
    }
    *a = '\0';
    a -= counter;
    _reverse(a);
}

int _atoi(char *a) {
    int result = 0;
    while (*a != '\0') {
        result = result * 10 + (*a - '0');
        a++;
    }
    return result;
}

int _strindex(char *s, char *t) {
    int result = -1;

    int i, j, k;
    for (i = 0; *(s + i) != '\0'; i++) {
        for (j = i, k = 0; *(t + k) != '\0' && *(s + j) == *(t + k); j++, k++) {
        }
        if (k > 0 && *(t + k) == '\0') {
            result = i;
        }
    }

    return result;
}

