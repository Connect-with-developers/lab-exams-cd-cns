# Exp 10: SHA-1 — Java

## 1. Aim
Message digest using SHA-1 in JAVA.

## 2. Description
- SHA-1 = 160-bit hash (40 hex chars). One-way, fixed size.
- Pattern (same for SHA-1 & MD5, only name changes):
```java
MessageDigest md = MessageDigest.getInstance("SHA-1");
byte[] digest = md.digest(text.getBytes());
// bytes → hex with %02x
```

## 3. Small steps
Step 1: Learn 2 lines above.
Step 2: Learn hex loop (copy-paste).
Step 3: Remember output for "Hello world": `7b502c3a1f48c8609ae212cdfb639dee39673f5e` (40 chars).
```
javac SHA1Demo.java
java SHA1Demo
```

## 4. Output
See `output.txt`.

## 5. Viva
1. Output size? 160 bits / 40 hex.
2. Reversible? No, one-way.
3. Use? Integrity, password storing, certs.
4. Secure? No — collisions found, use SHA-256.
