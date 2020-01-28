package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics9 {

    static String nextParenthesis(String s) {
        int st = 0, end = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') {
                st++;
                if (end > st) {
                    break;
                }
            } else {
                end++;
            }
        }
        s = s.substring(0, s.length() - st - end);
        if (s.equals("")) {
            return "error";
        } else {
            StringBuilder stringBuilder = new StringBuilder(s);
            stringBuilder.append(")");
            for (int i = 1; i <= st; i++) {
                stringBuilder.append("(");
            }
            for (int i = 1; i < end; i++) {
                stringBuilder.append(')');
            }
            s = stringBuilder.toString();
        }
        return s;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("brackets.in"));
        FileWriter fileWriter = new FileWriter(new File("brackets.out"));
        int n = scanner.nextInt();
        StringBuilder string = new StringBuilder();
        for (int i = 0; i < n; i++) {
            string = string.append("(");
        }
        for (int i = 0; i < n; i++) {
            string = string.append(")");
        }
        String res = string.toString();
        fileWriter.write(res + "");
        while (!nextParenthesis(res).equals("error")) {
            res = nextParenthesis(res);
            fileWriter.write("\n" + res);
        }
        fileWriter.flush();
    }
}
