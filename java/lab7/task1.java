package lab7;

import java.util.*;

public class task1 {
    static int a, b;

    public static void main(String[] args) {

        getInput();
        System.out.printf("%d + %d = %d\n", a, b, a + b);
    }

    public static void getInput() {
        System.out.print("Enter the 2 number to sum: ");
        Scanner sc = new Scanner(System.in);
        try {
            a = sc.nextInt();
            b = sc.nextInt();
            sc.close();
        } catch (InputMismatchException e) {
            System.out.println("Invalid input try again.\n");
            getInput();
        }
    }
}
