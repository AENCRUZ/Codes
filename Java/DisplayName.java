import java.util.Scanner;

class DisplayName {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String name = input.nextLine();
        
        System.out.println("Hello "+ name +", you are so amazing!");
        input.close();
    }
}