public class HillCipher {
    // 2x2 key: [[3,3],[2,5]], inverse mod 26 = [[15,17],[20,9]]
    static int[][] key = {{3,3},{2,5}};
    static int[][] invKey = {{15,17},{20,9}};

    static String encrypt(String text) {
        text = text.toUpperCase().replaceAll("[^A-Z]", "");
        if (text.length() % 2 == 1) text += "X"; // padding
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < text.length(); i += 2) {
            int p0 = text.charAt(i) - 'A';
            int p1 = text.charAt(i+1) - 'A';
            int c0 = (key[0][0]*p0 + key[0][1]*p1) % 26;
            int c1 = (key[1][0]*p0 + key[1][1]*p1) % 26;
            res.append((char)(c0+'A')).append((char)(c1+'A'));
        }
        return res.toString();
    }
    static String decrypt(String text) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < text.length(); i += 2) {
            int c0 = text.charAt(i) - 'A';
            int c1 = text.charAt(i+1) - 'A';
            int p0 = (invKey[0][0]*c0 + invKey[0][1]*c1) % 26;
            int p1 = (invKey[1][0]*c0 + invKey[1][1]*c1) % 26;
            res.append((char)(p0+'A')).append((char)(p1+'A'));
        }
        return res.toString();
    }
    public static void main(String[] args) {
        String plain = "HELLO";
        String enc = encrypt(plain);
        System.out.println("Plain : " + plain);
        System.out.println("Key matrix: [3 3; 2 5]");
        System.out.println("Encrypted: " + enc);
        System.out.println("Decrypted: " + decrypt(enc));
    }
}
