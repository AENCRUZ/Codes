import java.util.Scanner;

public class CaesarCipher {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter cipher: ");
        String input = scanner.nextLine();
        scanner.close();

        String[] parts = input.split(" ");
        StringBuilder result = new StringBuilder();

        for (String part : parts) {
            int shift = Character.getNumericValue(part.charAt(0));
            String encrypted = part.substring(1);
            result.append(decrypt(encrypted, shift)).append(" ");
        }

        System.out.println(result.toString().trim());
    }

    private static String decrypt(String text, int shift) {
        StringBuilder decrypted = new StringBuilder();

        for (char ch : text.toCharArray()) {
            if (Character.isLetter(ch)) {
                char base = Character.isUpperCase(ch) ? 'A' : 'a';
                int offset = (ch - base - shift + 26) % 26; // wrap-around logic
                decrypted.append((char) (base + offset));
            } else {
                decrypted.append(ch); // keep non-letters unchanged
            }
        }

        return decrypted.toString();
    }
}

