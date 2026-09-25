import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class AESDemo {
    public static void main(String[] args) throws Exception {
        // Rijndael = AES (Rijndael won AES competition)
        String plain = "Hello world";
        KeyGenerator kg = KeyGenerator.getInstance("AES");
        kg.init(128);
        SecretKey key = kg.generateKey();

        Cipher c = Cipher.getInstance("AES/ECB/PKCS5Padding");
        c.init(Cipher.ENCRYPT_MODE, key);
        String enc = Base64.getEncoder().encodeToString(c.doFinal(plain.getBytes()));

        c.init(Cipher.DECRYPT_MODE, key);
        String dec = new String(c.doFinal(Base64.getDecoder().decode(enc)));

        System.out.println("Plain : " + plain);
        System.out.println("Rijndael/AES Encrypted (Base64): " + enc);
        System.out.println("Rijndael/AES Decrypted: " + dec);
    }
}
