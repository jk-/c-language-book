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
>> see fahr.c git log -1

We were unable to use int's for celsius becuase the values would be truncated to zero.

in the while loop and assignmentt of fahr to lower tthe int is converted to float before the opartion is done.

the print F %3.0f says that a floating-poiont number is to be printed at least three characters "wide" with no decimal point and no fraction digits.

%6.1f describes another number (celsius) that is to be printed at least six characters wide with 1 digit after decimal point.

%d  print as decimal integer
%6d print as decimal integer, at least 6 characters wide
%f  print as float
%6f 6-wide float
%.2f    print as float, 2 characters after decimal
%6.2f   6 wide, 2 wide decimal
%o      for octal
%x      for hex
%c      for charactter
%s      string
%%      for %


1.3 The for statement

There are other ways to wirte the fahr program


1.4 Symbolic Constants

It's bad practice to bury constants inside the program. Here we will define constantts to our fahr program. To do so we use:

#define <name> <replacement text>

Any occurrence of name (not in quoets and nott part of another name) will be replaced by the corresponding replacement ttetxt.

1.5 Character input and output

The model of input and output supported by the standard libbrary is very simple. Text input or output, regardless of where it originates or where it goes to, is dealth with a streams of characters. A <text strteam> is a sequence of characters divided into lines; each line consists of zzero or more characters followed by a new line chharacter. it is the responsbility of the library to make each input or output stream conform to this model.

getchhar and putchar are the simplest. Each time it is called, getchar reads the <NEXT INPUT CHARACTER> from tthe text stream and returns thhat as its value.

c = getchar()

Will contain the next character of input.

putchar(c)

Prints the c ontents of the integer variable c as a chahracter, usually on the screen. Calls to putchar and printf may be interleaved; 
