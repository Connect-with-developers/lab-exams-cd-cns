# Exp 06: Type Checking — C

## 1. Aim (write this in exam)
Write a C program for simple type checking: int+int→int, int+float→float, error if variable undeclared.

## 2. Description in simple words
- Compiler must check `a+b` is legal and find result type.
- `getType()`: hardcoded table — `a`=int, `b`=float, anything else = NULL (undeclared).
- Rule: if either side is float → answer float, else int. If any side NULL → error.

Rule to remember: **float wins; unknown name = error.**

## 3. Learn in small steps

**Step 1 — Type table (20 sec):**
```c
if (strcmp(name,"a")==0) return "int";
if (strcmp(name,"b")==0) return "float";
return NULL;
```

**Step 2 — Undeclared check (30 sec):**
```c
char *t1 = getType(op1), *t2 = getType(op2);
if (t1 == NULL) printf("ERROR: %s undeclared", op1);
```

**Step 3 — Result type = one line (20 sec):**
```c
char *res = (t1=="float" || t2=="float") ? "float" : "int";
```

**Step 4 — main tests all 3 cases (20 sec):**
```c
check("a","+","a"); // int
check("a","+","b"); // float
check("a","+","c"); // error
```

How to practice: write Step 1, then Steps 2+3 as `check()`. 2 times = done.

## 4. Full Program
See `program.c`. Compile & run:
```
gcc program.c -o exp06
./exp06
```

## 5. Expected Output
See `output.txt`. Key lines:
```
a(int) + a(int) -> int
a(int) + b(float) -> float
a + c -> ERROR: c undeclared
```

## 6. How to write in exam (3 min version)
Program is already 22 lines — write as is. Just don't forget the NULL check.

## 7. Viva — 1 line answers
1. **Type checking rule here?** float + anything = float, int+int = int.
2. **What is undeclared error?** Variable used without declaration (no type found).
3. **Which phase does this?** Semantic analysis (after parsing).
4. **What is type coercion?** Auto-convert int→float in mixed expression.
5. **Why needed?** Catches `int + undeclared` before code generation.
