package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics5 {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("telemetry.in"));
        FileWriter fileWriter = new FileWriter(new File("telemetry.out"));
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int len = (int) Math.pow(k, n);
        String s[] = new String[len];
        for (int i = 0; i < len; i++) s[i] = "";
        int st = 1;
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (j < len) {
                int cur = 0;
                int cnt = 0;
                if (j < len) {
                    while (cur < k) {
                        cnt = 0;
                        while (cnt < st) {
                            s[j] = s[j] + cur;
                            cnt++;
                            j++;
                        }
                        cur++;
                    }
                }
                if (j < len) {
                    while (cur > 0) {
                        cur--;
                        cnt = 0;
                        while (cnt < st) {
                            s[j] = s[j] + cur;
                            cnt++;
                            j++;
                        }
                    }
                }
            }
            st = st * k;
        }
        for (int i = 0; i < len; i++) {
            fileWriter.write(s[i] + "\n");
        }
        fileWriter.flush();
    }
}
