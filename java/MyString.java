import java.util.*;

public class MyString {
    char[] value;

    public MyString(char[] chars) {
        value = Arrays.copyOf(chars, chars.length);
    };

    public char charAt(int index) {
        return value[index];
    };

    public int length() {
        return value.length;
    };

    // public MyString substring(int begin, int end) {
    // return MyString();
    // }

    public MyString toLowerCase() {
        char[] lower = new char[value.length];
        for (int i = 0; i < value.length; i++) {
            if (value[i] >= 65 && value[i] <= 90) {
                lower[i] = Character.toLowerCase(value[i]);
            } else {
                lower[i] = value[i];
            }
        }
        MyString result = new MyString(lower);
        return result;
    };

    public boolean equals(MyString s) {
        for (int i = 0; i < value.length; i++) {
            if (value[i] != s.value[i])
                return false;
        }
        return true;
    };

    public static MyString valueOf(int i) {
        char[] temp = Integer.toString(i).toCharArray();
        MyString result = new MyString(temp);
        return result;
    };

    public int compare(String s) {
        int limit = Math.min(this.length(), s.length());
        int i = 0;
        while (i < limit) {
            char c1 = value[i];
            char c2 = s.charAt(i);
            if (c1 != c2) {
                return c1 - c2;
            }
            i++;
        }
        return this.length() - s.length();
    };

    // public MyString substring(int begin) {

    // };

    public MyString toUpperCase() {
        char[] lower = new char[value.length];
        for (int i = 0; i < value.length; i++) {
            if (value[i] >= 97 && value[i] <= 122) {
                lower[i] = Character.toUpperCase(value[i]);
            } else {
                lower[i] = value[i];
            }
        }
        MyString result = new MyString(lower);
        return result;
    };

    public static void main(String[] args) {
        char[] word = { 'H', 'e', 'L', 'l', 'o' };
        MyString a = new MyString(word);

        MyString b = new MyString(word);

        char[] word1 = { 'W', 'o', 'r', 'l', 'd' };
        MyString c = new MyString(word1);

        System.out.println(Arrays.toString(a.value));
        System.out.println(a.charAt(2));
        System.out.println(a.length());
        System.out.println(Arrays.toString(a.toLowerCase().value));

        // Equals
        System.out.println(a.equals(b));
        System.out.println(a.equals(c));

        // Compare
        String d = "HeLlo";
        String e = "hello";
        System.out.println(a.compare(d));
        System.out.println(a.compare(e));
    }
}
