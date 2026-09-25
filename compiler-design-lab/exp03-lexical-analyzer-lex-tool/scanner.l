%{
#include<stdio.h>
%}
%%
"int"|"float"|"char"|"if"|"else"|"return"|"while"|"for"  { printf("%s -> keyword\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*  { printf("%s -> identifier\n", yytext); }
[0-9]+                  { printf("%s -> number\n", yytext); }
[+\-*/=%<>;]            { printf("%s -> operator\n", yytext); }
[ \t\n]+               { /* skip whitespace */ }
.                       { printf("%s -> unknown\n", yytext); }
%%
int yywrap() { return 1; }
int main() {
  printf("Enter input:\n");
  yylex();
  return 0;
}
