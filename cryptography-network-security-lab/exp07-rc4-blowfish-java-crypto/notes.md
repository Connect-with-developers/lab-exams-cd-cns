# Exp 07: RC4 + Blowfish with own key — Java

## 1. Aim
RC4 logic in Java using Java crypto; encrypt “Hello world” using Blowfish. Create own key using Java key tool (KeyGenerator).

## 2. Description
- **RC4:** stream cipher. 2 parts: KSA (shuffle S[0..255] with key) + PRGA (generate keystream, XOR with data). Exam-writable ~15 lines — mug it.
- **Blowfish part:** same JCE as Exp05, but highlight `KeyGenerator.getInstance("Blowfish")` = "create your own key". In real Java, `keytool` creates certs; `KeyGenerator` creates secret keys — examiner accepts this.
- Our `RC4BlowfishDemo.java` does both.

## 3. Small steps
Step 1 — Learn RC4 KSA (shuffle):
```java
for i 0..255 S[i]=i;
j=0; for i 0..255 { j=(j+S[i]+key[i%keylen])%256; swap(S[i],S[j]); }
```
Step 2 — Learn PRGA (generate + XOR):
```java
i=0;j=0; for each byte: i=(i+1)%256; j=(j+S[i])%256; swap; out = data ^ S[(S[i]+S[j])%256];
```
Step 3 — Blowfish part = copy Exp05 (3 lines).
```
javac RC4BlowfishDemo.java
java RC4BlowfishDemo
```

## 4. Output
See `output.txt`. RC4 Base64 for "Hello world"+"mykey" = `HgPpAhtkygn4vIM=` (fixed, since key fixed). Blowfish Base64 changes (random key).

## 5. Viva
1. RC4 type? Stream, variable key, byte-wise XOR.
2. KSA vs PRGA? KSA shuffles, PRGA generates stream.
3. How own key created? `KeyGenerator.getInstance("Blowfish").generateKey()`.
4. RC4 secure? No — WEP broken, biases.
