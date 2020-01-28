package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Combinatorics27 {

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
            return "-";
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
        Scanner scanner = new Scanner(new File("nextbrackets.in"));
        FileWriter fileWriter = new FileWriter(new File("nextbrackets.out"));
        String s = scanner.nextLine();
        fileWriter.write(nextParenthesis(s));
        fileWriter.flush();
    }
}
