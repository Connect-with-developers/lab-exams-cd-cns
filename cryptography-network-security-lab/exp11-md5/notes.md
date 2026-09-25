# Exp 11: MD5 — Java

## 1. Aim
Message digest using MD5 in JAVA.

## 2. Description
- MD5 = 128-bit hash (32 hex chars). Faster but broken.
- Same code as SHA-1, only `"MD5"`.

## 3. Small steps
Step 1: If you learned Exp10, change `"SHA-1"` → `"MD5"`. Done!
Step 2: Remember output for "Hello world": `3e25960a79dbc69b674cd4ec67a72c62` (32 chars).
Step 3: Difference: SHA-1=40 chars/160-bit, MD5=32 chars/128-bit.
```
javac MD5Demo.java
java MD5Demo
```

## 4. Output
See `output.txt`.

## 5. Viva
1. Size? 128 bits / 32 hex.
2. MD5 vs SHA-1? MD5 smaller, faster, less secure.
3. Use? Checksums, but not for security now.
4. Collision? Yes — MD5 broken.
