package lab4;

import java.util.*;

public class lab4task2 {

    public static int[] merge(int[] list1, int[] list2) {
        int merged[] = new int[(list1.length + list2.length - 1)];

        for (int i = 0; i < list1.length; i++)
            merged[i] = list1[i];

        for (int j = list1.length; j < merged.length; j++) {
            merged[j] = list2[j - list1.length];
        }
        return merged;
    }

    // Insertion sort
    public static int[] sort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return arr;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.printf("\nEnter list1: ");
        String line = in.nextLine();
        String[] tokens = line.split(" ");
        int[] list1 = new int[tokens.length - 1];
        for (int i = 1; i < tokens.length; i++)
            list1[i - 1] = Integer.parseInt(tokens[i]);

        System.out.printf("\nEnter list2: ");
        line = in.nextLine();
        tokens = line.split(" ");
        int[] list2 = new int[tokens.length];
        for (int i = 1; i < tokens.length; i++)
            list2[i - 1] = Integer.parseInt(tokens[i]);

        in.close();
        // System.out.println(Arrays.toString(sort(list1)));
        System.out.printf("The merged list is %s\n",
                Arrays.toString(sort(merge(list1, list2))));

    }
}
