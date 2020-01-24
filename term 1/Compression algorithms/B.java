package com.company;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class B {

    static String[] NFSSHIFT(String s) {
        int n = s.length();
        String a[] = new String[n];
        a[0] = s;
        for (int i = 1; i < n; i++) {
            String part = a[i - 1].substring(n - 1);
            a[i] = part + a[i - 1].substring(0, n - 1);
        }
        return a;
    }

    static String SwordAndSorcery(String listik[]) {
        int n = listik.length;
        int num = 26;
        int m = n;
        String res = "";
        for (int i = m - 1; i >= 0; i--) {
            String b[] = new String[n];
            int[] c = new int[26];
            for (int j = 0; j <= num - 1; j++) {
                c[j] = 0;
            }

            for (int j = 0; j <= n - 1; j++) {
                int d = listik[j].charAt(i) - 97;
                c[d]++;
            }
            int count = 0;

            for (int j = 0; j <= num - 1; j++) {
                int tmp = c[j];
                c[j] = count;
                count += tmp;
            }
            for (int j = 0; j <= n - 1; j++) {
                int d = listik[j].charAt(i) - 97;
                b[c[d]] = listik[j];
                c[d]++;
            }
            listik = b;
        }
        for (int i = 0; i < n; i++) {
            res = res + listik[i].substring(n - 1);
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("bwt.in"));
        FileWriter fileWriter = new FileWriter(new File("bwt.out"));
        String s = scanner.nextLine();
        fileWriter.write(SwordAndSorcery(NFSSHIFT(s)));
        fileWriter.flush();
    }
}
