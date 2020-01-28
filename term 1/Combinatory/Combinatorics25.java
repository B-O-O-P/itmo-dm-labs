package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics25 {

    static int[] nextCombination(int[] a, int n, int k) {
        int b[] = new int[n];
        for (int i = 0; i < k; i++) {
            b[i] = a[i];
        }
        if (n != k) {
            b[k] = n + 1;
            int ind = k - 1;
            while (ind >= 0 && b[ind + 1] - b[ind] < 2) {
                ind--;
            }
            if (ind >= 0) {
                b[ind]++;
                for (int j = ind + 1; j < k; j++) {
                    b[j] = b[j - 1] + 1;
                }
                for (int i = 0; i < k; i++) {
                    a[i] = b[i];
                }
                return a;
            } else return null;
        } else return null;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("nextchoose.in"));
        FileWriter fileWriter = new FileWriter(new File("nextchoose.out"));
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int a[] = new int[k];
        for (int i = 0; i < k; i++) a[i] = scanner.nextInt();
        int b[] = nextCombination(a, n, k);
        if (b != null) {
            for (int i = 0; i < k; i++) {
                fileWriter.write(b[i] + " ");
            }
        } else {
            fileWriter.write("-1");
        }
        fileWriter.flush();
    }
}
