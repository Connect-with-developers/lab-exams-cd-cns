# Exp 04: Yacc — Arithmetic Check + Variable Check + Calculator (3-in-1)

## 1. Aim (write this in exam)
(a) Check valid arithmetic expression (+ - * /), (b) check valid variable, (c) calculator that evaluates expression. Write any one as asked.

## 2. Description in simple words
- Yacc = write grammar, yacc generates parser. Lex sends tokens, yacc checks grammar.
- `.l` returns token: `return NUM;` or `return yytext[0];` for symbols.
- `.y` has `%token`, grammar rules `E : E '+' T`, actions `{ $$ = ...; }`.
- (a) arithmetic: no actions except print Valid. (b) variable: one rule `S : VAR`. (c) calc: same grammar + `{ $$=$1+$3; }` to compute.
- Grammar E(+,-) → T(*,/) → F(bracket/NUM) gives correct precedence.

Rule to remember: **.l returns tokens, .y checks grammar, $$ computes.**

## 3. Learn in small steps

**Step 1 — .l pattern (same for all 3, 30 sec):**
```c
%{ #include "y.tab.h" %}
%%
// arithmetic: [0-9]+ return NUM;  symbols return yytext[0];
// variable:   [a-zA-Z_][a-zA-Z0-9_]* return VAR;
// calc:       [0-9]+ { yylval=atoi(yytext); return NUM; }
[ \t\n]+ ;
%%
int yywrap() { return 1; }
```

**Step 2 — (a) arithmetic.y grammar (30 sec):**
```c
%token NUM
S : E { printf("Valid expression\n"); } ;
E : E '+' T | E '-' T | T ;
T : T '*' F | T '/' F | F ;
F : '(' E ')' | NUM ;
```

**Step 3 — (b) variable.y grammar (20 sec):**
```c
%token VAR
S : VAR { printf("Valid variable\n"); } ;
```

**Step 4 — (c) calc.y = same grammar + actions (30 sec):**
```c
S : E '\n' { printf("Result = %d\n", $1); } ;
E : E '+' T { $$ = $1 + $3; }   // minus, T same way
T : T '*' F { $$ = $1 * $3; }   // divide, F same way
F : '(' E ')' { $$ = $2; } | NUM { $$ = $1; } ;
```

**Step 5 — tail (same all 3):**
```c
int main() { printf("Enter expr:\n"); yyparse(); return 0; }
int yyerror(char *s) { printf("Invalid\n"); return 0; }
```

How to practice: memorize Step 1+5 once, then Step 2/3/4 as 3 options. Each file <40 lines.

## 4. Full Programs
See `arithmetic.l`, `arithmetic.y`, `variable.l`, `variable.y`, `calc.l`, `calc.y`. Compile & run:
```
# part (a)
lex arithmetic.l
yacc -d arithmetic.y
gcc lex.yy.c y.tab.c -o parser
./parser
# part (b): replace with variable.l / variable.y
# part (c): replace with calc.l / calc.y
```

## 5. Expected Output
See `output.txt`. Key lines:
```
a+b*c     -> Valid expression
count1    -> Valid variable
3+5*2     -> Result = 13
```
(Sample output — flex/bison not installed, this is the expected result.)

## 6. How to write in exam (3 min version)
Exam asks only ONE part. Write that .l (8 lines) + .y (12-18 lines). Calculator = arithmetic + `$$` actions.

## 7. Viva — 1 line answers
1. **Lex vs yacc?** Lex = tokens, yacc = grammar check.
2. **What is yylval?** Passes number value from lex to yacc.
3. **What is $$, $1, $3?** $$ = result, $1/$3 = left/right values.
4. **Why E→T→F?** Gives * / higher precedence than + -.
5. **What is yyerror?** Called on syntax error.
