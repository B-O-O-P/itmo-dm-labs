package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics3 {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("antigray.in"));
        FileWriter fileWriter = new FileWriter(new File("antigray.out"));
        int n = scanner.nextInt();
        int m = (int) Math.pow(3, n - 1);
        for (int i = 0; i < m; i++) {
            int sdvig = 0;
            for (int j = 0; j < 3; j++) {
                int cur = i;
                String string = "";
                for (int k = 0; k < n; k++) {
                    string = (cur % 3 + sdvig) % 3 + string;
                    cur = cur / 3;
                }
                sdvig++;
                fileWriter.write(string + "\n");
            }
        }
        fileWriter.flush();
    }
}
