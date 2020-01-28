package ru.itmo.chizhikov;

import java.io.IOException;

public class Combinatorics19 {

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
        int newlen = 0;
        StringBuilder opend = new StringBuilder();
        opend.setLength(len);

        for (int i = len - 1; i >= 0; i--) {
            long cur;
            long dif;
            if (dno < n) {
                if (dno < -1) {
                    dif = 0;
                } else {
                    dif = dp[i][dno + 1] << ((i - (dno + 1)) / 2);
                }
                cur = dif;
            } else {
                cur = 0;
            }
            if (cur >= k) {
                string.append('(');
                opend.setCharAt(newlen, '(');
                newlen++;
                dno++;
                continue;
            }
            k -= cur;
            if (newlen > 0) {
                if (opend.charAt(newlen - 1) == '(') {
                    if (dno > 0) {
                        dif = dp[i][dno - 1] << ((i - (dno - 1)) / 2);
                        cur = dif;
                    } else {
                        cur = 0;
                    }
                } else {
                    cur = 0;
                }
            } else {
                cur = 0;
            }
            if (cur >= k) {
                string.append(')');
                newlen--;
                dno--;
                continue;
            }
            k -= cur;
            if (dno < n) {
                if (dno < -1) {
                    dif = 0;
                } else {
                    dif = dp[i][dno + 1] << ((i - (dno + 1)) / 2);
                }
                cur = dif;
            } else {
                cur = 0;
            }
            if (cur >= k) {
                string.append('[');
                opend.setCharAt(newlen, '[');
                newlen++;
                dno++;
                continue;
            }
            k -= cur;
            string.append(']');
            newlen--;
            dno--;
        }
        return string.toString();
    }


    public static void main(String[] args) throws IOException {
        /*Scanner scanner=new Scanner(new File("num2brackets2.in"));
        FileWriter fileWriter=new FileWriter(new File("num2brackets2.out"));
        int n=scanner.nextInt();
        long k=scanner.nextLong();*/
        int n = 4;
        long k = 100;
        System.out.print(getParenthesis(n, k + 1) + "");
    }
}
