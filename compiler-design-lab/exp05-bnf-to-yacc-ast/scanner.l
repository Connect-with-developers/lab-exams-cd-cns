%{
#include "y.tab.h"
#include<string.h>
%}
%%
[a-zA-Z]  { yylval.s = strdup(yytext); return ID; }
[+*()\n]  { return yytext[0]; }
[ \t]+    ;
.         { return yytext[0]; }
%%
int yywrap() { return 1; }
