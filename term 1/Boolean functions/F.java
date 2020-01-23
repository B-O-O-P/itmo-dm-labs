package ru.itmo.chizhikov;

import com.sun.org.apache.regexp.internal.RE;

import java.util.ArrayList;
import java.util.Scanner;

public class F {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        ArrayList<Integer> F = new ArrayList<Integer>();
        ArrayList<String> Values = new ArrayList<String>();
        ArrayList<Integer> Rezzzzz = new ArrayList<Integer>();
        for (int i = 0; i < (int) Math.pow(2, n); i++) {
            String s[] = scanner.nextLine().split(" ");
            Values.add(s[0]);
            F.add(Integer.parseInt(s[1]));
        }
        Rezzzzz.add(F.get(0));
        while (F.size() > 0) {
            for (int i = 0; i < F.size() - 1; i++) {
                F.set(i, (F.get(i) + F.get(i + 1)) % 2);
            }
            Rezzzzz.add(F.get(0));
            F.remove(F.size() - 1);
        }
        for (int i = 0; i < Values.size(); i++) {
            System.out.println(Values.get(i) + " " + Rezzzzz.get(i));
        }
    }
}
