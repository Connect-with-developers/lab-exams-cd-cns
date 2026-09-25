# Exp 02: AND / XOR `Hello world` with 127 — C [LEARN]

> Same structure as Exp01 learn.md: Test First → Story → Concept → Code → Output → Exam Version → Viva → Perfect Checklist. notes.md untouched.

---

## 0. TEST FIRST
**Q1.** What is `72 & 127`? Options: 72 / 0 / 127
> Answer: 72. Normal letters <128 → AND 127 = same.

**Q2.** What is `72 ^ 127`? Options: 55 / 72 / 0
> Answer: 55. XOR flips 7 bits.

**Q3.** 127 in binary? Options: 01111111 / 11111111 / 10000000
> Answer: 01111111 (7 ones).

**Q4 [code].** Which operator for masking? `&` or `^`?
> Answer: `&` masks, `^` flips.

**Q5 [output].** XOR 127 result printable? Yes / No, print %d
> Answer: No, mostly control chars → print number %d.

If 4/5 → strong, go to Story. Else read Concept twice.

---

## 1. AIM
C program with `Hello world`. AND and XOR each char with 127, display result.

## 2. STORY
**Mask vs Evil Twin:**
- 127 = `01111111` = mask with 7 holes. Put mask on `H` → H stays H. That's `&127` = mask that keeps 7-bit ASCII.
- Same 127 as evil twin key: `H ^ 127 = 55` (garbage). That's flip.

Hook: **See `&127` → mask, same. See `^127` → flip, garbage numbers: H→55, e→26, space→95.**

Real world: masking to 7-bit for old systems, flipping = confusion in ciphers.

## 3. CONCEPT
- `&`: 1&1=1 else 0. So `ch & 01111111` clears 8th bit, keeps lower 7.
- `^`: different=1. So `ch ^ 01111111` inverts lower 7 bits.
- For ASCII <128, AND = no change. XOR = big change.

## 4. PROGRAM — same for-pattern as Exp01 (2 loops)
```c
#include <stdio.h>
int main() {
    char *str = "Hello world";
    printf("Original string: %s\n\n", str);
    printf("--- AND with 127 ---\n");
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        char res = ch & 127;
        printf("  %c  |  %d  |   %d   |   %c\n", ch, ch, res, res);
    }
    printf("\n--- XOR with 127 ---\n");
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        char res = ch ^ 127;
        printf("  %c  |  %d  |   %d   |   %d\n", ch, ch, res, res);
    }
    return 0;
}
```
Mug: Exp01 skeleton, change `^0` → `&127`, copy loop → `^127`. Print %c for AND, %d for XOR.

```
gcc program.c -o exp02
./exp02
```

## 5. OUTPUT
- AND: same `Hello world` (72→72, 101→101...)
- XOR: H→55, e→26, l→19, space→95, w→8... numbers only.

## 6. EXAM 3-MIN (same for-pattern, 1 loop ok)
```c
#include <stdio.h>
int main(){
 char *s="Hello world";
 for(int i=0;s[i]!='\0';i++) printf("%c &127=%d ^127=%d\n",s[i],s[i]&127,s[i]^127);
 return 0;
}
```

## 7. VIVA
1. AND 127 effect? Masks to 7-bit, clears 8th.
2. XOR 127 effect? Flips 7 bits, control chars.
3. 127 binary? 01111111.
4. Exp01 vs Exp02? 01 identity, 02 mask/flip.
5. Why %d for XOR? Non-printable.

## 8. PERFECT CHECKLIST
- [ ] Write both for-loops without seeing?
- [ ] H&127=72, H^127=55 from memory?
- [ ] Explain mask vs flip story?
- [ ] 5 viva in 1 line?
If all → perfect → next.
