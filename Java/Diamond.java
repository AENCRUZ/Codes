import java.util.*;

class Diamond {
    public static void main(String[] args) {
        int num = 5;
        
        for(int i = 1; i <= num; i += 2){
            for(int j = 0; j < (num-i)/2; j++){
                System.out.print(" ");
            }
            for(int k = 0; k < i; k++){
                System.out.print("*");
            }
            System.out.println();
        }
        
        for(int i = num-2; i >= i; i -= 2){
            for(int j = 0; j < (num-i)/2; j++){
                System.out.print(" ");
            }
            for(int k = 0; k < i; k++){
                System.out.print("*");
            }
            System.out.println();
        }
        
    }
}