package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics24 {

    static void reverse(int a[], int i, int j) {
        while (i != j && i < j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    static int[] nextPermutation(int[] a, int n) {
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                int min = i + 1;
                for (int j = i + 1; j < n; j++) {
                    if ((a[j] < a[min]) && (a[j] > a[i])) {
                        min = j;
                    }
                }
                int tmp = a[min];
                a[min] = a[i];
                a[i] = tmp;
                reverse(a, i + 1, n - 1);
                return a;
            }
        }
        for (int i = 0; i < n; i++) {
            a[i] = 0;
        }
        return a;
    }

    static int[] prevPermutation(int[] a, int n) {
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i + 1]) {
                int min = i + 1;
                for (int j = i + 1; j < n; j++) {
                    if ((a[j] > a[min]) && (a[j] < a[i])) {
                        min = j;
                    }
                }
                int tmp = a[min];
                a[min] = a[i];
                a[i] = tmp;
                reverse(a, i + 1, n - 1);
                return a;
            }
        }
        for (int i = 0; i < n; i++) {
            a[i] = 0;
        }
        return a;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("nextperm.in"));
        FileWriter fileWriter = new FileWriter(new File("nextperm.out"));
        int n = scanner.nextInt();
        int a[] = new int[n];
        int b[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            b[i] = a[i];
        }
        int nx[] = nextPermutation(a, n);
        int pv[] = prevPermutation(b, n);
        for (int i = 0; i < n; i++) {
            fileWriter.write(pv[i] + " ");
        }
        fileWriter.write("\n");
        for (int i = 0; i < n; i++) {
            fileWriter.write(nx[i] + " ");
        }
        fileWriter.flush();
    }
}
