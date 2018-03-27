#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR_CACHE_SIZE 10000
#define MAX_WORD_SIZE 10000


int getch();
void ungetch(int ch);

int get_word(char *word_buff, int limit);

int main(int argc, char *argv[]) {

	char word_buff[MAX_WORD_SIZE];

	while(1) {
		int result = get_word(word_buff, MAX_WORD_SIZE);
		printf("word --> %s, result --> %d\n", word_buff, result);
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

	while (isspace(current_c = getch())) {
		// NOP
	}

	if (current_c != EOF) {
		*temp_word = current_c;
		temp_word++;
	}

	if (!isalpha(current_c)) {
		*temp_word = '\0';
		return current_c;
	}

	for (; --limit > 0; temp_word++) {
		if (!isalnum(*temp_word = getch())) {
			ungetch(*temp_word);
			break;
		}
	}

	*temp_word = '\0';
	return word_buff[0];
}








