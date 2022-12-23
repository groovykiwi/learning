package lab7;

import java.util.Scanner;
import java.util.Random;

public class task2 {
    public static void main(String[] args) {
        Random r = new Random(System.currentTimeMillis());
        Scanner sc = new Scanner(System.in);

        int arr[] = new int[100];
        for (int i = 0; i < 100; i++)
            arr[i] = r.nextInt(100);

        System.out.printf("Enter an index number: ");
        int index = sc.nextInt();
        sc.close();

        try {
            System.out.println(arr[index]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Index out of bounds, try again.\n");
            main(null);
        }

    }
}
