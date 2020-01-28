package ru.itmo.chizhikov;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Combinatorics29 {


    static ArrayList<Integer> nextFragmentation(ArrayList<Integer> a) {
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
        Scanner scanner = new Scanner(new File("nextpartition.in"));
        FileWriter fileWriter = new FileWriter(new File("nextpartition.out"));
        String data = scanner.nextLine();
        String plus[] = data.split("=");
        String n = plus[0];
        String s[] = plus[1].split("\\+");
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 0; i < s.length; i++) {
            a.add(Integer.parseInt(s[i]));
        }
        if (a.size() != 1) {
            a = nextFragmentation(a);
            fileWriter.write(n + "=");
            for (int i = 0; i < a.size() - 1; i++) {
                fileWriter.write(a.get(i) + "+");
            }
            System.out.print(a.get(a.size() - 1) + "");
        } else fileWriter.write("No solution");
    }
}
