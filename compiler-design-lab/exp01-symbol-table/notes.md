# Exp 01: Symbol Table — C

## 1. Aim (write this in exam)
Write a C program to implement a simple symbol table with insert, search and display (name, type, scope). Insert 3 symbols.

## 2. Description in simple words
- Symbol table = list the compiler keeps: variable name → type + scope.
- `struct Symbol { name, type, scope }` is one row. Array `table[10]` is the table.
- `insert` copies 3 strings with `strcpy`. `search` loops and uses `strcmp`.
- `display` prints all rows in a table.

Rule to remember: **insert = strcpy, search = strcmp loop, display = print loop.**

## 3. Learn in small steps (don't mug full program at once)

**Step 1 — Remember the skeleton (30 sec):**
```c
struct Symbol { char name[20], type[20], scope[20]; };
struct Symbol table[10]; int n = 0;
```

**Step 2 — Insert = strcpy (30 sec):**
```c
strcpy(table[n].name, name);
strcpy(table[n].type, type);
strcpy(table[n].scope, scope); n++;
```

**Step 3 — Search = strcmp loop (30 sec):**
```c
for (i = 0; i < n; i++)
  if (strcmp(table[i].name, name) == 0) return i;
return -1;
```

**Step 4 — main = 3 inserts + display + 2 searches (20 sec):**
```c
insert("x","int","local"); insert("y","float","global"); insert("z","char","local");
display(); search("y"); search("w");
```
**Step 5 — Full logic = Step1+2+3+4.** See `program.c`.

How to practice: cover the code, write Steps 1-4 from memory on paper. 2 times = done.

## 4. Full Program
See `program.c`. Compile & run:
```
gcc program.c -o exp01
./exp01
```

## 5. Expected Output
See `output.txt`. Key lines:
```
Name  Type  Scope
x     int   local
y     float global
z     char  local
Found y: float global
w not found
```

## 6. How to write in exam (3 min version)
Same program is already short (34 lines). Just write `program.c` as is.

## 7. Viva — 1 line answers
1. **What is a symbol table?** Compiler's list of names with type/scope/address.
2. **Why strcpy/strcmp?** To copy and compare name strings.
3. **What is scope?** Where a variable is visible (local vs global).
4. **What does search return?** Index if found, -1 if not.
5. **Which compiler phase uses it?** All phases — built by declaration, used by type checking/code gen.
