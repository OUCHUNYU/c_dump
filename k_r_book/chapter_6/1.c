#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR_CACHE_SIZE 10000
#define MAX_WORD_SIZE 10000


int getch();
void ungetch(int ch);

int get_word(char *word_buff, int limit);
int is_underscore(int ch);
int handle_string_const(char *word_buff, int current_c, int *limit);
int handle_comment(char *word_buff, int current_c, int *limit);

int main(int argc, char *argv[]) {

	char word_buff[MAX_WORD_SIZE];

	while(1) {
		int result = get_word(word_buff, MAX_WORD_SIZE);
		printf("word --> %s\n", word_buff);
	}

	return 0;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int char_buff_index = 0;
char char_buff[MAX_CHAR_CACHE_SIZE];

int getch() {
	if (char_buff_index > 0) {
		return char_buff[char_buff_index--];
	}

	return getchar();
}

void ungetch(int ch) {
	if (char_buff_index >= MAX_CHAR_CACHE_SIZE) {
		printf("Error: ungetch exceed the max size allowed!\n");
		exit(EXIT_FAILURE);
	}

	char_buff[++char_buff_index] = ch;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

int get_word(char *word_buff, int limit) {
	int current_c;
	int limit_copy = limit;

	while (isspace(current_c = getch())) {
		// NOP
	}

	if (current_c != EOF) {
		*word_buff = current_c;
		word_buff++;
	}

	if (handle_string_const(word_buff, current_c, &limit)) {
		return current_c;
	}

	if (handle_comment(word_buff, current_c, &limit)) {
		return current_c;
	}

	if (!isalpha(current_c) && !is_underscore(current_c)) {
		*word_buff = '\0';
		return current_c;
	}

	for (; --limit > 0; word_buff++) {
		if (!isalnum(*word_buff = getch()) && !is_underscore(*word_buff)) {
			ungetch(*word_buff);
			break;
		}
	}

	*word_buff = '\0';
	return word_buff[0];
}

int is_underscore(int ch) {
	return ch == '_';
}

int handle_string_const(char *word_buff, int current_c, int *limit) {
	// early exit if not a ", return the same char back so the checking can continue
	if (current_c != '\"') {
		return 0;
	}

	for (; --(*limit) > 0; word_buff++) {
		*word_buff = getch();
		if (*word_buff == '\"') {
			break;
		}
	}

	if (*word_buff != '\"') {
		printf("Error: ungetch exceed the max size allowed but still no ending \" \n");
		exit(EXIT_FAILURE);
	}

	*(++word_buff) = '\0';
	return 1;
}

int handle_comment(char *word_buff, int current_c, int *limit) {
	if (current_c != '/') {
		return 0;
	}

	int next_char = getch();
	if (next_char != '/') {
		ungetch(next_char);
		return 0;
	}

	*(word_buff++) = next_char;

	for (; --(*limit) > 0; word_buff++) {
		*word_buff = getch();
		if (*word_buff == '\n') {
			break;
		}
	}

	if (*word_buff != '\n') {
		printf("Error: ungetch exceed the max size allowed but still no new line in comment\n");
		exit(EXIT_FAILURE);
	}

	*word_buff = '\0';
	return 1;
}



