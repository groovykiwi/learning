package lab3;

import java.util.Scanner;

public class task2 {
    public static int reverse(int n) {
        int rv = 0;
        while (n > 0) {
            rv *= 10;
            rv += n % 10;
            n /= 10;
        }
        return rv;
    }

    public static void main(String[] args) {
        // INPUT
        System.out.println("Enter number: ");
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        in.close();

        System.out.println("Reverse is: " + reverse(a));
    }

}
