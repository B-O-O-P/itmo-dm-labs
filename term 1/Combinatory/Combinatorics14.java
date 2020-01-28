package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics14 {

    static long fact(int n) {
        if (n == 0) return 1;
        else {
            long f = 1;
            for (int i = 1; i <= n; i++) {
                f = f * i;
            }
            return f;
        }
    }

    static long getNumber(int a[], int n) {
        int old[] = new int[n + 1];
        long num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < a[i]; j++) {
                if (old[j] == 0) {
                    num = num + fact(n - i - 1);
                }
            }
            old[a[i]] = 1;
        }
        return num;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("perm2num.in"));
        FileWriter fileWriter = new FileWriter(new File("perm2num.out"));
        int n = scanner.nextInt();
        int perm[] = new int[n];
        for (int i = 0; i < n; i++) {
            perm[i] = scanner.nextInt();
        }
        fileWriter.write(getNumber(perm, n) + "");
        fileWriter.flush();
    }
}
