#include <assert.h>
#include <stdio.h>
#include "calc.h"

int foo(void);

void test_add(void)
{
    assert(add(1,2) == 3);
    assert(add(5,2) == 7);
}

void test_subtract(void)
{
    assert(subtract(5,4) == 1);
}

void test_multiply(void)
{
    assert(multiply(3,3) == 9);
}

void test_divide(void)
{
    assert(divide(6,2) == 3);
}

int foo(void)
{
    printf("was here\n");
    return 'b';
}

void test_getinput(void) {
    my_getchar = &foo;
    my_getchar();
}

int main()
{
    test_add();
    test_subtract();
    test_multiply();
    test_divide();
    test_getinput();
}
