# Exp 12: FIRST Function — C

## 1. Aim (write this in exam)
Write a C program to compute FIRST for E→E+T|T, T→T*F|F, F→(E)|id. Output FIRST(E)=FIRST(T)=FIRST(F)={(,id}.

## 2. Description in simple words
- FIRST(X) = set of terminals that can start X.
- FIRST(F): F→(E) starts with `(`; F→id starts with `id`. So {(, id}.
- FIRST(T): T→T*F|F — starts with whatever F starts with. So same {(, id}.
- FIRST(E): E→E+T|T — starts with whatever T starts with. So same {(, id}.

Rule to remember: **bottom-up: F first, then T=F, then E=T.**

## 3. Learn in small steps

**Step 1 — Print grammar (20 sec):**
```c
E -> E+T | T,  T -> T*F | F,  F -> (E) | id
```

**Step 2 — FIRST(F) direct (20 sec):**
```c
// F->(E) gives '(', F->id gives id
FIRST(F) = { (, id }
```

**Step 3 — Propagate up (20 sec):**
```c
FIRST(T) = FIRST(F)   // T->F
FIRST(E) = FIRST(T)   // E->T
```

**Step 4 — Final answer line (10 sec):**
```c
FIRST(E)=FIRST(T)=FIRST(F)={(,id}
```

How to practice: say "F direct, T from F, E from T" 3 times, then write program. Done.

## 4. Full Program
See `program.c`. Compile & run:
```
gcc program.c -o exp12
./exp12
```

## 5. Expected Output
See `output.txt`. Key line:
```
Answer: FIRST(E)=FIRST(T)=FIRST(F)={(,id}
```

## 6. How to write in exam (3 min version)
14 lines — write as is. Examiner wants the 3-step chain, not just the answer.

## 7. Viva — 1 line answers
1. **What is FIRST?** Terminals that can appear first in a derivation.
2. **Why FIRST(F)={(,id}?** From F→(E) and F→id directly.
3. **Why all three equal?** E→T and T→F chain passes the set up.
4. **Use of FIRST?** Building LL(1) parse tables.
5. **FIRST(E+T)?** Same {(, id} since E starts it.
