%{
#include<stdio.h>
%}
%token NUM
%%
S : E '\n' { printf("Result = %d\n", $1); } ;
E : E '+' T { $$ = $1 + $3; }
  | E '-' T { $$ = $1 - $3; }
  | T { $$ = $1; } ;
T : T '*' F { $$ = $1 * $3; }
  | T '/' F { $$ = $1 / $3; }
  | F { $$ = $1; } ;
F : '(' E ')' { $$ = $2; }
  | NUM { $$ = $1; } ;
%%
int main() { printf("Enter expr:\n"); yyparse(); return 0; }
int yyerror(char *s) { printf("Error\n"); return 0; }
