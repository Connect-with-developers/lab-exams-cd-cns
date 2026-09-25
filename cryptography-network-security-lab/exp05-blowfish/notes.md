# Exp 05: Blowfish Logic — Java (JCE)

## 1. Aim
Implement Blowfish algorithm logic.

## 2. Description
- Blowfish = 64-bit block, variable key 32-448 bits, 16 Feistel rounds, 4 S-boxes + P-array.
- Fast, free, symmetric. Same JCE pattern as DES, only `"Blowfish"`.

## 3. Small steps
Step 1: If you learned Exp04 DES, just change `"DES"` → `"Blowfish"`. Done!
Step 2: Remember 2 points: variable key length, 16 rounds Feistel.
Step 3: Run `BlowfishDemo.java`.

```
javac BlowfishDemo.java
java BlowfishDemo
```

## 4. Output
See `output.txt`. Base64 differs each run (random key).

## 5. Viva
1. Block size? 64-bit. Key? 32-448 variable.
2. Structure? Feistel 16 rounds.
3. Designer? Bruce Schneier.
4. DES vs Blowfish? Blowfish has variable key, free, stronger.
