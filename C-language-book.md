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

1.7 Functions

A function is equivalent to a subroutine in Fortran.

>> see power.c

A function def has this form:

<return type> <function-name>(<parameter delcarations>)
{
    <declarations>
    <statements>
}

Function definitions can appear in any order, and in one source file or several.

We are assuming that both functions are in the same file.

int power(int base, int n);

declares the paramter types and names, and the type of the result that the function returns. The names used by the power for its parameters are local to power.

PARAMETER: a varaible named in the parenthesized list in a function def

ARGUMENTT: value used in theh call of the function

A return value of 0 implies normal termination.
Non-zero values signal unsual or erroneous termination conditions.

int power(int m, int n);

This is called a FUNCTION PROTOTYPE, an error occurs if the definition of a function or any uses of it do not agree with its prototype.

parameter names need not agree. indeed, parameter names are optimal in a functional protype, so for the prototype we could have written:

int power(int, int);

ANSI C and earlier versions is how functions are declared and defined. In original definition C, the pwoer function would have been wrriten like so:

power(base, n)
int base, n;
{
    <statements>
}

int power();

No parameter list was permitted, so the compiler could not readily check that the power was being caleld correctly. Ineed, since by defaul;t the power would have been assumed ot return int, the entire delation might well have been ommitted.


1.8 Arguments -- call by value

All function arguments are passed "by value". This means that the called function is given the values of its arguments in temp variables rather than originals.

In C, the called function cannot directly alter a variable in the calling function. it can only alter its private, temp copy.

CBV (call by value), is an asset, howerver not a liability.

It is possible to modify a variable in a calling routine. Tthe caller must provide the ADDRESS of the variaables to be set (technically a POINTER to the variable), and the function must declare the parameter to be a pointer and access the var directly.

Arrays are different. When the name of an array is used as an argument, the value passed to the function is the location or the address of the begining of the array- there is no copying of array elements.

1.9: Character Arrays

>> see char-array.c

NOTE: getline is apart of stdio.h now, this book is older than the federal reserve.

'\0' the NULL CHARACTER whose value is zero,
    to mark the end of the string of characters.

When a string like:

"hello\n"

appears in C, the stored array of characters contains

h   e  l  l  o \n  \0

1.10 External Variables and Scope


Variables in C are referred to as AUTOMATIC variables (exist in local scope).

Alternative to AUTOMATIC variables are "external" to all functions. Because global variables are globally accessible they can be used instead of argument lists to communcate adata between functions.

An external variable must be defined, exactly once, outside any function. this VAR must also be delcared in each function. EXTERN statement

>> see updated char-array.c

in certain scenarios, the extern dec can be omitted. If the def of an external varaible occurs in the source file before its use in the particular function.

The extern dec in main, getline and copy are redundant.

The usual practice is to collect
extern declarations of variables and functions in a separate file, historically called a header, that is included by #include at the front of each source file.


DEFINTION: regers to the place where the variable is created or assigned storage
DELCARATION: refers to the place where the nature of the variaable is sttaated but no storage is allocated.


CHAPTER 2.0: Types, Operators, and Expressions

signed, unsigned

char, int, float, double

can be assigned with
short int sh;
long int counter;

int can be omitted in such dec

short is often 16 bits and long is 32
and int either 16 or 32 bit.

Each compiler is free to choose sizes for its own harderware.

chars - 8 bbits
unsigned char values between 0 and 255

signed chars between -128 and 127

The standard headers:

<limits.h> and <float.h> contain symbolic constants for all of these types (long double, etc)

1234 = int
123456789L = long constant (note L)

unsigned constants are written with U and suffix of ul or UL inicates unsigned long

the suffix f or F indicates a float constant
l or L indicate long double

A leading 0 (zero) on an integer constant means octal.

A leading 0x means hex.

DEC 31 == 037 in octal
and 0x1f in hex.

Character constant is an INTEGER

Written: 'x'. the value of a character constant is the numeric value of the character in the machines' character set.

ASSIC character set constnat '0' has the value 48, which is unrealted to the numeric value of 0.

Certain chars can be represented in character and string constants  by escape seq \n (even though it uses two characters).

Arbitrary byte-sized bit pattern can be specified by:

'\ooo'

where ooo is one to three octal digits or by

'xhh'

where hh is one or more hexadeciaml digits.

#define VTAB '\013' /* ASCII vertical tab \*/
#define BELL '\077' /* ASCII bell character \*/

Or in hex

#define VTAB '\xb'
#define BELL '\x7'

Constant expression
#define MAXLINE 1000

String constant:
"I am a string"

"hello," "world" == "hello, world"

strlen(s) returns the length of its character string arguments s, excluding the terminal '\0' see: <string.h>

Enumeration constant:

enum boolean {NO, YES};

Alternative to define, but the values are determined for you (1,2,..,n)

2.7 Type Conversions

The only automatic conversion of types are those that convert a "narrwer" operand into a
"wider" one without losing information. Such as converting an int to a float (f + i).
Expressions that would lose information like assigning a longer int type ot a shorter, or a floating point to an int may draw a warning, but are not illegal.

a Char is just a small int, so chars may be freely used in artimetic. A common use of this in atoi which converts a string of digits into its numeric equivalent.

2.9 Bitwise Operators

&   bitwise AND
|   bitwise inclusive OR
^   bitwise exclusive OR
<<  left shift
>>  right shift
~   one's complement unary

&: used to mask off some set of bits:

n = b & 0177;

sets to zero all but the lower-order 7 bits of n.

The bitwise OR operator | is used to turn bits on:

x = x | SET_ON;

sets to one in x the bits that are set to one in SET_ON

The ^ operator sets a one in each bit position where its operands have different bits, and zero where they are the same.

The ~ operator yields the one's complement of an integer.
It converts each 1-bit into 0-bit and vice versa.

x = x & ~077

sets the last six bits of x to zero. Note that x & ~077 is independent of word length and is thus perferable to x & 0177700, which assumes that x is a 16-bit quantity.

<< SKIPPED A LOT OF KNOWN THINGS >>

4.6 Static Variables

static allows scoping of of external variables or functions
private static variables provide a permanent storage within a single function (they dont fall away like automatic veriables)

4.7 Register Variables

A way to tell the compiler thatt a virable will be used often.

4.8 Block Stucture

C is not a block-stuctured language because functions cannot be defined within other functions (aka python).

Variables however, are block structured.

4.9 Initialization

external and static variables are guranteed to be init to zero.
automattic and register variables have undefined initial values (ie. garbage)
scalar variables are defined on assignment

external and static variables is done once before program begins execution. automatic and register variables are done each time the function is entered.

When an array ommits its size the compiler will compute the length by counting the inittializers, of which are there are 12 in this case.

int days[] = { 1, 2, 3, ... , 12};

If fewer intializers for an array than the number specified than the missing elements will be zero for external, static and automatic variables.

Char arrays are special. A string may be used instead of commans.

char pattern[] = "ould";

shorthand for:

char pattern[] = { 'o', 'u', 'l', 'd', '\0'};

4.10 Recursion

C functions may be used recursively.

Lower order digits are available before high-order digits. I believe this means (a-z < A-Z).

two solutions: one is to store the digits in an array as they are generated, then print tthem in the reserve order, as we did with itoa.

Alternative is a recursive solution in which printd first calls itself to cope with any laeding digits, then prints the trailing digit. This version can fail on the largest negative number.

>> see prtind.c
>> see quicksort.c
