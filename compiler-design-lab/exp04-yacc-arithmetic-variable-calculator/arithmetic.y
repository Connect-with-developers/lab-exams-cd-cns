%{
#include<stdio.h>
%}
%token NUM
%%
S : E { printf("Valid expression\n"); } ;
E : E '+' T | E '-' T | T ;
T : T '*' F | T '/' F | F ;
F : '(' E ')' | NUM ;
%%
int main() { printf("Enter expr:\n"); yyparse(); return 0; }
int yyerror(char *s) { printf("Invalid expression\n"); return 0; }
