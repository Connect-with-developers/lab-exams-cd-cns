# Exp 03: Caesar, Substitution, Hill — Java

## 1. Aim
Java program for encryption/decryption using a. Caesar b. Substitution c. Hill.

## 2. Description (1-line each for exam)
- **Caesar:** shift each letter by key (ex. 3): `H->K, e->h`. Formula `C=(P+K)%26`.
- **Substitution:** replace each letter by fixed jumbled alphabet. Ex. `a->q, b->w...` Key = 26-letter string.
- **Hill:** take 2 letters as vector, multiply by 2x2 key matrix mod 26. Ex. key `[[3,3],[2,5]]`.

## 3. Learn small-steps → big (do in this order)

### Step 1 — Caesar first (easiest, 2 min)
Core line only:
```java
(ch - 'A' + shift) % 26 + 'A'  // for UPPER
(ch - 'a' + shift) % 26 + 'a'  // for lower
```
Logic: bring to 0-25, add shift, wrap with %, go back to ASCII.
Decrypt = encrypt with `26-shift`.

Practice: write `CaesarCipher.java` from memory once. If you can do this, 33% done.

### Step 2 — Substitution (copy Caesar pattern, 2 min)
No math, only lookup:
```java
plain  = "abcdefghijklmnopqrstuvwxyz";
cipher = "qwertyuiopasdfghjklzxcvbnm";
idx = plain.indexOf(ch) → cipher.charAt(idx)
```
Decrypt = reverse lookup.
Trick: same loop as Caesar, only mapping changes.

### Step 3 — Hill (only 1 example to mug, 5 min)
Don't learn full inverse theory. Mug this ONE standard key:
- Key = `[3 3; 2 5]`, Inverse = `[15 17; 20 9]`
- Steps: `HELLO` → pad to `HELLOX` → take pairs `HE | LL | OX` → `C = K*P %26`
- Ex. `H(7),E(4)`: `C0=3*7+3*4=33%26=7=H`, `C1=2*7+5*4=34%26=8=I` → `HI`...

For exam, if asked to write code, write the 2x2 multiply loop from `HillCipher.java`. If asked theory, draw matrix multiply.

Order to learn: **Caesar → Substitution → Hill**. Don't start with Hill.

## 4. Programs
- `CaesarCipher.java`, `SubstitutionCipher.java`, `HillCipher.java`
- Run:
```
javac *.java
java CaesarCipher
java SubstitutionCipher
java HillCipher
```

## 5. Expected Output
See `output.txt`:
- `Hello world` + shift 3 = `Khoor zruog`
- Substitution with `qwerty...` = `Itssg vgksr`
- Hill `HELLO` = `HIOZHN`, decrypt = `HELLOX` (X padding)

## 6. How to write fast in exam
Caesar 10-line version is enough. For Hill, write encrypt only if time less — mention padding and `%26`.

## 7. Viva
1. **Caesar key space?** 25 (26-1).
2. **Substitution key space?** 26! — bigger but still breakable by frequency analysis.
3. **Hill type?** Polygraphic, linear algebra, needs invertible matrix mod 26 (gcd(det,26)=1).
4. **Why padding X?** To make even length for 2x2.
5. **Which is strongest?** Hill > Substitution > Caesar.
