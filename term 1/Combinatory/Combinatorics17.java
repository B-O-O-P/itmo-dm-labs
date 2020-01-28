package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics17 {

    static String getParenthesis(int n, long k) {
        StringBuilder string = new StringBuilder();
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
            if (dno + 1 <= n && dp[len - i - 1][dno + 1] >= k) {
                string.append("(");
                dno = dno + 1;
            } else {
                if (dno + 1 <= n) {
                    k = k - dp[len - i - 1][dno + 1];
                }
                string.append(")");
                dno = dno - 1;
            }
        }
        return string.toString();
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("num2brackets.in"));
        FileWriter fileWriter = new FileWriter(new File("num2brackets.out"));
        int n = scanner.nextInt();
        long k = scanner.nextLong();
        //int n=4;
        //long k=14;
        fileWriter.write(getParenthesis(n, k + 1) + "");
        fileWriter.flush();
    }
}
