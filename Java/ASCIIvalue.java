import java.util.Scanner;

class ASCIIvalue{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String character;
        
        while(true){
            System.out.print("Enter a character('#' to exit): ");
            character = input.nextLine();
            
            if(character.equals("A")){
                System.out.println("The ASCII value is 65");
            }
            else if(character.equals("a")){
                System.out.println("The ASCII value is 97");
            }
            else if(character.equals("0")){
                System.out.println("The ASCII value is 48");
            }
            else if(character.equals("space") || character.equals("Space")){
                System.out.println("The ASCII value is 32");
            }
            else if(character.equals("#")){
                System.out.println("Exiting the program...");
                break;
            }
        }
    input.close();
    }
}