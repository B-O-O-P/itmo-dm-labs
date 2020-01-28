package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics23 {

    static String nextVector(String s, int n) {
        StringBuilder string = new StringBuilder(s);
        while ((n >= 0) && s.charAt(n) != '0') {
            string.setCharAt(n, '0');
            n--;
        }
        if (n == -1) {
            return "-";
        }
        string.setCharAt(n, '1');
        return string.toString();
    }

    static String prevVector(String s, int n) {
        StringBuilder string = new StringBuilder(s);
        while ((n >= 0) && s.charAt(n) != '1') {
            string.setCharAt(n, '1');
            n--;
        }
        if (n == -1) {
            return "-";
        }
        string.setCharAt(n, '0');
        return string.toString();
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("nextvector.in"));
        FileWriter fileWriter = new FileWriter(new File("nextvector.out"));
        String s = scanner.nextLine();
        fileWriter.write(prevVector(s, s.length() - 1) + "\n" + nextVector(s, s.length() - 1));
        fileWriter.flush();
    }
}
