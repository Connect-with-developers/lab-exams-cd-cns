# Exp 02: Lexical Analyzer — Patterns in C

## 1. Aim (write this in exam)
Write a C program to recognize identifiers, constants, comments and operators from a hardcoded C line.

## 2. Description in simple words
- Lexical analyzer = first phase, splits code into tokens.
- `keyword`: int/float/if... `identifier`: starts with letter/_, then letters/digits. `constant`: all digits. `operator`: one of `+-*/=%<>`. `comment`: starts `//` or `/*`.
- Our program tests one sample line: `int sum = a + 12; // total` — each word is checked by one small function.

Rule to remember: **letter→identifier, digit→constant, //→comment, +-*→operator.**

## 3. Learn in small steps

**Step 1 — Keyword list (30 sec):**
```c
char *kw[] = {"int","float","char","if","else","return"};
// loop + strcmp
```

**Step 2 — Identifier vs constant (30 sec):**
```c
isIdentifier: first char isalpha or '_', rest alnum, not keyword.
isConstant: every char isdigit.
```

**Step 3 — Operator vs comment (20 sec):**
```c
isOperator: strlen==1 and char in "+-*/=%<>";
isComment: s[0]=='/' && (s[1]=='/' || s[1]=='*');
```

**Step 4 — check() + main (30 sec):**
```c
check("int"); check("sum"); check("="); check("a");
check("+"); check("12"); check("// total");
```
Order in check(): comment → keyword → identifier → constant → operator.

How to practice: write Steps 1-3 as functions, then Step 4 calls. 2 times = done.

## 4. Full Program
See `program.c`. Compile & run:
```
gcc program.c -o exp02
./exp02
```

## 5. Expected Output
See `output.txt`. Key lines:
```
int        -> keyword
sum        -> identifier
=          -> operator
12         -> constant
// total   -> comment
```

## 6. How to write in exam (3 min version)
If short on time, keep only `isIdentifier`, `isConstant`, `isOperator`, `isComment` + 3-4 `check()` calls. Same marks.

## 7. Viva — 1 line answers
1. **What is lexical analysis?** First phase: source → tokens.
2. **Identifier rule?** Letter/_ first, then letters/digits/_.
3. **How to detect comment?** Starts with `//` or `/*`.
4. **Keyword vs identifier?** Keyword is reserved (strcmp list), rest are identifiers.
5. **Tool for this phase?** lex.
