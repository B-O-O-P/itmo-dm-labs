package ru.itmo.chizhikov;


import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics28 {

    static void reverse(int a[], int i, int j) {
        while (i != j && i < j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    static int[] nextMultiPermutation(int[] a, int n) {
        int ind = n - 2;
        while ((ind >= 0) && (a[ind] >= a[ind + 1])) {
            ind--;
        }
        if (ind > -1) {
            int inj = ind + 1;
            while ((inj < n - 1) && (a[inj + 1] > a[ind])) {
                inj++;
            }
            int tmp = a[ind];
            a[ind] = a[inj];
            a[inj] = tmp;
            reverse(a, ind + 1, n - 1);
            return a;
        } else {
            for (int i = 0; i < n; i++) a[i] = 0;
            return a;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("nextmultiperm.in"));
        FileWriter fileWriter = new FileWriter(new File("nextmultiperm.out"));
        int n = scanner.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) a[i] = scanner.nextInt();
        a = nextMultiPermutation(a, n);
        for (int i = 0; i < n; i++) {
            fileWriter.write(a[i] + " ");
        }
        fileWriter.flush();
    }
}
