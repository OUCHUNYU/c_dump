#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKEN 100
#define UNGET_BUFFER_LIMIT 1000

int _getch();
void _ungetch(int c);
int gettoken();
void dcl();
void dirdcl();

enum {
	NAME,
	PARENS,
	BRACKETS
};

static int tokentype;
static char token[MAXTOKEN];
static char name[MAXTOKEN];
static char datatype[MAXTOKEN];
static char out[1000];
static char unget_buffer[UNGET_BUFFER_LIMIT];
static int unget_buffer_index = 0;

// ************************************
int _getch() {
	if (unget_buffer_index <= 0) {
		return getchar();
	}

	return unget_buffer[unget_buffer_index--];
}

void _ungetch(int c) {
	unget_buffer_index++;

	if (unget_buffer_index > UNGET_BUFFER_LIMIT - 1) {
		printf("Unget buffer overflow\n");
		unget_buffer_index--;
		exit(1);
	}

	unget_buffer[unget_buffer_index] = c;
}

int gettoken() {
	int c;
	char *p = token;

	// Skip spaces and tabs from stdin
	while ((c = _getch()) == ' ' || c == '\t');

	if (c == '(') {
		if ((c = _getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		}

		_ungetch(c);
		return tokentype = '(';
	} 

	if (c == '[') {
		for (*(p++) = c; (*(p++) = _getch()) != ']'; );

		*p = '\0';
		return tokentype = BRACKETS;
	}

	if (isalpha(c)) {
		for (*(p++) = c; isalnum(c = _getch()); ) {
			*(p++) = c;
		}

		*p = '\0';
		_ungetch(c);
		return tokentype = NAME;
	} 

	return tokentype = c;
}

void dcl() {
	int ns;

	for (ns = 0; gettoken() == '*'; ) {
		ns++;
	}

	dirdcl();

	while (ns-- > 0) {
		strcat(out, "pointer to ");
	}
}

void dirdcl() {
	int type;

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')') {
			printf("Missing closing ')' \n");
		}
	} else if (tokentype == NAME) {
		strcpy(name, token);
	} else {
		printf("Unexpected name or (dcl)\n");
	}

	while ((type = gettoken()) == PARENS || type == BRACKETS) {
		if (type == PARENS) {
			strcat(out, " function returning");
		} else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}
// ************************************

int main(int argc, char *argv[]) {
	while (gettoken() != EOF) {
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n') {
			printf("Syntax error!\n");
		}
		printf("%s: %s %s\n", name, out, datatype);
	}

	return 0;
}











