import java.util.Scanner;

class SimpleAdd{
    public static void main(String[]args){
        
        Scanner num1 = new Scanner(System.in);
        System.out.print("Enter number 1: ");
        int int1 = num1.nextInt();
        
        Scanner num2 = new Scanner(System.in);
        System.out.print("Enter number 2: ");
        int int2 = num2.nextInt();
        
        System.out.print(int1 + " + " + int2 + " = ");
        System.out.print(int1 + int2);
        num1.close();
        num2.close();
    }
}