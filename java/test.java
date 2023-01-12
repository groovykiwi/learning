import java.util.ArrayList;

public class test {

    public static void main(String[] args) {

        Foo[] x = { new Foo(), new Bar() };

        x[0].f();

        x[1].g();

        ((Bar) x[1]).u();

        ((Foo) x[1]).u();

    }

}

class Foo {

    public void f() {

        System.out.print("1");

    }

    public void g() {

        System.out.print("2");

    }

    public void u() {

        System.out.print("9");

    }

}

class Bar extends Foo {

    public void f() {

        System.out.print("3");

    }

    public void g() {

        System.out.print("4");

    }

    public void u() {

        System.out.print("5");

    }

}