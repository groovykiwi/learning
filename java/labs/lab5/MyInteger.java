package lab5;

public class MyInteger {
    int value;

    MyInteger(int value) {
        this.value = value;
    }

    int getValue() {
        return value;
    }

    static boolean isEven(int x) {
        if (x % 2 == 0)
            return true;
        else
            return false;
    }

    static boolean isOdd(int x) {
        if (x % 2 != 0)
            return true;
        else
            return false;
    }

    static boolean isPrime(int x) {
        for (int i = 2; i < x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    boolean isEven() {
        return isEven(value);
    }

    boolean isOdd() {
        return isOdd(value);
    }

    boolean isPrime() {
        return isPrime(value);
    }

    boolean isEven(MyInteger x) {
        return isEven(x.value);
    }

    boolean isOdd(MyInteger x) {
        return isOdd(x.value);
    }

    boolean isPrime(MyInteger x) {
        return isPrime(x.value);
    }

    boolean equals(int x) {
        if (value == x)
            return true;
        else
            return false;
    }

    boolean equals(MyInteger x) {
        if (value == x.value)
            return true;
        else
            return false;
    }

    static int parseInt(char[] num) {
        int x = 0, increment = 1;

        for (int i = num.length - 1; i >= 0; i--) {
            x += num[i] * increment;
            increment *= 10;
        }
        return x;
    }

    static int parseInt(String num) {
        int x = 0, increment = 1;

        for (int i = num.length() - 1; i >= 0; i--) {
            x += Character.getNumericValue(num.charAt(i)) * increment;
            increment *= 10;
        }
        return x;
    }

    public static void main(String[] args) {
        MyInteger a = new MyInteger(12);
        MyInteger b = new MyInteger(17);

        System.out.println("A = " + a.getValue());
        System.out.println("B = " + b.getValue());
        System.out.println();

        // No Args methods
        System.out.println(a.isOdd());
        System.out.println(b.isOdd());
        System.out.println(a.isEven());
        System.out.println(b.isEven());
        System.out.println(a.isPrime());
        System.out.println(b.isPrime());
        System.out.println();
        // Static Methods
        System.out.println(MyInteger.isOdd(5));
        System.out.println(MyInteger.isEven(8));
        System.out.println(MyInteger.isPrime(4));
        System.out.println();
        // Methods with MyInteger Input
        System.out.println(b.isEven(a));
        System.out.println(a.isOdd(b));
        System.out.println(a.isPrime(b));

        // Parse Int from Char array
        System.out.println();
        System.out.println(MyInteger.parseInt(new char[] { 1, 2, 3 }));

        String str = "321";
        System.out.println(MyInteger.parseInt(str));
    }
}
