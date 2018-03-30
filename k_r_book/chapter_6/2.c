/*

Exercise 6-2. Write a program that reads a C program and prints in alphabetical 
order each group of variable names that are identical in the first 6 characters, 
but different somewhere thereafter. Don’t count words within strings and 
comments. Make 6 a parameter that can be set from the command line.

Solution:
make a structure to hold the group

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GROUP_ALLOWED 1000
#define MAX_GROUP_LIST_SIZE 1000

char *c_keywords[] = {
	"auto",
	"double",
	"int",
	"struct",
	"break",
	"else",
	"long",
	"switch",
	"case",
	"enum",
	"register",
	"typedef",
	"char",
	"extern",
	"return",
	"union",
	"const",
	"float",
	"short",
	"unsigned",
	"continue",
	"for",
	"signed",
	"void",
	"default",
	"goto",
	"sizeof",
	"volatile",
	"do",
	"if",
	"static",
	"while"
};

struct group {
	char *identical_chars;
	int identical_char_count;
	char *list[MAX_GROUP_LIST_SIZE];
};

int parse_arg(char *argv[]);
struct group *init_new_group(char *first_string, int count);
int check_identical(char *str1, char *str2, int count);
int is_variable(char *str);

int main(int argc, char *argv[]) {

	int default_identical_char_count = 6;

	if (argc > 1) {
		default_identical_char_count = parse_arg(argv);
	}

	struct group *ordered_groups[MAX_GROUP_ALLOWED];

	/* 
		import 1.c getword

		get a variable in each loop
		go through the groups and check if it belongs to any group
		if yes put it in that group
		else create a new group and put it in the groups

		at the end, go through the groups again to print each group
	*/

	return 0;
}

int parse_arg(char *argv[]) {
	int result = atoi(argv[1]);
	printf("Argument received, default identical character count is now %d\n", result);
	return result;
}







