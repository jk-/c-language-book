Chapter 1:

1.1 Getting Started
see hello.c


Hello World:

#include <stdio.h>

main()
{
    printf("hello, world\n");
}

>> cc hello.c

makes a.out
./a.out
>> hello, world

Every program must have a main

#include <stdio.h>

tells thhe compiler to include information about the standard input/output library.

1.2 Variables and Arithmetic Expressions
see Fahr.c

C = (5/9)(F-32)

int fahr, celsius;

16-bit ints, which lie between -32769 and +32767 are common, as are 32-bit ints.

A float number is typically a 32-bit quantity with at
least six significant digits and magnitude generally between
10^-38 and 10^38

C provides several data types besides int and float:

char    character - a single byte
short   short integer
long    long integer
double  double-precision floating point

Size of these types are machine dependant. There are
also arrays, structures and unions of these basic types, pointers to them and functions that return them.

There are problems in our FAHR.c. Because we used ints
our arithmetic is not accurate. Let's change that.

>>
