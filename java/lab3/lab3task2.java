package lab3;

import java.util.Scanner;

public class lab3task2 {

    public static int reverse(int n) {
        int rv = 0;
        while (n > 0) {
            rv *= 10;
            rv += n % 10;
            n /= 10;
        }
        return rv;
    }

    public static boolean isPalindrome(int n) {
        if (n == reverse(n))
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        // INPUT
        System.out.println("Enter number: ");
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();

        if (isPalindrome(a))
            System.out.println("The number is a palindrome");
        else
            System.out.println("The number is NOT a palindrome");
    }
}