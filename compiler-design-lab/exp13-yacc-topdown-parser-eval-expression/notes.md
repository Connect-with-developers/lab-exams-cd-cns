# Exp 13: Yacc Top-Down Parser — Evaluate Expression

## 1. Aim (write this in exam)
Write a yacc parser for E→E+T|E-T|T, T→T*F|T/F|F, F→(E)|NUM that evaluates expression (e.g. `3+5*2` = 13).

## 2. Description in simple words
- Grammar is top-down style: start S, expand E→T→F. Yacc handles it as LALR but exam calls it top-down parser.
- Precedence: E does +,- (lowest), T does *,/ (middle), F does bracket/number (highest). So `3+5*2` = 3+(5*2) = 13.
- Lex passes value via `yylval = atoi(yytext)`. Yacc computes via `$$ = $1 + $3` etc.
- `%left '+' '-'` then `%left '*' '/'` tells yacc * binds tighter.

Rule to remember: **E eats +, T eats *, F eats number, $$ computes.**

## 3. Learn in small steps

**Step 1 — expr.l (30 sec):**
```c
%{ #include "y.tab.h" #include<stdlib.h> %}
%%
[0-9]+      { yylval = atoi(yytext); return NUM; }
[+\-*/()\n] { return yytext[0]; }
[ \t]+     ;
%%
int yywrap() { return 1; }
```

**Step 2 — expr.y header (20 sec):**
```c
%{
#include<stdio.h>
%}
%token NUM
%left '+' '-'
%left '*' '/'
```

**Step 3 — grammar + actions (40 sec):**
```c
S : E '\n' { printf("Result = %d\n", $1); } ;
E : E '+' T { $$ = $1 + $3; } | E '-' T { $$ = $1 - $3; } | T { $$ = $1; } ;
T : T '*' F { $$ = $1 * $3; } | T '/' F { $$ = $1 / $3; } | F { $$ = $1; } ;
F : '(' E ')' { $$ = $2; } | NUM { $$ = $1; } ;
```

**Step 4 — tail (10 sec):**
```c
int main() { printf("Enter expr:\n"); yyparse(); return 0; }
int yyerror(char *s) { printf("Error\n"); return 0; }
```

How to practice: write Step 3 from memory (E/T/F one line each). 2 times = done.

## 4. Full Program
See `expr.l`, `expr.y`. Compile & run:
```
lex expr.l
yacc -d expr.y
gcc lex.yy.c y.tab.c -o parser
./parser
```

## 5. Expected Output
See `output.txt`. Key lines:
```
3+5*2   -> Result = 13
(2+3)*4 -> Result = 20
```
(Sample output — flex/bison not installed, this is the expected result.)

## 6. How to write in exam (3 min version)
Write .l (10 lines) + .y (18 lines) as is. If short on time, skip `%left` lines — grammar order already gives precedence.

## 7. Viva — 1 line answers
1. **Why 3+5*2 = 13 not 16?** `*` has higher precedence, 5*2 first.
2. **What is yylval?** Carries number value lex→yacc.
3. **Top-down or bottom-up?** Yacc is bottom-up (LALR), grammar written top-down from E.
4. **What does %left do?** Sets associativity + precedence level.
5. **What is yyerror?** Called on invalid expression.
