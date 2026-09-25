import java.security.MessageDigest;

public class SHA1Demo {
    public static void main(String[] args) throws Exception {
        String text = "Hello world";
        MessageDigest md = MessageDigest.getInstance("SHA-1");
        byte[] digest = md.digest(text.getBytes());
        StringBuilder hex = new StringBuilder();
        for (byte b : digest) hex.append(String.format("%02x", b));
        System.out.println("Text: " + text);
        System.out.println("SHA-1: " + hex);
        System.out.println("Length: " + hex.length() + " hex chars (160 bits)");
    }
}
