public class task {
    public static void main(String[] args) {
        Rectangle b = new Rectangle(5, 10);
        Circle c = new Circle(5);

        b.print();
        c.print();

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

    public void setLocation(double x, double y) {
        this.x = x;
        this.y = y;
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
        location.setLocation(x, y);
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void print() {
        System.out
                .println("Shape: color = " + color + ", location = (" + location.getX() + ", " + location.getY() + ")");
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

    @Override
    public void setLocation(double x, double y) {
        super.setLocation(x, y);
    }

    @Override
    public String getColor() {
        return super.getColor();
    }

    @Override
    public void setColor(String color) {
        super.setColor(color);
    }

    public double getArea() {
        return width * height;
    }

    @Override
    public void print() {
        System.out.println("Rectangle: width = " + width + ", height = " + height + ", color = " + getColor()
                + ", location = (" + getX() + ", " + getY() + ")");
    }
}

class Circle extends Shape {
    private double radius;
    private Point center;

    public Circle(double radius) {
        super("black");
        this.radius = radius;
        this.center = new Point();
    }

    public void setCenter(double x, double y) {
        center.setLocation(x, y);
    }

    public Point getCenter() {
        return center;
    }

    @Override
    public void setColor(String color) {
        super.setColor(color);
    }

    @Override
    public String getColor() {
        return super.getColor();
    }

    @Override
    public void print() {
        System.out.println("Circle: radius = " + radius + ", center = (" + center.getX() + ", " + center.getY()
                + "), color = " + getColor());
    }
}