#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *w) {
    char *kw[] = {"int", "float", "char", "if", "else", "return"};
    for (int i = 0; i < 6; i++)
        if (strcmp(w, kw[i]) == 0) return 1;
    return 0;
}
int main() {
    char s[] = "int a = b + 12; float c = a * 2;";
    int kw = 0, id = 0, num = 0, op = 0, i = 0;
    printf("Input: %s\n", s);
    while (s[i]) {
        if (isspace(s[i]) || s[i] == ';') { i++; continue; }
        if (isalpha(s[i]) || s[i] == '_') {
            char w[20]; int j = 0;
            while (isalnum(s[i]) || s[i] == '_') w[j++] = s[i++];
            w[j] = '\0';
            if (isKeyword(w)) { kw++; printf("%-6s keyword\n", w); }
            else { id++; printf("%-6s identifier\n", w); }
        } else if (isdigit(s[i])) {
            char w[20]; int j = 0;
            while (isdigit(s[i])) w[j++] = s[i++];
            w[j] = '\0'; num++; printf("%-6s number\n", w);
        } else if (strchr("+-*/=", s[i])) {
            printf("%-6c operator\n", s[i]); op++; i++;
        } else i++;
    }
    printf("keywords=%d identifiers=%d numbers=%d operators=%d\n", kw, id, num, op);
    return 0;
}
