# 22CS704PC: Compiler Design Lab

**B.Tech IV Year I Sem | L T P C: 0 0 2 1**

## Prerequisites
- Object Oriented Programming through Java

## Co-requisites
- Web Technologies

## Course Objectives
- Understand various phases in design of a compiler
- Understand design of top-down and bottom-up parsers
- Understand syntax directed translation schemes
- Introduce lex and yacc tools

## Course Outcomes
- Design, develop, and implement a compiler for any language
- Use lex and yacc tools for developing scanner and parser
- Design and implement LL and LR parsers

## List of Experiments — Fast Index

| No | Experiment | Folder |
|----|------------|--------|
| 1 | Implementation of symbol table | `exp01-symbol-table/` |
| 2 | Lexical analyzer to recognize patterns in C (identifiers, constants, comments, operators etc.) | `exp02-lexical-analyzer-patterns-c/` |
| 3 | Implementation of lexical analyzer using lex tool | `exp03-lexical-analyzer-lex-tool/` |
| 4 | YACC specification: a) valid arithmetic expression (+,-,*,/) b) valid variable (letter followed by letters/digits) c) calculator using lex and yacc | `exp04-yacc-arithmetic-variable-calculator/` |
| 5 | Convert BNF rules into yacc form and write code to generate abstract syntax tree | `exp05-bnf-to-yacc-ast/` |
| 6 | Implement type checking | `exp06-type-checking/` |
| 7 | Implement any one storage allocation strategy (heap, stack, static) | `exp07-storage-allocation/` |
| 8 | Lex program to count words and lines in a given file/program | `exp08-lex-word-line-count/` |
| 9 | C program to implement lexical analyzer using C | `exp09-lexical-analyzer-c-program/` |
| 10 | Recursive descent parser for E->E+T | E->T | T->T*F | T->F | F->(E)/id | `exp10-recursive-descent-E-T-F/` |
| 11 | Recursive descent parser for S->(L) | S->a | L->L,S | L->S | `exp11-recursive-descent-S-L/` |
| 12 | C program to calculate FIRST function for E->E+T | E->T | T->T*F | T->F | F->(E)/id | `exp12-first-function/` |
| 13 | YACC program to implement top-down parser + YACC program to evaluate algebraic expression | `exp13-yacc-topdown-parser-eval-expression/` |

## How to use this folder for exams
Each `expXX-.../` folder will contain:
- `program.c` / `scanner.l` / `parser.y` — final exam-ready code
- `output.txt` — sample output / compile-run commands
- `notes.md` — aim, algorithm, viva questions (2-min revision)

**Imp lex/yacc commands for exam:**
```
lex scanner.l
yacc -d parser.y
gcc lex.yy.c y.tab.c -o parser
./parser
```

## Text Book
1. Compilers: Principles, Techniques and Tools, 2nd Ed, Aho, Lam, Sethi, Ullman

## Reference Books
1. Lex & Yacc – Levine, Mason, Brown, O’Reilly
2. Compiler Construction, Louden, Thomson
