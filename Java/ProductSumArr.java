import java.util.*;

class ProductSumArr{
    public static void main(String[]args){
        int[] numbers = {2,3,4,5,6,7,8,9};
        
        int SumEven = 0;
        int ProductOdd = 1;
        
        for(int n : numbers){
            if(n%2==0){
                SumEven += n;
            }
            else{
                ProductOdd *= n;
            }
        }
        
        System.out.println("Sum of Even numbers: " + SumEven);
        System.out.println("Product of Odd numbers: " + ProductOdd);
    }
}