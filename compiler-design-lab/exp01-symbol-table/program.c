#include <stdio.h>
#include <string.h>

struct Symbol { char name[20], type[20], scope[20]; };
struct Symbol table[10];
int n = 0;

void insert(char *name, char *type, char *scope) {
    strcpy(table[n].name, name);
    strcpy(table[n].type, type);
    strcpy(table[n].scope, scope);
    n++;
}
int search(char *name) {
    for (int i = 0; i < n; i++)
        if (strcmp(table[i].name, name) == 0) return i;
    return -1;
}
void display() {
    printf("Name\tType\tScope\n");
    for (int i = 0; i < n; i++)
        printf("%s\t%s\t%s\n", table[i].name, table[i].type, table[i].scope);
}
int main() {
    insert("x", "int", "local");
    insert("y", "float", "global");
    insert("z", "char", "local");
    display();
    int i = search("y");
    if (i != -1) printf("Found y: %s %s\n", table[i].type, table[i].scope);
    else printf("y not found\n");
    if (search("w") == -1) printf("w not found\n");
    return 0;
}
