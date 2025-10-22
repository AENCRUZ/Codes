import java.util.Scanner;

class AptxVault {

    // Function to get user input
    public static int[] getPasscodes() {
        Scanner scanner = new Scanner(System.in);
        int[] passcodes = new int[3];

        for (int i = 0; i < 3; i++) {
            System.out.print("Enter passcode " + (i + 1) + ": ");
            passcodes[i] = scanner.nextInt();
        }

        return passcodes;
    }

    // Function to check if all passcodes are valid
    public static boolean isValidPasscodes(int[] passcodes) {
        for (int code : passcodes) {
            if (code < 450 || code > 3000) {
                return false;
            }
        }
        return true;
    }

    // Main logic
    public static void main(String[] args) {
        int[] passcodes = getPasscodes();

        int sum = 0;
        for (int code : passcodes) {
            sum += code;
        }

        if (isValidPasscodes(passcodes) && sum == 4869) {
            System.out.println("Vault unlocked with: " + passcodes[0] + ", " + passcodes[1] + ", " + passcodes[2]);
        } else {
            System.out.println("Vault remains locked.");
        }
    }
}
