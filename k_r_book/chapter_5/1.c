#include <stdio.h>
#include <ctype.h>
#define BUFFERLENGTH 100

int getch(void);
void ungetch(int);
int getint(int *pn);

int main() {

    int *t;
    int result = getint(t);

    printf("%i\n", *t);

    return 0;
}

int buf[BUFFERLENGTH];
int nfp = 0;

int getch(void) {
	return (nfp > 0) ? buf[--nfp] : getchar();
}

void ungetch(int c) {
	if(nfp < BUFFERLENGTH)
		buf[nfp++] = c;
	else
		printf("error: ungetch buffer overflow\n");
}

int getint(int *pn) {
	int c, sign;
	while(isspace(c = getch()));
	if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
        return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-') {
		c = getch(); 
		if(!isdigit(c)) {
			ungetch(sign == -1 ? '-' : '+');
			return 0;
		}
	}
	for(*pn = 0; isdigit(c); c = getch())
		*pn = *pn * 10 + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

