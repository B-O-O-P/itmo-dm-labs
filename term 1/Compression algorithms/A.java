package com.company;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class A {
    static long HUFFHUFF(long a[], int n) {
        long b[] = new long[n];
        int f1 = 0, f2 = 0;
        long res = 0;
        for (int i = 0; i < n; i++) {
            b[i] = (long) 100000000 * 1000 + 1;
        }
        boolean first, second, third;
        for (int i = 0; i < n - 1; i++) {
            if (f1 + 1 < n) {
                first = (((a[f1 + 1] + a[f1]) <= (a[f1] + b[f2])) && ((a[f1] + a[f1 + 1]) <= (b[f2] + b[f2 + 1])));
                second = (((a[f1] + b[f2]) <= (a[f1] + a[f1 + 1])) && ((a[f1] + b[f2]) <= (b[f2] + b[f2 + 1])));
                third = (((b[f2] + b[f2 + 1]) <= (a[f1] + a[f1 + 1])) && ((b[f2] + b[f2 + 1]) <= (a[f1] + b[f2])));
                if (first) {
                    b[i] = a[f1] + a[f1 + 1];
                    res = res + b[i];
                    f1 = f1 + 2;
                    continue;
                }
                if (second) {
                    b[i] = a[f1] + b[f2];
                    res = res + b[i];
                    f2++;
                    f1++;
                    continue;
                }
                if (third) {
                    b[i] = b[f2] + b[f2 + 1];
                    res = res + b[i];
                    f2 = f2 + 2;
                }
            } else {
                if (f1 < n) {
                    if (a[f1] + b[f2] <= b[f2] + b[f2 + 1]) {
                        b[i] = b[f2] + a[f1];
                        f1++;
                        f2++;
                        res = res + b[i];
                    } else {
                        b[i] = b[f2] + b[f2 + 1];
                        res = res + b[i];
                        f2 = f2 + 2;
                    }
                } else {
                    b[i] = b[f2] + b[f2 + 1];
                    res = res + b[i];
                    f2 = f2 + 2;
                }
            }
        }
        System.out.println(Arrays.toString(b));
        return res;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("huffman.in"));
        FileWriter fileWriter = new FileWriter(new File("huffman.out"));
        int n = scanner.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        Arrays.sort(a);
        fileWriter.write(HUFFHUFF(a, n) + "");
        fileWriter.flush();
    }
}
