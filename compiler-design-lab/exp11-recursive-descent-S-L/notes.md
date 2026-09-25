# Exp 11: Recursive Descent for S → (L) | a, L → S,L | S

## 1. Aim (write this in exam)
Write a recursive descent parser for S→(L)|a, L→S,L|S. Test `(a,(a,a))` valid, `(a,` invalid.

## 2. Description in simple words
- `S` is either bracketed list `(L)` or single `a`. `L` is `S` or `S,L` (comma list).
- Two functions call each other: S→L→S (mutual recursion) — handles nesting like `(a,(a,a))`.
- Same driver as Exp10: global `ip`, `pos`, `err`; accept only if full string eaten.

Rule to remember: **S = bracket or a; L = S comma S...**

## 3. Learn in small steps

**Step 1 — Same globals as Exp10 (10 sec):**
```c
char *ip; int pos, err;
```

**Step 2 — S function (30 sec):**
```c
void S() {
  if (ip[pos]=='(') { pos++; L(); if (ip[pos]==')') pos++; else err=1; }
  else if (ip[pos]=='a') pos++; else err=1;
}
```

**Step 3 — L function = one if (20 sec):**
```c
void L() { S(); if (!err && ip[pos]==',') { pos++; L(); } }
```

**Step 4 — test() same as Exp10 (20 sec):**
```c
ip=s; pos=0; err=0; S();
if (!err && pos==strlen(s)) Accepted; else Rejected;
// tests: "(a,(a,a))" valid, "(a," invalid
```

How to practice: if you know Exp10, only Steps 2-3 are new. Write them twice = done.

## 4. Full Program
See `program.c`. Compile & run:
```
gcc program.c -o exp11
./exp11
```

## 5. Expected Output
See `output.txt`. Key lines:
```
(a,(a,a))    -> Accepted
(a,          -> Rejected
```

## 6. How to write in exam (3 min version)
25 lines — write as is. Examiner checks the 2 test strings, don't skip them.

## 7. Viva — 1 line answers
1. **What language is this?** Balanced parens with a's and commas (nested lists).
2. **Why is `(a,` rejected?** Missing closing `)` and second S after comma.
3. **S vs L?** S = single item, L = comma-separated list of S.
4. **Left recursion here?** Original L→L,S was left-recursive; L→S,L|S is fixed.
5. **Difference from Exp10?** Exp10 parses expressions (+,*), this parses nested lists.
