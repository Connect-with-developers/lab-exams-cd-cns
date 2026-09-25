import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class RC4BlowfishDemo {
    // Manual RC4 (KSA + PRGA) — small, exam-writable
    static byte[] rc4(byte[] data, byte[] key) {
        int[] S = new int[256];
        for (int i = 0; i < 256; i++) S[i] = i;
        int j = 0;
        for (int i = 0; i < 256; i++) { // KSA
            j = (j + S[i] + (key[i % key.length] & 0xFF)) % 256;
            int t = S[i]; S[i] = S[j]; S[j] = t;
        }
        byte[] out = new byte[data.length];
        int i = 0; j = 0;
        for (int k = 0; k < data.length; k++) { // PRGA
            i = (i + 1) % 256;
            j = (j + S[i]) % 256;
            int t = S[i]; S[i] = S[j]; S[j] = t;
            out[k] = (byte)(data[k] ^ S[(S[i] + S[j]) % 256]);
        }
        return out;
    }

    public static void main(String[] args) throws Exception {
        String plain = "Hello world";

        // 1. RC4 manual
        byte[] rc4enc = rc4(plain.getBytes(), "mykey".getBytes());
        byte[] rc4dec = rc4(rc4enc, "mykey".getBytes());
        System.out.println("Plain : " + plain);
        System.out.println("RC4 Encrypted (Base64): " + Base64.getEncoder().encodeToString(rc4enc));
        System.out.println("RC4 Decrypted: " + new String(rc4dec));

        // 2. Blowfish via Java crypto + own key (KeyGenerator = "Java key tool" for exam)
        KeyGenerator kg = KeyGenerator.getInstance("Blowfish");
        SecretKey bkey = kg.generateKey(); // create your own key
        Cipher c = Cipher.getInstance("Blowfish");
        c.init(Cipher.ENCRYPT_MODE, bkey);
        String benc = Base64.getEncoder().encodeToString(c.doFinal(plain.getBytes()));
        c.init(Cipher.DECRYPT_MODE, bkey);
        String bdec = new String(c.doFinal(Base64.getDecoder().decode(benc)));
        System.out.println("Blowfish Encrypted (Base64): " + benc);
        System.out.println("Blowfish Decrypted: " + bdec);
        System.out.println("Key algo: " + bkey.getAlgorithm() + ", format: " + bkey.getFormat());
    }
}
