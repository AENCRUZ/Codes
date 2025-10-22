import java.util.Scanner;
public class NaniwaHarukas {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("WELCOME TO NANIWA HARUKAS!");
        System.out.print("\nEnter the first term (a1): ");
        int a1 = input.nextInt();

        System.out.print("Enter the common difference (d): ");
        int d = input.nextInt();

        System.out.print("Enter the number of terms (n): ");
        int n = input.nextInt();

        int[] sequence = new int[n];
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sequence[i] = a1 + (i * d);
            sum += sequence[i];
        }

        System.out.print("\nArithmetic Sequence: ");
        for (int i = 0; i < n; i++) {
            System.out.print(sequence[i]);
            if (i < n - 1) System.out.print(" ");
        }

        System.out.println("\nSum of sequence = " + sum);

        if (sum == 60) {
            System.out.println("Welcome to the Observation Deck.");
            System.out.println("\"It's a beautiful sunset, isn't it?\"");
        } else if (sum % 5 == 0 && sum % 3 == 0) {
            System.out.println("Welcome to the Souvenir Shop.");
        } else if (sum % 3 == 0) {
            System.out.println("Welcome to the Restaurant and Sky Garden.");
        } else {
            System.out.println("The elevator displays the sum: " + sum);
        }

        input.close();
    }
}
