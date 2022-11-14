package lab4;

import java.util.Scanner;

public class pretask3 {
    public static int[] locateLargest(double[][] a) {
        double largest = 0;
        int coords[] = new int[2];

        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                if (a[i][j] > largest) {
                    largest = a[i][j];
                    coords[0] = i;
                    coords[1] = j;
                }
            }
        }
        return coords;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.printf("\nEnter the number of rows and columns of the array: ");
        double array[][] = new double[sc.nextInt()][sc.nextInt()];

        System.out.printf("\nEnter the array: \n");
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[0].length; j++) {
                array[i][j] = sc.nextDouble();
            }
        }
        sc.close();

        int[] ans = locateLargest(array);
        System.out.printf("The location of the largest element is at (%d, %d)", ans[0], ans[1]);

    }
}

// TEST
// 3 4
// 23.5 35 2 10
// 4.5 3 45 3.5
// 35 44 5.5 9.6
