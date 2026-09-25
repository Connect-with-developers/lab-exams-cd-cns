# Exp 10: Recursive Descent for E → T+E | T, T → F*T | F, F → (E) | id

## 1. Aim (write this in exam)
Write a recursive descent parser for E→T+E|T, T→F*T|F, F→(E)|id (left recursion eliminated). Test `a+b*c` and `a*(b+c)`.

## 2. Description in simple words
- One function per non-terminal: `E()`, `T()`, `F()` call each other.
- Original grammar `E→E+T` is left-recursive (parser loops). Right-recursive `E→T+E` fixes it.
- Global `ip` string + `pos` index. `F`: if `(` parse E then expect `)`, else one letter = id. `E`: T then if `+` parse E. `T`: F then if `*` parse T.
- Accept only if no error AND full string consumed (`pos == strlen`).

Rule to remember: **E eats +, T eats *, F eats brackets/id.**

## 3. Learn in small steps

**Step 1 — Globals (20 sec):**
```c
char *ip; int pos, err;
```

**Step 2 — E and T = one if each (30 sec):**
```c
void E() { T(); if (ip[pos]=='+') { pos++; E(); } }
void T() { F(); if (ip[pos]=='*') { pos++; T(); } }
```

**Step 3 — F = bracket or letter (30 sec):**
```c
void F() {
  if (ip[pos]=='(') { pos++; E(); if (ip[pos]==')') pos++; else err=1; }
  else if (a<=ip[pos]<='z') pos++; else err=1;
}
```

**Step 4 — test() driver (30 sec):**
```c
ip=s; pos=0; err=0; E();
if (!err && pos==strlen(s)) Accepted; else Rejected;
```

How to practice: write Steps 2+3 from memory, then Step 4 with `a+b*c`, `a*(b+c)`. 2 times = done.

## 4. Full Program
See `program.c`. Compile & run:
```
gcc program.c -o exp10
./exp10
```

## 5. Expected Output
See `output.txt`. Key lines:
```
a+b*c      -> Accepted
a*(b+c)    -> Accepted
a+*b       -> Rejected
```

## 6. How to write in exam (3 min version)
Program is 27 lines — write as is. Minimum: E/T/F + test with the 2 valid strings.

## 7. Viva — 1 line answers
1. **Why eliminate left recursion?** Recursive descent loops forever on E→E+T.
2. **What is F (factor)?** Base: bracketed expr or id.
3. **How is id recognized here?** Single lowercase letter (simplified).
4. **When Accepted?** No error and full input consumed.
5. **Top-down or bottom-up?** Top-down (starts from E, expands down).
