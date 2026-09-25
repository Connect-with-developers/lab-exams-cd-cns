# Exp 08: Lex — Count Lines, Words, Characters

## 1. Aim (write this in exam)
Write a lex program to count lines, words and characters (like `wc` command).

## 2. Description in simple words
- 3 counters: `lc` (lines), `wc` (words), `cc` (chars).
- 3 rules: `\n` = new line (+1 line, +1 char), `[^ \t\n]+` = word (+1 word, +yyleng chars), `[ \t]` = space (+1 char).
- `yyleng` = length of matched word. `[^ \t\n]+` means "one or more non-space chars" = one word.
- End input with Ctrl+D, then print all 3 counts.

Rule to remember: **newline→line, non-space→word, everything→char.**

## 3. Learn in small steps

**Step 1 — Counters (10 sec):**
```c
%{
#include<stdio.h>
int lc = 0, wc = 0, cc = 0;
%}
```

**Step 2 — 3 rules (30 sec):**
```c
%%
\n          { lc++; cc++; }
[^ \t\n]+  { wc++; cc += yyleng; }
[ \t]       { cc++; }
```

**Step 3 — Tail (20 sec):**
```c
%%
int yywrap() { return 1; }
int main() {
  printf("Enter text (Ctrl+D to end):\n");
  yylex();
  printf("Lines=%d Words=%d Chars=%d\n", lc, wc, cc);
  return 0;
}
```

How to practice: write Step 2 from memory (order: newline, word, space). 2 times = done.

## 4. Full Program
See `count.l`. Compile & run:
```
lex count.l
gcc lex.yy.c -o count
./count
```

## 5. Expected Output
See `output.txt`. Key lines:
```
Lines=2 Words=4 Chars=21
```
(Sample output — flex not installed, this is the expected result.)

## 6. How to write in exam (3 min version)
Program is 17 lines — write as is. Minimum: 3 rules + printf line.

## 7. Viva — 1 line answers
1. **What is yyleng?** Length of current matched text.
2. **Word pattern?** `[^ \t\n]+` — run of non-space chars.
3. **Why cc += yyleng?** Word has many chars, add all at once.
4. **What is yywrap?** End-of-input handler, return 1 = stop.
5. **How to end input?** Ctrl+D (Linux) / Ctrl+Z (Windows).
