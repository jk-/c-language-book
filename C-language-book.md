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

1.5.1 File copying

Given getchar and putchar, you can write a surprising amountn of useful code without knowing anything more input or output.

read and write a character
>> see file-copy.c

The problem is distinguished the end of the input from valid data. The solution is that getchar returns a distictive value when there is no more input, a value that connot be confused with any real character. This value is called EOF or "end of file". We must declare c to be a type big enough to hold any value thaht getchar returns. We can't use char since c must be big enough to hold EOF in addition to any possible char. Therfore we must use int.

EOF is defined in <stdio.h>, but the specific numeric value doesn't matter as long as it is not the same as any char value.

stdio.h:
https://fresh2refresh.com/c-programming/c-function/stdio-h-library-functions/

in C, any assignmentt, such as

c = getchar()

is an experssion and has a value, which is the value of the left hand side after the assignment. This means that an assignment can appaer as part of a larger expression. If the assignment of a cahracter to c is put inside the test part of a while loop, the copy program an be written this way.

>> see file-copy.c

The parantheses around the assignment within the condition are neccessary. The precedence of != is higher than tthhat of =, which means that in the absence of parantheses the relational test != would be done before the assignment = . So the statement:

c = getchar() != EOF

is ====

c = (getchar() != EOF)

This has the undesired effect of setting c to 0 or 1.

1.5.2 Character Counting

>> count-char.c

NOTE: the program wouldn't print the size of characters because we were stuck in for loop - see count-char.c for break to print.

We can cope with bigger numbers by using a double and we will use a for loop instead of a while, to illustrate another way to write the loop.

The body of the for loop is empty, because all of the work is done in the test increment parts. Bbut the grammatical rules of C require that a for statement have a body. The isolated semicolon called a NULL STATEMENT, is there to satisfy that requirement.

1.5.3 Line Counting

The next program counts input lines.

>> see count-lines.c

== is the C notation for "is equal to" (like Pascal's singl = or Forta's .EQ.)

A character written between single quotes represents an integer value equal to the numerical value of the character in the machine's character set. This is called
a character constant, although it is just another way to write a small integer. So, for exmaple 'A' is a chracter constant; in the ASCII character set its value is 65, the internal representation of the character is A.

1.5.4 Word Counting

>> see count-words.c

1.6 Arrays

Count number of occurences of each digit or white space character (blank, tab, newline).

There are TWELVE categories of input, so it is convenient to use an array to hold the number of occurrences of each digit, rather than a ten indivcidual varaibles.

>> see array.c

int ndigit[10];

declares ndigit to be an array of 10 integers. Array subscripts always start at zero in C, so the elements are ndigit[0], [1], .. [9].

A subscript can be any integer expression, which includes integer variables like i, and integer constants.

This particular program relies on properties of the character representation of digits.

c >= '0' && c <= '9'

determines whether the character in C is a digit. If it is, the NUMERIC value of that digit is:

c - '0'

Characters are just small integers.
