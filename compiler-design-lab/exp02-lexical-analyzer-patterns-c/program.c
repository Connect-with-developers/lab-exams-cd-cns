#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *s) {
    char *kw[] = {"int", "float", "char", "if", "else", "return"};
    for (int i = 0; i < 6; i++)
        if (strcmp(s, kw[i]) == 0) return 1;
    return 0;
}
int isIdentifier(char *s) {
    if (!isalpha(s[0]) && s[0] != '_') return 0;
    for (int i = 1; s[i]; i++)
        if (!isalnum(s[i]) && s[i] != '_') return 0;
    return !isKeyword(s);
}
int isConstant(char *s) {
    for (int i = 0; s[i]; i++)
        if (!isdigit(s[i])) return 0;
    return 1;
}
int isOperator(char *s) {
    return strlen(s) == 1 && strchr("+-*/=%<>", s[0]) != NULL;
}
int isComment(char *s) {
    return s[0] == '/' && (s[1] == '/' || s[1] == '*');
}
void check(char *s) {
    if (isComment(s)) printf("%-10s -> comment\n", s);
    else if (isKeyword(s)) printf("%-10s -> keyword\n", s);
    else if (isIdentifier(s)) printf("%-10s -> identifier\n", s);
    else if (isConstant(s)) printf("%-10s -> constant\n", s);
    else if (isOperator(s)) printf("%-10s -> operator\n", s);
    else printf("%-10s -> unknown\n", s);
}
int main() {
    printf("Line: int sum = a + 12; // total\n");
    check("int"); check("sum"); check("="); check("a");
    check("+"); check("12"); check("// total");
    return 0;
}
