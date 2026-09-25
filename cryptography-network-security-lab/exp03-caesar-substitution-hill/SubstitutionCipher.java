public class SubstitutionCipher {
    // Simple monoalphabetic: plain alphabet -> QWERTY... mapping
    static String plainAlpha = "abcdefghijklmnopqrstuvwxyz";
    static String cipherAlpha = "qwertyuiopasdfghjklzxcvbnm";

    static String encrypt(String text) {
        StringBuilder res = new StringBuilder();
        for (char ch : text.toCharArray()) {
            boolean upper = Character.isUpperCase(ch);
            char low = Character.toLowerCase(ch);
            int idx = plainAlpha.indexOf(low);
            if (idx != -1) {
                char ec = cipherAlpha.charAt(idx);
                res.append(upper ? Character.toUpperCase(ec) : ec);
            } else res.append(ch);
        }
        return res.toString();
    }
    static String decrypt(String text) {
        StringBuilder res = new StringBuilder();
        for (char ch : text.toCharArray()) {
            boolean upper = Character.isUpperCase(ch);
            char low = Character.toLowerCase(ch);
            int idx = cipherAlpha.indexOf(low);
            if (idx != -1) {
                char dc = plainAlpha.charAt(idx);
                res.append(upper ? Character.toUpperCase(dc) : dc);
            } else res.append(ch);
        }
        return res.toString();
    }
    public static void main(String[] args) {
        String plain = "Hello world";
        String enc = encrypt(plain);
        System.out.println("Plain : " + plain);
        System.out.println("Key   : " + cipherAlpha);
        System.out.println("Encrypted: " + enc);
        System.out.println("Decrypted: " + decrypt(enc));
    }
}
