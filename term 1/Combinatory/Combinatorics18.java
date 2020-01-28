package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics18 {

    static long getNumber(String s, int n) {
        long num = 0;
        int len = 2 * n;
        long dp[][] = new long[len + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if (j > 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                if (j + 1 <= n) {
                    dp[i][j] += dp[i - 1][j + 1];
                }
            }
        }
        int dno = 0;
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == '(') {
                dno = dno + 1;
            } else {
                if (dno + 1 <= n) {
                    num = num + dp[len - i - 1][dno + 1];
                }
                dno = dno - 1;
            }
        }
        return num;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("brackets2num.in"));
        FileWriter fileWriter = new FileWriter(new File("brackets2num.out"));
        String s = scanner.nextLine();
        //String s="()()()()";
        fileWriter.write((getNumber(s, s.length() / 2) + ""));
        fileWriter.flush();
    }
}
