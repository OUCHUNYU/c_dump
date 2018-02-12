#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 5000

char *lineptr[MAXLINE];

int _getline(char *s, int lim);
int _readlines(char *lineptr[], int nline);
void _writelines(char *lineptr[], int nline);
void _qsort(void *lineptr[], int left, int right,
        int (*comp)(const void *, const void *));
int _numcmp(const char *, const char *);
void _swap(void *v[], int i, int j);

int main(int argc, char *argv[]) {
    
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }

    if ((nlines = _readlines(lineptr, MAXLINE)) >= 0) {
        _qsort((void **) lineptr, 0, nlines - 1,
                (int (*)(const void *, const void *))(numeric ? _numcmp : strcmp));
        _writelines(lineptr, nlines);
    } else {
        printf("error!\n");
        return 1;
    }

    return 0;
}

int _getline(char *s, int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

int _readlines(char *lineptr[], int nline) {
    int i;
    int len = 0;
    char *p;
    char line_buf[10000];

    for (i = 0; i < nline && (len = _getline(line_buf, 10000)) > 0; i++) {
        line_buf[len - 1] = '\0';
        strcpy(p, line_buf);
        lineptr[i] = p;
    }
    
    return i;
}

void _writelines(char *lineptr[], int nline) {
    while (nline-- > 0)
        printf("%s\n", *lineptr++);
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

void _qsort(void *lineptr[], int left, int right,
        int (*comp)(const void *, const void *)) {

}

void _swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

