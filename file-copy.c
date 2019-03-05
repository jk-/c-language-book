#include <stdio.h>

/* copy input to output; 1st version */
int main()
{
    int c;
    /* move c = getchar() into while loop */
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
