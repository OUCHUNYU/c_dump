#include <stdio.h>
#include <string.h>


void squeeze(char *s1, char *s2);

int main() {
    
    char s1[] = "bbbb aaaaaaaaaaaaa hh aaaaaaaaaa bbbb\n";
    char s2[] = "ah";

    squeeze(s1, s2);

    printf("%s\n", s1);

    return 0;
}

void squeeze(char *s1, char *s2) {
    int i, j;
    int found = 0;
    int s2_len = strlen(s2);

    for (i = j = 0; s1[i] != '\0'; i++) {
        for (int k = 0; k < s2_len; k++) {
            if (s2[k] != s1[i]) {
                continue; 
            }
            found = 1;
            break;
        }

        if (found) {
            found = 0;
            continue;
        }

        s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
