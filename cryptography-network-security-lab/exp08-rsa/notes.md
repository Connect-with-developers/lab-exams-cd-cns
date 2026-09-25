# Exp 08: RSA — Java

## 1. Aim
Java program to implement RSA.

## 2. Description — small to big
- RSA = asymmetric. Public (e,n) encrypts, Private (d,n) decrypts.
- Mug ONE numbers set: `p=61, q=53 → n=3233, phi=3120, e=17, d=2753`. Msg 65 → Enc 2790 → Dec 65.
- Formulas:
  1. `n=p*q`, `phi=(p-1)*(q-1)`
  2. Choose `e` with gcd(e,phi)=1
  3. `d = e^-1 mod phi`
  4. `C=M^e mod n`, `M=C^d mod n`

## 3. Small steps
Step 1: Write `modPow` once (copy from program — same for RSA+DH).
Step 2: Write main with fixed numbers above — don't calculate d in exam, just write `d=2753`.
Step 3: Encrypt then decrypt, print.
```
javac RSADemo.java
java RSADemo
```

## 4. Output
See `output.txt` — 65→2790→65.

## 5. Viva
1. RSA full form? Rivest-Shamir-Adleman.
2. Why secure? Factoring n hard.
3. e,d relation? d*e ≡1 mod phi.
4. Symmetric vs asymmetric? RSA asymmetric, 2 keys.
