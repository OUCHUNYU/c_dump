#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 5000

static int numeric = 0;
static int reverse = 0;
static int case_insensitive = 0;

void parse_flags(int argc, char *argv[], int index);
int _getline(char *s, int lim);
int _readlines(char *lineptr[], int nline);
void _writelines(char *lineptr[], int nline);
void _swap(void *v[], int i, int j);
int _numcmp(const char *, const char *);
int _strcmp_case_insensitive(const char *, const char *);
void _qsort(void *lineptr[], int left, int right,
        int (*comp)(const void *, const void *), int reverse);

int main(int argc, char *argv[]) {
    
    int nlines;
    char *lineptrs[MAXLINE];

    for (int counter = 1; counter < argc; counter++) {
        parse_flags(argc, argv, counter);
    }

    printf("numeric: %i, reverse: %i, case: %i\n", numeric, reverse, case_insensitive);

    if ((nlines = _readlines(lineptrs, MAXLINE)) >= 0) {
        int (*function_p)(const char *, const char *) = strcmp;

        if (numeric) {
            function_p = _numcmp;
        } else if (case_insensitive) {
            function_p = _strcmp_case_insensitive;
        }

        _qsort((void **) lineptrs, 0, nlines - 1, (int (*)(const void *, const void *))function_p, reverse);
        _writelines(lineptrs, nlines);
    } else {
        printf("error!\n");
        return 1;
    }

    return 0;
}

void parse_flags(int argc, char *argv[], int index) {
    char *arg = argv[index];

    if (strcmp(arg, "-n") == 0) {
        numeric = 1;
    } else if (strcmp(arg, "-r") == 0) {
        reverse = 1;
    } else if (strcmp(arg, "-f") == 0) {
        case_insensitive = 1;        
    } else if (strcmp(arg, "-rn") == 0 || strcmp(arg, "-nr") == 0) {
        reverse = 1;
        numeric = 1;
    } else if (strcmp(arg, "-rf") == 0 || strcmp(arg, "-fr") == 0) {
        reverse = 1;
        case_insensitive = 1;
    } else if (strcmp(arg, "-nf") == 0 || strcmp(arg, "-fn") == 0) {
        numeric = 1;
        case_insensitive = 1;
    } else if (strcmp(arg, "-rnf") == 0 || strcmp(arg, "-rfn") == 0 
            || strcmp(arg, "-nrf") == 0 || strcmp(arg, "-nfr") == 0
            || strcmp(arg, "-frn") == 0 || strcmp(arg, "-fnr") == 0) {
        numeric = 1;
        reverse = 1;
        case_insensitive = 1;
    }
}

int _getline(char *s, int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

int _readlines(char *lineptr[], int nline) {
    int len, nlines = 0;
    char *p;
    char line_buf[10000];
    while ((len = _getline(line_buf, 10000)) > 0) {
        line_buf[len - 1] = '\0';
        p = malloc(len);
        strcpy(p, line_buf);
        lineptr[nlines++] = p;
    }
     
    return nlines;
}

void _writelines(char *lineptr[], int nline) {
    for (int i = 0; i < nline; i++) {
        printf("%s\n", lineptr[i]);
    }
}

int _numcmp(const char *s1, const char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}

int _strcmp_case_insensitive(const char *str1, const char *str2) {
    int c1, c2, result;

    while ((c1 = *(str1++)) != '\0') {
        c2 = *(str2++);
        result = c1 - c2;
        if (result != 0) {
            return result;
        }
    }

    return result;
}

void _qsort(void *lineptr[], int left, int right,
        int (*comp)(const void *, const void *), int reverse) {
    int i, last;
    
    if (left >= right) {
        return;
    }
    _swap(lineptr, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (reverse) {
            if ((*comp)(lineptr[i], lineptr[left]) > 0) {
                _swap(lineptr, ++last, i);
            }
        } else {
            if ((*comp)(lineptr[i], lineptr[left]) < 0) {
                _swap(lineptr, ++last, i);
            }
        }
    }
    _swap(lineptr, left, last);
    _qsort(lineptr, left, last - 1, comp, reverse);
    _qsort(lineptr, last + 1, right, comp, reverse);
}

void _swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

