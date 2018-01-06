#include <stdio.h>
# define MAX_CHAR 10000

/*
 * converts characters like newline and tab into visible
 * escape sequences like \n and \t as it copies the string t to s.
 */

void escape(char *s, char *t);
void reverse_escape(char *s, char *t);

int main() {

    char *test = "fff   ddd \n \n ddd";
    char escaped[MAX_CHAR];
    char reverse_escaped[MAX_CHAR];

    escape(escaped, test);
    printf("escaped: %s\n", escaped);

    reverse_escape(reverse_escaped, escaped);
    printf("reverse escaped: %s\n", reverse_escaped);

    return 0;
}

void escape(char *s, char *t) {
    int c;
    int i = 0,
        j = 0;
    while ((c = t[i]) != '\0') {
        switch (c) {
            case 9:
                s[j] = '\\';
                s[++ j] = 't';
                break;
            case '\n':
                s[j] = '\\';
                s[++ j] = 'n';
                break;
            default:
                s[j] = c;
                break;
        }
       
        j ++;
        i ++;
    }

}

void reverse_escape(char *s, char *t) {
    int c;
    int next_c;
    int i = 0,
        j = 0;

    while ((c = t[i]) != '\0') {
        int is_next_null = t[i + 1] == '\0';
        int is_c_not_slash = c != '\\';

        if (is_next_null || is_c_not_slash) {
            s[j] = c;
            i ++;
            j ++;
            continue;
        }

        i ++;
        next_c = t[i];

        switch (next_c) {
            case 'n':
                s[j] = '\n';
                break;
            case 't':
                s[j] = '\t';
                break;
            default:
                s[j] = c;
                j ++;
                s[j] = next_c;
                break;
        }

        i ++;
        j ++;
    }

}
