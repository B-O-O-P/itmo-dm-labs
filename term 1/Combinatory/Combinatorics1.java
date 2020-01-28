package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics1 {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("allvectors.in"));
        FileWriter fileWriter = new FileWriter("allvectors.out");
        int n = scanner.nextInt();
        for (int i = 0; i < Math.pow(2, n); i++) {
            int cur = i;
            String s = "";
            for (int j = 0; j < n; j++) {
                s = cur % 2 + s;
                cur = cur / 2;
            }
            fileWriter.write(s + "\n");
        }
        fileWriter.flush();
    }
}
