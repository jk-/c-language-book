#include <stdio.h>
#include "calc.h"

int (* my_getchar)(void);

float add(float x, float y)
{
    return x + y;
}

float subtract(float x, float y)
{
    return x - y;
}

float multiply(float x, float y)
{
    return x * y;
}

float divide(float x, float y)
{
    return x / y;
}

void taco_bell() {
    int c;
    c = my_getchar();
    printf("%d\n", c);
}
