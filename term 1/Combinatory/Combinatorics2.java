package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics2 {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("gray.in"));
        FileWriter fileWriter = new FileWriter(new File("gray.out"));
        int n = scanner.nextInt();
        int m = 1 << n;
        int s[] = new int[m];
        s[0] = 0;
        s[1] = 1;
        for (int i = 2; i < m; i++) {
            s[i] = i ^ (i / 2);
        }
        for (int i = 0; i < m; i++) {
            String string = "";
            int cur = s[i];
            for (int j = 0; j < n; j++) {
                string = cur % 2 + string;
                cur = cur / 2;
            }
            fileWriter.write(string + "\n");
        }
        fileWriter.flush();
    }
}
