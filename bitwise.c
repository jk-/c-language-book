#include <stdio.h>

/*

&   bitwise AND
|   bitwise inclusive OR
^   bitwise exclusive OR
<<  left shift
>>  right shift
~   one's complement unary

*/

void bitand(int x, int y);
void bitor(int x, int y);
void bitxor(int x, int y);
void leftshift(int x, int shift);
void rightshift(int x, int shift);
void bitnot(unsigned int x);

int main()
{
    /*
    16 8 4 2 1
             1
             << 2
         1 0 0 == 4
    */
    leftshift(1, 2);

    /*
    16 8 4 2 1
           1 1
             << 2
       1 1 0 0 == 12
    */
    leftshift(3, 2);

    /*
    16 8 4 2 1
         1 0 1
             << 2
     1 0 1 0 0 == 20
    */
    leftshift(5, 2);

    /*
    16 8 4 2 1
             1
             >> 1
             0 == 0
    */
    rightshift(1, 1);
    rightshift(1, 2);

    // 8?
    rightshift(16, 1);

    /*
    16 8 4 2 1
             1
           1 0
             &
             0
    */
    bitand(1, 2);

    /*
    16 8 4 2 1
         1 0 1
           1 0
             &
             0
    */
    bitand(5, 2);

    /*
    16 8 4 2 1
         1 1 1
           1 0
             &
           1 0 == 2
    */
    bitand(7, 2);

    /*
    16 8 4 2 1
             1
           1 0
             &
           1 1  ? 3
    */
    bitor(1, 2);

    /*
    16 8 4 2 1
         1 0 1
           1 0
             &
         1 1 1 == 7
    */
    bitor(5, 2);

    /*
    16 8 4 2 1
         1 1 1
           1 0
             &
         1 1 1 == 7
    */
    bitor(7, 2);

    /*
    16 8 4 2 1
             1
           1 0
             &
           1 1  ? 3
    */
    bitxor(1, 2);

    /*
    16 8 4 2 1
         1 0 1
           1 0
             &
         1 1 1 == 7
    */
    bitxor(5, 2);

    /*
    16 8 4 2 1
         1 1 1
           1 0
             &
         1 0 1 == 7
    */
    bitxor(7, 2);

    /*
    16 8 4 2 1
             1
           1 0
             &
           1 1  ? 3
    */
    bitnot(1);

    /*
    16 8 4 2 1
         1 0 1
           1 0
             &
         1 1 1 == 7
    */
    bitnot(5);

    /*
    16 8 4 2 1
         1 1 1
           1 0
             &
         1 0 1 == 7
    */
    bitnot(7);

    /*
    16 8 4 2 1
         1 0 0
    */
    long char taco = ~0;
    printf("%u\n", taco);
}

/* leftshift: shifts all 1-bits LEFT */
void leftshift(int x, int shift)
{
    printf("Left Shift %d by %d: %d\n", x, shift, x << shift);
}

/* rightshift: shifts all 1-bits RIGHT */
void rightshift(int x, int shift)
{
    printf("Right Shift %d by %d: %d\n", x, shift, x >> shift);
}

/* bitand: takes all 1-bits that are equal */
void bitand(int x, int y)
{
    printf("Bit AND %d & %d: %d\n", x, y, x & y);
}

/* bitor: takes all 1-bits */
void bitor(int x, int y)
{
    printf("Bit OR %d | %d: %d\n", x, y, x | y);
}

/* bitxor: takes all 1-bits that are not shared */
void bitxor(int x, int y)
{
    printf("Bit XOR %d ^ %d: %d\n", x, y, x ^ y);
}

/* bitnot: inverts bits */
void bitnot(unsigned int x)
{
    printf("Bit comp %u ~: %u\n", x, ~x);
}
