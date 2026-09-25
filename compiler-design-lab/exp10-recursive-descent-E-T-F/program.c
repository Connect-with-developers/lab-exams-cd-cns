#include <stdio.h>
#include <string.h>

char *ip; int pos; // input string + index
// E -> T+E | T   (right recursion, no left recursion)
void E(); void T(); void F();
int err;
void E() { T(); if (ip[pos] == '+') { pos++; E(); } }
void T() { F(); if (ip[pos] == '*') { pos++; T(); } }
void F() {
    if (ip[pos] == '(') { pos++; E(); if (ip[pos] == ')') pos++; else err = 1; }
    else if ((ip[pos] >= 'a' && ip[pos] <= 'z')) pos++; // id = one letter
    else err = 1;
}
void test(char *s) {
    ip = s; pos = 0; err = 0;
    E();
    if (!err && pos == (int)strlen(s)) printf("%-10s -> Accepted\n", s);
    else printf("%-10s -> Rejected\n", s);
}
int main() {
    printf("E->T+E|T, T->F*T|F, F->(E)|id\n");
    test("a+b*c");
    test("a*(b+c)");
    test("a+*b");
    return 0;
}
