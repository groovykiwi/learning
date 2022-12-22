package lab7;

import java.io.*;
import java.util.*;

public class task3 {
    public static void main(String[] args) {
        String currentDir = System.getProperty("user.dir") + "/java/lab7";
        File f = new File(currentDir, "Exercise.txt");

        // WRITE
        Random rand = new Random(System.currentTimeMillis());
        try {

            FileWriter w = new FileWriter(f);

            for (int i = 0; i < 100; i++) {
                w.write(rand.nextInt(100) + " ");
            }
            w.close();
        } catch (IOException e) {
            System.out.println("An error occurred when writing to the file.");
        }

        // READ
        int arr[] = new int[100];
        try {
            Scanner sc = new Scanner(f);
            for (int i = 0; i < 100; i++) {
                arr[i] = sc.nextInt();
            }
            sc.close();
            sort(arr);
            System.out.println("\n" + Arrays.toString(arr));

        } catch (IOException e) {
            System.out.println("An error occurred when reading the file.");
        }
    }

    // Insertion Sort
    static void sort(int arr[]) {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
}
