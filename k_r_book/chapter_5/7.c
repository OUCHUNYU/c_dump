#include <stdio.h>
#include <string.h>
#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSTORE 100000

char *lineptr[MAXLINES];

int myreadlines(char *lineptr[], int maxlines, char *line_buf);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int _getline(char *s, int lim);

int main() {
    int nlines;
    char linestore[MAXSTORE]; /* array for storing all lines */
    /* myreadlines will pass an extra parameter linestore for storing all the input lines */
    if ((nlines = myreadlines(lineptr, MAXLINES, linestore)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}


int myreadlines(char *lineptr[], int maxlines, char *line_buf) {
    int len, nlines = 0;
    char *p;

    while ((len = _getline(line_buf, MAXLEN)) > 0) {
        if (nlines >= maxlines) {
            return -1;
        }
        line_buf[len - 1] = '\0';
        strcpy(p, line_buf);
        lineptr[nlines++] = p;
        line_buf += len;
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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
