# Exp 04: DES Logic — Java (JCE)

## 1. Aim
Implement DES algorithm logic (C/JAVA).

## 2. Description — small to big
- **Big idea:** DES = 64-bit block, 56-bit key, 16 Feistel rounds. Each round: Expand → XOR key → S-box → Permute.
- **For lab/exam:** don't code 16 rounds by hand. Use Java Crypto (JCE) — accepted as "DES logic".
- Pattern (same for DES/Blowfish/AES, only name changes):
  1. `KeyGenerator.getInstance("DES")` → key
  2. `Cipher.getInstance("DES/ECB/PKCS5Padding")`
  3. `init(ENCRYPT)` → `doFinal()` → Base64
  4. `init(DECRYPT)` → `doFinal()` → plain

## 3. Small steps to learn
Step 1: mug Feistel diagram (1 box: L,R → E → XOR K → S → P → swap).
Step 2: mug 4 JCE lines above.
Step 3: run `DESDemo.java`. Output in `output.txt` (Base64 changes every run — that's OK, key is random).

## 4. Program / Output
See `DESDemo.java`, `output.txt`.
```
javac DESDemo.java
java DESDemo
```

## 5. Viva
1. Block/key size? 64-bit block, 56+8 parity key.
2. Rounds? 16.
3. Type? Feistel, symmetric.
4. Why Base64? To print binary as text.
5. DES secure today? No — brute-forceable, use AES.
