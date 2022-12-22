package lab7;

import java.util.*;

public class task1 {
    static int a, b;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the 2 number to sum: ");

        try {
            a = sc.nextInt();
            b = sc.nextInt();
            sc.close();
        } catch (InputMismatchException e) {
            System.out.println("Invalid input try again.\n");
            main(null);
        }
        System.out.printf("%d + %d = %d", a, b, a + b);
    }

}
