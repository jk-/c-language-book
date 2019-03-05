#include <stdio.h>

char* squeeze(char s[], int c);

int main()
{
    char taco[] = "taco";

    char* new = squeeze(taco, 't');
    printf("%s\n", new);

    return 0;
}


char* squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        printf("testing char:::");
        printf("%d\n", s[i]);
        // printf("%d\n", c);
        if (s[i] != c) {
            printf("Norm, (%c) %d\n", s[j], s[j]);
            printf("Plus 1, (%c) %d\n", s[j+1], s[j+1]);
            s[j++] = s[i];
            printf("After, (%c) %d\n", s[j], s[j]);
        }
    }
    s[j] = '\0';

    return s;
}
