package lab4;

import java.util.*;

public class pretask4 {

    public static double distance(double x1, double y1, double x2, double y2) {
        double d = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
        return d;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.printf("\nEnter the number of cities: ");
        int cities = sc.nextInt();
        double xcoords[] = new double[cities];
        double ycoords[] = new double[cities];

        System.out.printf("\nEnter the coordinates of the cities:\n");
        for (int i = 0; i < cities; i++) {
            xcoords[i] = sc.nextDouble();
            ycoords[i] = sc.nextDouble();
        }
        sc.close();

        // System.out.println(Arrays.toString(xcoords));
        // System.out.println(Arrays.toString(ycoords));

        double lowest = -1;
        double totald = 0;
        int index = 0;

        for (int i = 0; i < cities; i++) {
            for (int j = 0; j < cities; j++) {
                totald += distance(xcoords[i], ycoords[i], xcoords[j], ycoords[j]);
            }
            if (totald < lowest || lowest == -1) {
                lowest = totald;
                index = i;
            }
        }

        System.out.printf("The central city is at (%.1f, %.1f)\n", xcoords[index], ycoords[index]);
        System.out.printf("The total distance to all other cities is %.2f", lowest);
    }
}

// TEST
// 5 cities
// 2.5 5 5.1 3 1 9 5.4 54 5.5 2.1