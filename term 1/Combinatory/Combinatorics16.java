package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics16 {

    static long combination(int n, int k) {
        if (k == 0) {
            return 1;
        } else {
            return combination(n, k - 1) * (n - k + 1) / k;
        }
    }

    static long getNumber(int a[], int n, int k) {
        long num = 0;
        for (int i = 1; i <= k; i++) {
            int prev = a[i - 1] + 1;
            int cur = a[i] - 1;
            for (int j = prev; j <= cur; j++) {
                num = num + combination(n - j, k - i);
            }
        }
        return num;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("choose2num.in"));
        FileWriter fileWriter = new FileWriter(new File("choose2num.out"));
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] choose = new int[k + 1];
        choose[0] = 0;
        for (int i = 1; i <= k; i++) {
            choose[i] = scanner.nextInt();
        }
        fileWriter.write(getNumber(choose, n, k) + "");
        fileWriter.flush();
    }
}
