package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics22 {

    static class PartList {
        int b[];
        int size;

        PartList(int b[]) {
            this.b = b;
            this.size = b.length;
        }

        PartList(int b[], int n) {
            this.b = b;
            this.size = n;
        }
    }

    static PartList nextPartFast(PartList a) {
        a.b[a.size - 1]--;
        a.b[a.size - 2]++;
        if (a.b[a.size - 1] < a.b[a.size - 2]) {
            a.b[a.size - 2] += a.b[a.size - 1];
            a.b[a.size - 1] = 0;
            a.size--;
        } else {
            while (a.b[a.size - 1] >= a.b[a.size - 2] * 2) {
                int ch = a.b[a.size - 1] - a.b[a.size - 2];
                a.size++;
                a.b[a.size - 1] = ch;
                a.b[a.size - 2] = a.b[a.size - 3];
            }
        }
        return a;
    }

    static long getFragmentation(PartList x, int n) {
        long num = 0;
        int b[] = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = 1;
        }
        PartList a = new PartList(b);
        while (true) {
            if (a.size == x.size) {
                boolean ans = true;
                for (int i = x.size - 1; i >= 0; i--) {
                    if (x.b[i] != a.b[i]) {
                        ans = false;
                        break;
                    }
                }
                if (ans) break;
            }
            a = nextPartFast(a);
            num++;
        }
        return num;
    }


    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("part2num.in"));
        FileWriter fileWriter = new FileWriter(new File("part2num.out"));
        String s[] = scanner.nextLine().split("\\+");
        int n = 0;
        int size = 0;
        int b[] = new int[100];
        for (int i = 0; i < s.length; i++) {
            int cur = Integer.parseInt(s[i]);
            n += cur;
            b[i] = cur;
            size++;
        }
        int a[] = new int[n];
        PartList x = new PartList(a, size);
        for (int i = 0; i < n; i++) a[i] = b[i];
        fileWriter.write(getFragmentation(x, n) + "");
        fileWriter.flush();
    }
}
