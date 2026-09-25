#include <stdio.h>
#include <string.h>

char *getType(char *name) {
    if (strcmp(name, "a") == 0) return "int";
    if (strcmp(name, "b") == 0) return "float";
    return NULL; // undeclared
}
void check(char *op1, char *op, char *op2) {
    char *t1 = getType(op1), *t2 = getType(op2);
    if (t1 == NULL) { printf("%s %s %s -> ERROR: %s undeclared\n", op1, op, op2, op1); return; }
    if (t2 == NULL) { printf("%s %s %s -> ERROR: %s undeclared\n", op1, op, op2, op2); return; }
    char *res = (strcmp(t1, "float") == 0 || strcmp(t2, "float") == 0) ? "float" : "int";
    printf("%s(%s) %s %s(%s) -> %s\n", op1, t1, op, op2, t2, res);
}
int main() {
    printf("a=int, b=float\n");
    check("a", "+", "a");
    check("a", "+", "b");
    check("a", "+", "c");
    return 0;
}
