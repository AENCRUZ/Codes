import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Point p = new Point();

        System.out.print("Enter x: ");
        p.setX(input.nextInt());

        System.out.print("Enter y: ");
        p.setY(input.nextInt());

        p.printCoordinates();
        System.out.printf("%.2f\n", p.calculateDistance());
    }
}
