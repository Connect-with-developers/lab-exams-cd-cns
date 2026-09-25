# Exp 06: Rijndael (AES) Logic — Java (JCE)

## 1. Aim
Implement Rijndael algorithm logic.

## 2. Description
- Rijndael won AES competition → Rijndael = AES.
- 128-bit block, key 128/192/256, rounds 10/12/14. NOT Feistel — SPN (SubBytes, ShiftRows, MixColumns, AddRoundKey).

## 3. Small steps
Step 1: Same JCE pattern: `"AES"`, `kg.init(128)`.
Step 2: Remember: block 128, key 128, 10 rounds (for 128-bit).
Step 3: Difference from DES/Blowfish: SPN not Feistel, 128-bit not 64-bit.
```
javac AESDemo.java
java AESDemo
```

## 4. Output
See `output.txt`.

## 5. Viva
1. Rijndael vs AES? Rijndael is algorithm, AES is standard.
2. Block/key? 128-bit block, 128/192/256 key.
3. Rounds for 128? 10.
4. Structure? SPN, not Feistel.
