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
	char *temp_word = word_buff;
	int limit_copy = limit;

	while (isspace(current_c = getch())) {
		// NOP
	}

	if (current_c != EOF) {
		*temp_word = current_c;
		temp_word++;
	}
	
	current_c = handle_string_const(temp_word, current_c, &limit);

	// TODO: handle comments like // or /* */

	if (!isalpha(current_c) && !is_underscore(current_c)) {
		*(temp_word += (limit_copy - limit)) = '\0';
		return current_c;
	}

	for (; --limit > 0; temp_word++) {
		if (!isalnum(*temp_word = getch()) && !is_underscore(*temp_word)) {
			ungetch(*temp_word);
			break;
		}
	}

	*temp_word = '\0';
	return word_buff[0];
}

int is_underscore(int ch) {
	return ch == '_';
}

int handle_string_const(char *word_buff, int current_c, int *limit) {
	// early exit if not a ", return the same char back so the checking can continue
	if (current_c != '\"') {
		return current_c;
	}

	// *word_buff = current_c;
	// word_buff++;
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

	int result = *word_buff;
	word_buff++;
	return result;
}



