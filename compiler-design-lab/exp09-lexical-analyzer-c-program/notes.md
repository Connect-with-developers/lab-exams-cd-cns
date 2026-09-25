# Exp 09: Lexical Analyzer in C — Count Tokens

## 1. Aim (write this in exam)
Write a C program to count keywords, identifiers, numbers and operators in a sample string.

## 2. Description in simple words
- Scan the string char by char: letter→collect word (keyword or identifier), digit→collect number, `+-*/=`→operator, space/`;`→skip.
- Sample: `int a = b + 12; float c = a * 2;` gives kw=2, id=4, num=2, op=4.
- `isKeyword()` checks against small list; else it is an identifier.

Rule to remember: **letter=word, digit=number, symbol=operator.**

## 3. Learn in small steps

**Step 1 — Skeleton + counters (30 sec):**
```c
char s[] = "int a = b + 12; float c = a * 2;";
int kw=0, id=0, num=0, op=0, i=0;
```

**Step 2 — Word branch (30 sec):**
```c
if (isalpha(s[i])) { collect while alnum; if (isKeyword(w)) kw++; else id++; }
```

**Step 3 — Number + operator branch (30 sec):**
```c
else if (isdigit(s[i])) { collect digits; num++; }
else if (strchr("+-*/=", s[i])) { op++; i++; }
```

**Step 4 — Skip + final print (20 sec):**
```c
if (isspace(s[i]) || s[i]==';') i++;
printf("keywords=%d identifiers=%d numbers=%d operators=%d\n", kw,id,num,op);
```

How to practice: write Step 1, then if-else chain 2+3. 2 times = done.

## 4. Full Program
See `program.c`. Compile & run:
```
gcc program.c -o exp09
./exp09
```

## 5. Expected Output
See `output.txt`. Key line:
```
keywords=2 identifiers=4 numbers=2 operators=4
```
(int, float = keywords; a,b,c,a = identifiers; 12,2 = numbers; =,+,=,* = operators.)

## 6. How to write in exam (3 min version)
Already 33 lines — write as is. If short on time, drop the per-token printf, keep only counters + final line.

## 7. Viva — 1 line answers
1. **What is a token?** Smallest unit: keyword/identifier/number/operator.
2. **How are keywords found?** strcmp against reserved list.
3. **Why skip `;` and space?** Separators, not counted tokens here.
4. **Which phase is this?** Lexical analysis (scanner).
5. **lex vs this C program?** lex auto-generates scanner; here we hand-write it.
