package lab3;

import java.util.*;

public class lab3task3 {

    public static int sumSquare(int n) {
        int sum = 0;
        while (n > 0) {
            sum += Math.pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }

    public static boolean isHappy(int n) {
        int calc = sumSquare(n);
        while (calc != 4 && calc != 1) {
            calc = sumSquare(calc);
        }

        if (calc == 1)
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        // INPUT
        System.out.print("Enter number: ");
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();

        if (isHappy(a))
            System.out.println("The number is happy");
        else
            System.out.println("The number is sad");
    }
}