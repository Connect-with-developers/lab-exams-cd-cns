# Exp 03: Caesar, Substitution, Hill — Java [LEARN]

> Same structure: Test First → Story → Concept → Code → Output → Exam → Viva → Perfect. notes.md untouched.

## 0. TEST FIRST
**Q1.** Caesar shift 3: `H` → ? Options: K / I / J
> Answer: K (H+3).

**Q2.** Substitution: no math, only lookup? True/False
> Answer: True. a→q via key string.

**Q3.** Hill needs? Options: matrix × mod26 / shift / lookup
> Answer: matrix × mod26.

**Q4.** `HELLO` length 5, Hill 2x2 needs even → ? Options: pad X → HELLOX / remove O / nothing
> Answer: pad X.

If 3/4 → go Story. Else read Concept.

## 1. AIM
Java encrypt/decrypt: a.Caesar b.Substitution c.Hill.

## 2. STORY
- **Caesar = queue jump:** 26 chairs circle, you jump 3 ahead. H→K, e→h. `Hello→Khoor`. Brutus killed Caesar, now you kill exam with +3.
- **Substitution = secret phonebook:** a saved as q, b as w... key=`qwerty...`. `Hello→Itssg`. Bigger book (26!) but still spy can guess by frequency (e most common).
- **Hill = pair dance:** take 2 letters, multiply by matrix `[[3,3],[2,5]]`. `HELLO→HIOZHN`. Strongest of 3.

Hook: **jump → phonebook → dance. Easy→hard.**

## 3. CONCEPT
- Caesar: `C=(P+K)%26`. Bring A=0, +3, %26 wrap, back to ASCII.
- Substitution: `plain.indexOf(ch) → cipher.charAt(idx)`.
- Hill: `C=K*P%26`, pairs, pad X if odd.

## 4. CODE (learn Caesar first, 2 min)
```java
// Caesar heart
(ch - 'A' + shift) % 26 + 'A'  // UPPER
(ch - 'a' + shift) % 26 + 'a'  // lower
// decrypt = encrypt with 26-shift
```
Substitution heart: `cipher.charAt(plain.indexOf(ch))`
Hill heart: `c0=(3*p0+3*p1)%26; c1=(2*p0+5*p1)%26`

```
javac *.java
java CaesarCipher  // Khoor zruog
java SubstitutionCipher // Itssg vgksr
java HillCipher // HIOZHN
```

## 5. OUTPUT
- Caesar: Hello→Khoor zruog
- Sub: Hello→Itssg vgksr
- Hill: HELLO→HIOZHN, back HELLOX (X padding)

## 6. EXAM 3-MIN
Write Caesar 10 lines only if time less. For Hill write encrypt + mention inverse `[15 17;20 9]`.

## 7. VIVA
1. Caesar keys? 25.
2. Sub keys? 26! but frequency breakable.
3. Hill type? polygraphic, needs invertible (gcd(det,26)=1).
4. Why X? even length.
5. Strongest? Hill>Sub>Caesar.

## 8. PERFECT CHECKLIST
- [ ] H+3=K without seeing?
- [ ] Sub lookup line?
- [ ] Hill key + pad X?
- [ ] 5 viva?
