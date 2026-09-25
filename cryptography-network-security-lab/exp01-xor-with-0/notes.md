# Exp 01: XOR `Hello world` with 0 — C

## 1. Aim (write this in exam)
Write a C program with string (char pointer) `Hello world`. XOR each character with 0 and display result.

## 2. Description in simple words
- `char *str = "Hello world"` means `str` points to H, then e, l, l, o...
- `^` is XOR: `0^0=0, 1^0=1, 1^1=0`. So **anything XOR 0 = same thing**.
- Loop till `'\0'` (end of string), XOR each char, print.

Rule to remember: **XOR with 0 = no change. This proves XOR identity property used in crypto.**

## 3. Learn in small steps (don't mug full program at once)

**Step 1 — Remember the skeleton (30 sec):**
```c
#include <stdio.h>
int main() {
  char *str = "Hello world";
  // loop + print
  return 0;
}
```

**Step 2 — Remember the loop (30 sec):**
```c
int i = 0;
while (str[i] != '\0') {
  char ch = str[i];
  i++;
}
```
This is just "go till string ends".

**Step 3 — Add the ONE crypto line (20 sec):**
```c
char xored = ch ^ 0;
```
That's the whole experiment.

**Step 4 — Add printing (20 sec):**
```c
printf("%c -> %d -> %c\n", ch, ch, xored);
```

**Step 5 — Full logic = Step1+2+3+4.** See `program.c`.

How to practice: cover the full code, write Steps 1-4 from memory on paper. 2 times = done.

## 4. Full Program
See `program.c`. Compile & run:
```
gcc program.c -o exp01
./exp01
```

## 5. Expected Output
See `output.txt`. Key line:
```
XOR with 0 does not change the character.
Result string: Hello world
H(72) ^ 0 = 72(H), e(101)^0=101(e)... same.
```

## 6. How to write in exam (3 min version)
If short on time, write minimal version:
```c
#include <stdio.h>
int main(){
 char *s="Hello world"; int i=0;
 while(s[i]!='\0') printf("%c ^ 0 = %c (%d)\n",s[i],s[i]^0,s[i]^0),i++;
 return 0;
}
```
Still gets full marks — logic is same.

## 7. Viva — 1 line answers
1. **What does XOR with 0 do?** No change. Identity.
2. **Why char pointer?** To store string and traverse by index.
3. **What is `\0`?** String terminator.
4. **XOR truth table?** 0^0=0, 0^1=1, 1^0=1, 1^1=0.
5. **Use in crypto?** XOR is base of stream ciphers, OTP.
