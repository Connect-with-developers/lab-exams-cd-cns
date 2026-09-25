# HOW-TO-LEARN — Small Steps to Big (for both labs)

Don't mug full program at once. Use this 4-step loop for EVERY experiment:

## The Loop (10 min per exp)
1. **Read Aim (30 sec)** — open `notes.md` top. Say it aloud.
2. **Learn 1 core line (2 min)** — every notes.md has Step 1-2-3. Only mug the core:
   - CNS: `ch^0`, `(ch-'A'+shift)%26`, `K*P%26`, `Cipher.getInstance`, `modPow`, `MessageDigest`
   - CD: `while(s[i]!='\0')`, `S[i]=i shuffle`, `E->T+E`, `FIRST={(,id}`, `lex %{ %}%`
3. **Run + see output (3 min)** — `gcc` / `javac` / open `index.html`. Match with `output.txt`.
4. **Write from memory (5 min)** — close laptop, write skeleton on paper. Check. Done.

## Order — easy to hard (don't start random)

### CNS (11)
1. Exp01 XOR-0 → Exp02 AND/XOR-127 (same loop, 10 min both)
2. Exp10 SHA1 → Exp11 MD5 (same 2 lines, 10 min both)
3. Exp03 Caesar → Substitution → Hill (easy→hard)
4. Exp08 RSA → Exp09 DH (same modPow)
5. Exp04 DES → Exp05 Blowfish → Exp06 AES → Exp07 RC4 (same JCE pattern, RC4 manual last)

2 days: Day1 = 1+2+3, Day2 = 4+5.

### CD (13)
1. Exp08 word-count (easiest lex) → Exp03 lex-tool → Exp02/09 C analyzers
2. Exp01 symbol table → Exp06 type check → Exp07 storage (all table-like)
3. Exp10 E-T-F → Exp11 S-L → Exp12 FIRST (same grammar family)
4. Exp04 yacc 3-in-1 → Exp13 eval → Exp05 AST (hardest last)

2 days: Day1 = 1+2, Day2 = 3+4.

## Exam-day tricks
- Forget full code? Write minimal version from notes.md Section 6 — logic marks = full.
- Output numbers to mug: RSA 65→2790→65, DH 8,19,2, Caesar Khoor, Hill HIOZHN, SHA1 40 chars, MD5 32 chars, calc 3+5*2=13.
- Viva: read only Section 7 of each notes.md (5 Qs). 5 min per exp.
- Lex/YACC commands (write on hall ticket margin):
```
lex file.l
yacc -d file.y
gcc lex.yy.c y.tab.c -o out
./out
```
