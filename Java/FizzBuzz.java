import java.util.Scanner;

class FizzBuzz{
    public static void main(String args[]){
        System.out.print("Enter an upper bound: ");
        Scanner input = new Scanner(System.in);
        
        int upperbound = input.nextInt();
        
        for(int i = 1; i <= upperbound; i++){
            if (i % 3 == 0 && i % 5 == 0){
                System.out.println("FizzBuzz");
            }
            else if (i % 5 == 0){
                System.out.println("Buzz");
            }
            else if (i % 3 == 0){
                System.out.println("Fizz");
            }
            else{
                System.out.println(i);
            }
        }
        input.close();
    }
}