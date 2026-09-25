%{
#include<stdio.h>
int lc = 0, wc = 0, cc = 0;
%}
%%
\n          { lc++; cc++; }
[^ \t\n]+  { wc++; cc += yyleng; }
[ \t]       { cc++; }
%%
int yywrap() { return 1; }
int main() {
  printf("Enter text (Ctrl+D to end):\n");
  yylex();
  printf("Lines=%d Words=%d Chars=%d\n", lc, wc, cc);
  return 0;
}
