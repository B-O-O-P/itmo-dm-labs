package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Combinatorics4 {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("chaincode.in"));
        FileWriter fileWriter = new FileWriter(new File("chaincode.out"));
        int n = scanner.nextInt();
        Map<String, String> a = new HashMap<String, String>();
        String cur = "";
        StringBuilder first = new StringBuilder();
        for (int i = 0; i < n; i++) {
            first.append("0");
        }
        cur = first.toString();
        a.put(cur, cur);
        fileWriter.write(cur + "\n");
        while (true) {
            String pref = cur.substring(1);
            if (!a.containsKey(pref + "1")) {
                cur = pref + "1";
            } else if (!a.containsKey(pref + "0")) {
                cur = pref + "0";
            } else break;
            a.put(cur, cur);
            fileWriter.write(cur + "\n");
        }
        fileWriter.flush();
    }
}