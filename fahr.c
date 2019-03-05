#include <stdio.h>

/* 1.4 Add constants */
#define LOWER   0
#define UPPER   300
#define STEP    20

/* print Fahrenhheit-Celsius table
    for fahr = 0, 20, ..., 300 */
int main()
{
    int fahr;

    /* here we eliminated all of the varaible
        assignments and just used a for loop */
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
