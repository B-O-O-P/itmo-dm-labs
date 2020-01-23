package ru.itmo.chizhikov;

import java.util.ArrayList;
import java.util.Scanner;

public class B {
    static ArrayList<Integer> step1(int n, int k, int a[][]) {
        ArrayList<Integer> nep = new ArrayList<Integer>();
        int tj = -1;
        int ti = -1;
        boolean est = false;
        for (int i = 0; i < k; i++) {
            int cnt1 = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] != -1) {
                    cnt1++;
                    tj = j;
                    ti = i;
                    est = true;
                }
            }
            if (cnt1 == 1 && est) {
                break;
            }
        }
        for (int i = 0; i < k; i++) {
            int kol = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] != -1) {
                    kol++;
                }
            }
            if (a[i][tj] > 0 && a[ti][tj] > 0) {
                nep.add(i);
            }
            if (a[i][tj] < 0 && a[ti][tj] < 0) {
                nep.add(i);
            }
            if (kol == 1 && a[ti][tj] < 0 && a[i][tj] > 0) {
                System.out.print("YES");
                System.exit(0);
            }
            if (kol == 1 && a[ti][tj] > 0 && a[i][tj] < 0) {
                System.out.print("YES");
                System.exit(0);
            }
        }
        for (int i = 0; i < k; i++) {
            a[i][tj] = -1;
        }
        return nep;
    }

    static void step2(int n, int k, int a[][], ArrayList<Integer> nep) {
        if (nep.size() != k) {
            int b[][] = new int[nep.size()][n];
            for (int i = 0; i < nep.size(); i++) {
                for (int j = 0; j < n; j++) {
                    b[i][j] = a[nep.get(i)][j];
                }
            }
            step2(n, k, b, step1(n, b.length, b));
        } else {
            System.out.print("NO");
        }
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] s = scanner.nextLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);
        int a[][] = new int[k][n];
        for (int i = 0; i < k; i++) {
            String[] str = scanner.nextLine().split(" ");
            for (int j = 0; j < n; j++) {
                a[i][j] = Integer.parseInt(str[j]);
            }
        }
        step2(n, k, a, step1(n, k, a));
    }
}
