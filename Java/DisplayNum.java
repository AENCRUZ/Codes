import java.util.Scanner;

class DisplayNum{
    public static void main(String[]args){
        Scanner input = new Scanner (System.in);
        System.out.print("Enter number: ");
        int num = input.nextInt();
        
        System.out.println("Your number is "+ num + ".");
        input.close();
    }
}