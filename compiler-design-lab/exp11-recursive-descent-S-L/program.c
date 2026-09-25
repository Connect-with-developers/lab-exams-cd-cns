#include <stdio.h>
#include <string.h>

char *ip; int pos, err;
// S -> (L) | a ,  L -> S,L | S
void S(); void L();
void S() {
    if (ip[pos] == '(') { pos++; L(); if (ip[pos] == ')') pos++; else err = 1; }
    else if (ip[pos] == 'a') pos++;
    else err = 1;
}
void L() { S(); if (!err && ip[pos] == ',') { pos++; L(); } }
void test(char *s) {
    ip = s; pos = 0; err = 0;
    S();
    if (!err && pos == (int)strlen(s)) printf("%-12s -> Accepted\n", s);
    else printf("%-12s -> Rejected\n", s);
}
int main() {
    printf("S->(L)|a, L->S,L|S\n");
    test("(a,(a,a))");
    test("(a,");
    test("a");
    return 0;
}
