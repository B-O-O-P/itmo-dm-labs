package com.company;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class C {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("mtf.in"));
        FileWriter fileWriter = new FileWriter(new File("mtf.out"));
        String s = scanner.nextLine();
        int n = s.length();
        int APLHABET[] = new int[26];
        for (int i = 0; i < 26; i++) {
            APLHABET[i] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            int cur = (int) s.charAt(i) - 97;
            int val = APLHABET[cur];
            fileWriter.write(val + " ");
            for (int j = 0; j < 26; j++) {
                if (APLHABET[j] < val) {
                    APLHABET[j]++;
                }
            }
            APLHABET[cur] = 1;
        }
        fileWriter.flush();
    }
}
