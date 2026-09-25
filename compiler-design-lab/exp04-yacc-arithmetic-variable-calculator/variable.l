%{
#include "y.tab.h"
%}
%%
[a-zA-Z_][a-zA-Z0-9_]*  { return VAR; }
[ \t\n]+               ;
.                       { return yytext[0]; }
%%
int yywrap() { return 1; }
