package lab7;

import java.io.*;
import java.util.Scanner;

public class inlab {
    public static void main(String[] args) {
        String currentDir = System.getProperty("user.dir") + "/java/lab7";
        File f = new File(currentDir, "words.txt");

        int lines = 0;
        int chars = 0;
        int words = 0;
        String x;
        try {
            Scanner sc = new Scanner(f);
            while (sc.hasNextLine()) {
                sc.nextLine();
                lines++;
            }

            // Reset Scanner
            sc.close();
            sc = new Scanner(f);

            while (sc.hasNext()) {
                x = sc.next();
                System.out.println(x);
                words++;
                for (int i = 0; i <= x.length(); i++)
                    chars++;
            }
            sc.close();

        } catch (IOException e) {
            System.out.println("Error when reading the file.");
        }
        System.out.println("\nThis text file has " + lines + " lines");
        System.out.println("This text file has " + words + " words");
        System.out.println("This text file has " + chars + " characters");

    }
}
