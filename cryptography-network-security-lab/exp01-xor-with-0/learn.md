# Exp 01: XOR `Hello world` with 0 — C [MASTER TEMPLATE]

> Follow this same structure for EVERY exp: Test First → Story → Concept → Code → Output → Exam Version → Viva → Perfect Checklist.

---

## 0. TEST FIRST (answer before reading below)
Don't read explanation first. Test yourself:

**Q1.** What is `72 ^ 0`? Options: 72 / 0 / 73
> Answer: 72. If you said 72 → you know identity.

**Q2.** What is `'\0'`? Why `while(str[i]!='\0')`?
> Answer: End of string. Loop till string ends.

**Q3.** Which is correct? A) `1^1=0, 1^0=1`  B) Both=1
> Answer: A. Different→1, Same→0.

**Q4 [code].** What does `char *str = "Hello world"` mean?
> Answer: str points to 'H', str[0]=H, str[1]=e... continuous memory ending with '\0'.

**Q5 [output].** If input `H`, output after `^0` = ?
> Answer: H (72→72).

If 4/5 correct → base strong, go to Story for locking. If <4 → read Concept twice.

---

## 1. AIM (write in exam - 1 line)
Write a C program with string (char pointer) `Hello world`. XOR each character with 0 and display result.

## 2. STORY (remember when you see question)
**The Ghost Key:** Locker = `H(72)`. Key = ghost `0` (transparent, does nothing).
`H ^ ghost = H`. 11 lockers (Hello world) + ghost key = same 11 lockers.

Hook: **See `^0` in question → see ghost → say "no change, identity".**

Real world link:
- Real crypto = `msg ^ secret_key`. If key=0 → no security. This exp proves it.
- `A ^ 0 = A`, `A ^ A = 0`, `A ^ K ^ K = A` (last = how decryption works in OTP/stream ciphers).

## 3. CONCEPT in simple words
- `^` = XOR bitwise: `0^0=0, 0^1=1, 1^0=1, 1^1=0` (different=1).
- `char` = 1 byte ASCII number. `H=72, e=101, space=32`.
- `ch ^ 0` = each bit XOR 0 = same bit → same char.
- Loop till `'\0'` to cover all chars.

## 4. PROGRAM — line by line (mug in 4 steps, not at once)

Full file: `program.c`
```c
#include <stdio.h>
int main() {
    char *str = "Hello world";  // Step 1: skeleton - string pointer
    int i = 0;
    printf("Original string: %s\n", str);
    printf("Char | ASCII | XOR with 0 | Result Char\n");
    while (str[i] != '\0') {    // Step 2: loop till end
        char ch = str[i];       // take one locker
        char xored = ch ^ 0;    // Step 3: THE ONE crypto line - ghost key
        printf("  %c  |  %3d  |     %3d    |      %c\n", ch, ch, xored, xored); // Step 4: print
        i++;
    }
    printf("\nXOR with 0 does not change the character.\n");
    return 0;
}
```

**How to mug:**
- Day 1: Write Step1+2 from memory 2 times (skeleton+loop).
- Day 2: Add Step3 (1 line) + Step4 (printf). Cover and write full 2 times.
- Never mug full 21 lines at once.

Compile & run:
```
gcc program.c -o exp01
./exp01
```

## 5. EXPECTED OUTPUT — what to explain to examiner
File: `output.txt`
```
Original string: Hello world
Char | ASCII | XOR with 0 | Result Char
  H  |   72  |      72    |      H
  e  |  101  |     101    |      e
  ... same for all ...
Result string: Hello world
```
Explain: `H(72)^0=72(H), e(101)^0=101(e), space(32)^0=32`. No change → proves identity.

## 6. EXAM 3-MIN VERSION (if time less, still full marks)
```c
#include <stdio.h>
int main(){
 char *s="Hello world"; int i=0;
 while(s[i]!='\0') printf("%c ^ 0 = %c (%d)\n",s[i],s[i]^0,s[i]^0),i++;
 return 0;
}
```
Logic same, shorter print. Use this if you forget table header.

## 7. VIVA — 1 line answers (mug these 5)
1. **What does XOR with 0 do?** No change. Identity property.
2. **Why char pointer?** Stores string, traverse by index till '\0'.
3. **What is '\0'?** String terminator, ASCII 0.
4. **XOR truth table?** 0^0=0, 0^1=1, 1^0=1, 1^1=0.
5. **Use in crypto?** Base of stream ciphers/OTP. `M^K^K=M`.

Extra viva trap:
- **What is `H ^ H`?** 0. (Same→0)
- **XOR with 0 vs 127?** 0=no change, 127=flips 7 bits (next exp).

## 8. PERFECT CHECKLIST (tick before going to Exp02)
- [ ] Can write skeleton + loop without seeing?
- [ ] Can write `ch ^ 0` line + explain ghost story?
- [ ] Can write output for H,e,l (72,101,108 → same)?
- [ ] Can answer all 5 viva in 1 line?
- [ ] Can write 3-min version in <3 min?

If all ticked → perfect → go to Exp02. Else repeat Section 4 once.
