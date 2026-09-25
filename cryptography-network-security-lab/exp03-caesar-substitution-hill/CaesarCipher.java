public class CaesarCipher {
    static String encrypt(String text, int shift) {
        StringBuilder res = new StringBuilder();
        for (char ch : text.toCharArray()) {
            if (Character.isUpperCase(ch))
                res.append((char) ((ch - 'A' + shift) % 26 + 'A'));
            else if (Character.isLowerCase(ch))
                res.append((char) ((ch - 'a' + shift) % 26 + 'a'));
            else
                res.append(ch);
        }
        return res.toString();
    }
    static String decrypt(String text, int shift) {
        return encrypt(text, 26 - shift);
    }
    public static void main(String[] args) {
        String plain = "Hello world";
        int shift = 3;
        String enc = encrypt(plain, shift);
        String dec = decrypt(enc, shift);
        System.out.println("Plain : " + plain);
        System.out.println("Encrypted (shift 3): " + enc);
        System.out.println("Decrypted: " + dec);
    }
}
