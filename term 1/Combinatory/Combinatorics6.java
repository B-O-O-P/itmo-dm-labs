package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Scanner;

public class Combinatorics6 {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("vectors2.in"));
        FileWriter fileWriter = new FileWriter(new File("vectors2.out"));
        int n = scanner.nextInt();
        ArrayDeque<String> a = new ArrayDeque<>();
        int m = 1 << n;
        for (int i = 0; i < m; i++) {
            String string = "";
            int pref = 0;
            int cur = i;
            boolean hasone = false;
            for (int j = 0; j < n; j++) {
                if (cur % 2 == 1 && pref == 1) {
                    hasone = true;
                    break;
                }
                string = cur % 2 + string;
                if (cur % 2 == 1) {
                    pref = 1;
                } else {
                    pref = 0;
                }
                cur = cur / 2;
            }
            if (!hasone) {
                a.addLast(string);
            }
        }
        int cnt = a.size();
        fileWriter.write(cnt + "\n");
        while (!a.isEmpty()) {
            fileWriter.write(a.pollFirst() + "\n");
        }
        fileWriter.flush();
    }
}
