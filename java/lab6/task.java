public class task {
    public static void main(String[] args) {
        Point a = new Point(4, 7);
        Shape b = new Shape("red");
        Rectangle c = new Rectangle(5, 10);
        Circle d = new Circle(5);

        a.print();
        b.print();
        c.print();
        d.print();

        System.out.println("");
        // Rectangle
        Point ruCorner = c.getCornerRightUpp();
        System.out.println("Right-upper corner: (" + ruCorner.getX() + ", " + ruCorner.getY() + ")");
        System.out.println("Area of rectangle: " + c.getArea());
        System.out.println("Color of rectangle: " + c.getColor());

        System.out.println("");
        // Circle
        Point center = d.getCenter();
        System.out.println("Color of circle: " + d.getColor());
        System.out.println("Center: (" + center.getX() + ", " + center.getY() + ")");
        d.setCenter(2, 5);
        System.out.println("Center: (" + center.getX() + ", " + center.getY() + ")");
    }
}

class Point {
    private double x;
    private double y;

    public Point() {
        this.x = 0.0;
        this.y = 0.0;
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void print() {
        System.out.printf("Point: (%.2f, %.2f)\n", x, y);
    }
}

class Shape {
    private String color;
    private Point location;

    public Shape(String color) {
        this.color = color;
        this.location = new Point();
    }

    public double getX() {
        return location.getX();
    }

    public double getY() {
        return location.getY();
    }

    public void setLocation(double x, double y) {
        location.setX(x);
        location.setY(y);
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void print() {
        System.out
                .printf("Shape: %s, (%.2f, %.2f)\n", color, getX(), getY());
    }
}

class Rectangle extends Shape {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        super("black");
        this.width = width;
        this.height = height;
    }

    public Point getCornerLeftLow() {
        return new Point(getX(), getY());
    }

    public Point getCornerLeftUpp() {
        return new Point(getX(), getY() + height);
    }

    public Point getCornerRightLow() {
        return new Point(getX() + width, getY());
    }

    public Point getCornerRightUpp() {
        return new Point(getX() + width, getY() + height);
    }

    public double getArea() {
        return width * height;
    }

    @Override
    public void print() {
        System.out.printf("Rectangle: width %.2f, height %.2f, center (%.2f, %.2f), color %s\n", width, height,
                getX(), getY(), getColor());
    }
}

class Circle extends Shape {
    private double radius;
    private Point center;

    public Circle(double radius) {
        super("yellow");
        this.radius = radius;
        this.center = new Point();
    }

    public void setCenter(double x, double y) {
        center.setX(x);
        center.setY(y);
    }

    public Point getCenter() {
        return center;
    }

    @Override
    public void print() {
        System.out.printf("Circle: radius %.2f, center (%.2f, %.2f), color %s\n", radius, getX(), getY(), getColor());
    }
}