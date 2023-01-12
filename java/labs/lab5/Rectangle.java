package lab5;

public class Rectangle {
    double width;
    double height;

    Rectangle() {
        this(1, 1);
    }

    Rectangle(double x, double y) {
        width = x;
        height = y;
    }

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return width * 2 + height * 2;
    }
}

class TestRectangle {
    public static void main(String[] args) {

        // create first object
        // and initialize with no arg constructor
        Rectangle r1 = new Rectangle(4, 40);

        // create first object
        // and initialize with no arg constructor
        Rectangle r2 = new Rectangle(3.5, 35.9);

        System.out.println("Width and Height of r1 = " + r1.width + ", " + r1.height);
        System.out.println("Area of r1 = " + r1.getArea());
        System.out.println("Perimeter of r1 = " + r1.getPerimeter());
        System.out.println("\nWidth and Height of r2 = " + r2.width + ", " + r2.height);
        System.out.println("Area of r2 = " + r2.getArea());
        System.out.println("Perimeter of r2 = " + r2.getPerimeter());
    }
}