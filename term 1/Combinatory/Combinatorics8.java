package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics8 {

    static int[] nextCombination(int[] a, int n, int k) {
        int b[] = new int[n];
        for (int i = 0; i < k; i++) {
            b[i] = a[i];
        }
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
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("choose.in"));
        FileWriter fileWriter = new FileWriter(new File("choose.out"));
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        int CHOICE[] = new int[k];
        for (int i = 0; i < k; i++) {
            CHOICE[i] = i + 1;
            fileWriter.write(CHOICE[i] + " ");
        }
        fileWriter.write("\n");

        if (n != k) {
            int cur[] = nextCombination(CHOICE, n, k);
            while (cur != null) {
                for (int j = 0; j < k; j++) {
                    fileWriter.write(cur[j] + " ");
                }
                cur = nextCombination(cur, n, k);
                fileWriter.write("\n");
            }
        }
        fileWriter.flush();
    }
}
