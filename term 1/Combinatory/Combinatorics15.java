package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics15 {

    static long combanation(int n, int k) {
        if (k == 0) {
            return 1;
        } else {
            return combanation(n, k - 1) * (n - k + 1) / k;
        }
    }

    static int[] getCombination(int n, int k, long m) {
        int res[] = new int[k];
        int nt = 1;
        int cnt = 0;
        while (k > 0) {
            long cnk = combanation(n - 1, k - 1);
            if (m >= cnk) {
                m = m - cnk;
            } else {
                res[cnt] = nt;
                cnt++;
                k--;
            }
            n--;
            nt++;
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("num2choose.in"));
        FileWriter fileWriter = new FileWriter(new File("num2choose.out"));
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        long m = scanner.nextLong();
        int[] choose = getCombination(n, k, m);
        for (int i = 0; i < k; i++) {
            fileWriter.write(choose[i] + " ");
        }
        fileWriter.flush();
    }
}
