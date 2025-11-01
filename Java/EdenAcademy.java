import java.util.*;

public class EdenAcademy {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of grades: ");
        int n = sc.nextInt();

        int[] grades = new int[n];
        System.out.print("Enter grades: ");
        for (int i = 0; i < n; i++) {
            grades[i] = sc.nextInt();
        }

        List<Integer> passed = new ArrayList<>();
        List<Integer> failed = new ArrayList<>();

        for (int grade : grades) {
            int rounded = grade;

            if (grade >= 78) {
                int nextMultiple = ((grade / 5) + 1) * 5;
                if (nextMultiple - grade < 3) {
                    rounded = nextMultiple;
                }
            }

            if (rounded >= 80) {
                passed.add(rounded);
            } else {
                failed.add(grade);
            }
        }

        if (!passed.isEmpty()) {
            System.out.print("\nPassed: ");
            for (int i = 0; i < passed.size(); i++) {
                System.out.print(passed.get(i));
                if (i < passed.size() - 1) System.out.print(" ");
            }
            System.out.println();
        } else {
            System.out.println("\nPassed:");
        }

        System.out.print("Failed:");
        if (!failed.isEmpty()) {
            System.out.print(" ");
            for (int i = 0; i < failed.size(); i++) {
                System.out.print(failed.get(i));
                if (i < failed.size() - 1) System.out.print(" ");
            }
        }
        System.out.println();

        int stellaStars = passed.size() / 3;
        int tonitrusBolts = failed.size();

        System.out.println("\nStella Stars: " + stellaStars);
        System.out.println("Tonitrus Bolts: " + tonitrusBolts);
    }
}
