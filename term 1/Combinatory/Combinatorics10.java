package ru.itmo.chizhikov;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Combinatorics10 {

    static ArrayList<Integer> nextPart(ArrayList<Integer> a) {
        a.set(a.size() - 1, a.get(a.size() - 1) - 1);
        a.set(a.size() - 2, a.get(a.size() - 2) + 1);
        if (a.get(a.size() - 2) > a.get(a.size() - 1)) {
            a.set(a.size() - 2, a.get(a.size() - 2) + a.get(a.size() - 1));
            a.remove(a.size() - 1);
        } else
            while (a.get(a.size() - 2) * 2 <= a.get(a.size() - 1)) {
                a.add(a.get(a.size() - 1) - a.get(a.size() - 2));
                a.set(a.size() - 2, a.get(a.size() - 3));
            }
        return a;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("partition.in"));
        FileWriter fileWriter = new FileWriter(new File("partition.out"));
        int n = scanner.nextInt();
        //int n=4;
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(1);
        }
        for (int i = 0; i < a.size(); i++) {
            if (i != a.size() - 1) fileWriter.write(a.get(i) + "+");
            else fileWriter.write(a.get(a.size() - 1) + "\n");
        }
        while (a.size() != 1) {
            a = nextPart(a);
            for (int i = 0; i < a.size(); i++) {
                if (i != a.size() - 1) fileWriter.write(a.get(i) + "+");
                else fileWriter.write(a.get(a.size() - 1) + "\n");
            }
        }
        fileWriter.flush();
    }
}
