package lab3;

import java.util.Scanner;

public class task1 {

    public static int productDigits(long n) {
        int product = 1;
        while (n > 0) {
            product *= n % 10;
            n = n / 10;
        }
        return product;
    }

    public static void main(String[] args) {
        // INPUT
        System.out.println("Enter number: ");
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        in.close();

        System.out.println("Products of digits: " + productDigits(a));
    }
}
