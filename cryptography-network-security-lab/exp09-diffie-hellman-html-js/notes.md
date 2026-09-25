# Exp 09: Diffie-Hellman — HTML + JavaScript

## 1. Aim
Implement DH Key Exchange using HTML and JS.

## 2. Description
- DH lets Alice & Bob make shared secret over insecure channel.
- Mug example: `p=23, g=5, a=6, b=15 → A=8, B=19, secret=2`.
- Steps:
  1. Alice sends `A=g^a mod p`
  2. Bob sends `B=g^b mod p`
  3. Both compute `secret = B^a = A^b mod p`

## 3. Small steps
Step 1: Learn `modPow(base,exp,mod)` — same as RSA.
Step 2: HTML = 4 inputs (p,g,a,b) + button + `<pre>` output.
Step 3: JS `exchange()` = 4 lines: A, B, sA, sB.
- Open `index.html` in browser → click Exchange → see SUCCESS secret=2.
- No server needed.

## 4. Output
See `output.txt`. For viva write: A=8, B=19, secret=2.

## 5. Viva
1. DH purpose? Secret key without prior sharing.
2. Security based on? Discrete log hard.
3. Vulnerable to? Man-in-middle (no auth).
4. p,g public or private? Public. a,b private.
