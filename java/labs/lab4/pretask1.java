package lab4;

import java.util.*;

public class pretask1 {
    public static Integer[] eliminateDuplicates(int[] list) {
        boolean duplicate = false;
        ArrayList<Integer> nlist = new ArrayList<Integer>();

        for (int i = 0; i < list.length; i++) {
            duplicate = false;

            for (int j = 0; j < nlist.size(); j++) {
                if (nlist.get(j) == list[i])
                    duplicate = true;
            }
            if (!duplicate)
                nlist.add(list[i]);
        }

        System.out.printf("Sorted array: %s\n", nlist.toString());
        Integer[] out = nlist.toArray(new Integer[0]);
        return out;

    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int numbers[] = new int[10];
        System.out.printf("\nEnter 10 numbers: ");
        for (int i = 0; i < 10; i++) {
            numbers[i] = in.nextInt();
        }
        in.close();

        eliminateDuplicates(numbers);
    }
}
