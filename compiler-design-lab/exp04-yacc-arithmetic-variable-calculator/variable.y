%{
#include<stdio.h>
%}
%token VAR
%%
S : VAR { printf("Valid variable\n"); } ;
%%
int main() { printf("Enter variable:\n"); yyparse(); return 0; }
int yyerror(char *s) { printf("Invalid variable\n"); return 0; }
