import java.util.Scanner;

class SuperDigit{
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter an integer (up to 18 digits): ");
        
        String num = input.nextLine();
        long n = Long.parseLong(num);
        while (n>0){
            long sum = 0;
            while (n>0){
                sum += n%10;
            n /= 10;
            }
            n = sum;
            
            if (n<10){
                break;
            }
        }
        System.out.println("Super Digit of " + num + ": " + n);
    }
}