# Exp 03: Lexical Analyzer using Lex Tool

## 1. Aim (write this in exam)
Write a lex program to recognize keywords, identifiers, numbers, operators and skip whitespace.

## 2. Description in simple words
- Lex tool = write patterns, lex generates scanner automatically.
- 3 sections: `%{ declarations %}`, `%% rules %%`, `main + yywrap`.
- Each rule = `pattern { action }`. `yytext` holds matched word.
- Our rules: keyword list (`int|float|...`), identifier (`letter then letters/digits`), number (`digits`), operator (`+-*/=%<>;`), whitespace (skip, no action).

Rule to remember: **keyword→fixed words, letter→identifier, digit→number, +-*→operator.**

## 3. Learn in small steps

**Step 1 — Header + keyword (20 sec):**
```c
%{
#include<stdio.h>
%}
%%
"int"|"float"|"char"|"if"|"else"|"return"  { printf("%s -> keyword\n", yytext); }
```

**Step 2 — Identifier + number (20 sec):**
```c
[a-zA-Z_][a-zA-Z0-9_]*  { printf("%s -> identifier\n", yytext); }
[0-9]+                  { printf("%s -> number\n", yytext); }
```

**Step 3 — Operator + whitespace (20 sec):**
```c
[+\-*/=%<>;]  { printf("%s -> operator\n", yytext); }
[ \t\n]+     { /* skip */ }
.             { printf("%s -> unknown\n", yytext); }
```

**Step 4 — Tail (20 sec):**
```c
%%
int yywrap() { return 1; }
int main() { printf("Enter input:\n"); yylex(); return 0; }
```

How to practice: write Steps 1-4 in order. 2 times = done.

## 4. Full Program
See `scanner.l`. Compile & run:
```
lex scanner.l
gcc lex.yy.c -o scanner
./scanner
```

## 5. Expected Output
See `output.txt`. Key lines for input `int a = 5;`:
```
int -> keyword
a   -> identifier
=   -> operator
5   -> number
;   -> operator
```
(Sample output — flex not installed, this is the expected result.)

## 6. How to write in exam (3 min version)
Keep only 5 rules: keyword, identifier, number, operator, whitespace + `main/yywrap`. Same marks.

## 7. Viva — 1 line answers
1. **What is lex?** Tool that generates scanner from patterns.
2. **What is yytext?** Matched string for current token.
3. **What is yylex()?** Scanner function, called from main.
4. **What is yywrap()?** Called at end of input, return 1 = done.
5. **Identifier pattern?** `[a-zA-Z_][a-zA-Z0-9_]*`.
