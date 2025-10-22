import java.util.Scanner;

public class AdaLovelace {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter text: ");
        String text = input.nextLine();

        int count = 0;
        String lowerText = text.toLowerCase(); // convert to lowercase

        for (int i = 0; i <= lowerText.length() - 3; i++) {
            if (lowerText.substring(i, i + 3).equals("ada")) {
                count++;
            }
        }

        System.out.println("Ada: " + count);
    }
}

