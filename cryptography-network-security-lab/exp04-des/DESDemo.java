import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class DESDemo {
    public static void main(String[] args) throws Exception {
        String plain = "Hello world";
        KeyGenerator kg = KeyGenerator.getInstance("DES");
        SecretKey key = kg.generateKey();

        Cipher c = Cipher.getInstance("DES/ECB/PKCS5Padding");
        c.init(Cipher.ENCRYPT_MODE, key);
        byte[] enc = c.doFinal(plain.getBytes());
        String enc64 = Base64.getEncoder().encodeToString(enc);

        c.init(Cipher.DECRYPT_MODE, key);
        String dec = new String(c.doFinal(Base64.getDecoder().decode(enc64)));

        System.out.println("Plain : " + plain);
        System.out.println("DES Encrypted (Base64): " + enc64);
        System.out.println("DES Decrypted: " + dec);
    }
}
