import java.util.Scanner;

public class lab3task1 {

	public static int sumDigits(long n) {
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n = n / 10;
		}
		return sum;
	}

	public static void main(String[] args) {
		// INPUT
		System.out.println("Enter number: ");
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();

		System.out.println("Sum of digits: " + sumDigits(a));
	}
}