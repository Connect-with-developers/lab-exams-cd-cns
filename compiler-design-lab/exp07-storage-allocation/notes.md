# Exp 07: Storage Allocation — C

## 1. Aim (write this in exam)
Write a C program to demo static vs stack vs heap storage (static int, local variable address, malloc address).

## 2. Description in simple words
- `static int s` → static: one fixed address, lives whole program run.
- `int local` inside main → stack: created when function starts, address in stack frame.
- `malloc()` → heap: manual memory, address from heap, must `free()`.
- Print all three addresses with `%p` — they fall in 3 different regions.

Rule to remember: **static = fixed, stack = local, heap = malloc+free.**

## 3. Learn in small steps

**Step 1 — Three declarations (30 sec):**
```c
static int s = 10;
int local = 20;
int *heap = (int*)malloc(sizeof(int)); *heap = 30;
```

**Step 2 — Print values + addresses (30 sec):**
```c
printf("static s = %d at %p\n", s, (void*)&s);
printf("stack local = %d at %p\n", local, (void*)&local);
printf("heap *heap = %d at %p\n", *heap, (void*)heap);
```

**Step 3 — One-line meaning (20 sec):**
```c
// static: whole run, stack: main frame, heap: malloc
```

**Step 4 — Free heap (10 sec):**
```c
free(heap);
```

How to practice: write Step 1, then 3 printfs, then free. 2 times = done.

## 4. Full Program
See `program.c`. Compile & run:
```
gcc program.c -o exp07
./exp07
```

## 5. Expected Output
See `output.txt`. Key point (addresses change every run — tell examiner this):
```
static s   = 10 at 0x...   (fixed region)
stack local= 20 at 0x...   (stack region)
heap *heap = 30 at 0x...   (heap region)
```

## 6. How to write in exam (3 min version)
Program is 18 lines — write as is. Don't forget `(void*)` cast for `%p` and `free()`.

## 7. Viva — 1 line answers
1. **3 allocation types?** Static (compile time), stack (function call), heap (malloc).
2. **Who frees stack?** Auto — on function return.
3. **Who frees heap?** Programmer — `free()`, else leak.
4. **Where is static stored?** Data segment, fixed address.
5. **Why addresses differ each run?** ASLR/stack randomization + fresh malloc.
