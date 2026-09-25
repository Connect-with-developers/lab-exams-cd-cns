# Exp 02: AND / XOR `Hello world` with 127 — C

## 1. Aim
C program with string `Hello world`. AND and XOR each character with 127 and display result.

## 2. Description in simple words
- 127 = `01111111` in binary (7 ones). Max ASCII (DEL).
- `AND with 127`: `ch & 127` clears 8th bit. For normal letters (ASCII <128) → **no change**.
- `XOR with 127`: `ch ^ 127` flips lower 7 bits. `H(72) ^ 127 = 55`, `space(32)^127=95(_)`. Output becomes non-printable mostly.
- This shows masking and flipping — basic idea of confusion in ciphers.

Remember: **AND 127 = mask to 7-bit ASCII. XOR 127 = invert 7 bits.**

## 3. Learn in small steps

**Step 1 — Same skeleton as Exp01:**
```c
char *str = "Hello world";
```

**Step 2 — AND part (learn first):**
```c
char res_and = ch & 127;
printf("%c & 127 = %c (%d)\n", ch, res_and, res_and);
```

**Step 3 — XOR part (copy same, change operator):**
```c
char res_xor = ch ^ 127;
printf("%c ^ 127 = %d\n", ch, res_xor);
```
Don't print `%c` for XOR — result is non-printable, print number.

**Step 4 — Two loops or one loop?** Exam allows either. Our `program.c` uses 2 loops for clarity. One loop also ok.

Practice: Write Exp01 from memory, then change `^0` to `&127` and `^127`. Done — 2 exps in 1 pattern.

## 4. Full Program
See `program.c`:
```
gcc program.c -o exp02
./exp02
```

## 5. Expected Output
See `output.txt`. Key points to tell examiner:
- AND 127 → same string `Hello world` (72→72, 101→101...)
- XOR 127 → numbers: H→55, e→26, l→19, space→95...

## 6. How to write fast in exam
```c
#include <stdio.h>
int main(){
 char *s="Hello world"; int i=0;
 while(s[i]!='\0'){printf("%c &127=%d ",s[i],s[i]&127);printf("^127=%d\n",s[i]^127);i++;}
 return 0;
}
```

## 7. Viva
1. **AND with 127 effect?** Keeps 7-bit ASCII, clears 8th bit.
2. **XOR with 127 effect?** Flips 7 bits, gives mostly control chars.
3. **127 in binary?** 01111111.
4. **Difference Exp01 vs Exp02?** Exp01 identity, Exp02 masking/flipping.
5. **Why print %d for XOR?** Result non-printable, number is readable.
