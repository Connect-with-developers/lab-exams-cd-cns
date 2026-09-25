public class RSADemo {
    static long modPow(long base, long exp, long mod) {
        long res = 1;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
    public static void main(String[] args) {
        // Small exam example: p=61, q=53
        long p = 61, q = 53;
        long n = p * q;              // 3233
        long phi = (p-1)*(q-1);      // 3120
        long e = 17;                 // public exponent
        // d = e^-1 mod phi = 2753
        long d = 2753;
        long msg = 65;               // example: 'A' = 65
        long enc = modPow(msg, e, n);
        long dec = modPow(enc, d, n);
        System.out.println("p=" + p + " q=" + q + " n=" + n + " phi=" + phi);
        System.out.println("Public (e,n)=(" + e + "," + n + ") Private (d,n)=(" + d + "," + n + ")");
        System.out.println("Msg: " + msg);
        System.out.println("Encrypted: " + enc);
        System.out.println("Decrypted: " + dec);
    }
}
