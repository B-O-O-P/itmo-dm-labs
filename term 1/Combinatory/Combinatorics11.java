package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics11 {

    static String Subsets(int f, String s, int n) {
        if (f <= n) {
            String next = Subsets(f + 1, s, n);
            s += f + " ";
            if (f + 1 <= n) {
                s += "\n" + Subsets(f + 1, s, n);
            }
            s += "\n" + next;
            return s;
        } else return "";
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("subsets.in"));
        FileWriter fileWriter = new FileWriter(new File("subsets.out"));
        int n = scanner.nextInt();
        //int n=3;
        String res = Subsets(1, "", n);
        res = res.replaceAll("\n\n", "\n");
        fileWriter.write("\n" + res);
        fileWriter.flush();
    }
}
