#include <stdio.h>
#include <stdlib.h>

char* p;

int parseNumber();

int parseNumber() {
    char c = *p;
    int x = 0;

    while(c >= '0' && c <= '9') {
        x = x*10 + (c-'0');
        c = *++p;
    }

    return x;
}

void nextToken() {
    while((*p == ' ' || *p == '\n' || *p == '\t') && *p != '\0') {
        p++;
    }
}

int parseParens();

int parseMult() {
    int x = parseParens();
    nextToken();
    while(*p == '*') {
        p++;
        nextToken();
        x *= parseParens();
    }
    return x;
}

int parseAdd() {
    nextToken();
    int x = parseMult();
    nextToken();
    while(*p == '+') {
        p++;
        nextToken();
        x += parseMult();
    }
    return x;
}


int parseParens() {
    if(*p == '(') {
        p++;
        int x = parseAdd();
        p++;
        return x;
    }
    return parseNumber();
}


int main(void) {
    char* math = "1+1+2+(1+2-1+(1))";
    p = math;

    int x = parseAdd();

    printf("%d\n", x);

    return 0;
}
