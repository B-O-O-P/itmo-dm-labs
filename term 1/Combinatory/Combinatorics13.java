package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics13 {

    static long fact(int n) {
        long f = 1;
        if (n == 0) {
            return 1;
        } else {
            for (int i = 1; i <= n; i++) {
                f = f * i;
            }
            return f;
        }
    }

    static int[] getNumber(long k, int n) {
        int old[] = new int[n + 1];
        int[] perm = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            long nf = fact(n - i);
            int cur = 0;
            long pref = k / nf;
            k = k % nf;
            for (int j = 1; j <= n; j++) {
                if (old[j] == 0) {
                    cur++;
                    if (cur == pref + 1) {
                        perm[i] = j;
                        old[j] = 1;
                    }
                }
            }
        }
        return perm;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("num2perm.in"));
        FileWriter fileWriter = new FileWriter(new File("num2perm.out"));
        int n = scanner.nextInt();
        long k = scanner.nextLong();
        int[] res = getNumber(k, n);
        for (int i = 1; i <= n; i++)
            fileWriter.write(res[i] + " ");
        fileWriter.flush();
    }
}
