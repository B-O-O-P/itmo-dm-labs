package ru.ifmo.chizhikov;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class A {
    static ArrayList<ArrayList<Integer>> up = new ArrayList<ArrayList<Integer>>(100000), down = new ArrayList<ArrayList<Integer>>(10000);
    static boolean[] vu = new boolean[100000], vd = new boolean[100000];
    static Stack<Integer> stack = new Stack<Integer>();
    static int sc[] = new int[100000];
    static int cnt = 1;

    static void add(int a, int b) {
        up.get(a).add(b);
    }

    static void addRe(int a, int b) {
        down.get(b).add(a);
    }

    static void step1(int a) {
        if (!vu[a]) {
            vu[a] = true;
            for (int i = 0; i < up.get(a).size(); i++) {
                step1(up.get(a).get(i));
            }
            stack.push(a);
        }
    }

    static void step2(int a) {
        if (!vd[a]) {
            vd[a] = true;
            for (int i = 0; i < down.get(a).size(); i++) {
                step2(down.get(a).get(i));
            }
            sc[a] = cnt;
        }
    }

    static void Solver(int n, int m, int a[], int b[]) {
        for (int i = 0; i < m; i++) {
            if (a[i] > 0 && b[i] > 0) {
                add(a[i] + n, b[i]);
                addRe(a[i] + n, b[i]);
                add(b[i] + n, a[i]);
                addRe(b[i] + n, a[i]);
            } else if (a[i] > 0 && b[i] < 0) {
                add(a[i] + n, n - b[i]);
                addRe(a[i] + n, n - b[i]);
                add(-b[i], a[i]);
                addRe(-b[i], a[i]);
            } else if (a[i] < 0 && b[i] > 0) {
                add(-a[i], b[i]);
                addRe(-a[i], b[i]);
                add(b[i] + n, n - a[i]);
                addRe(b[i] + n, n - a[i]);
            } else {
                add(-a[i], n - b[i]);
                addRe(-a[i], n - b[i]);
                add(-b[i], n - a[i]);
                addRe(-b[i], n - a[i]);
            }
        }

        for (int i = 1; i <= 2 * n; i++) {
            if (!vu[i]) {
                step1(i);
            }
        }

        while (!stack.isEmpty()) {
            int k = stack.lastElement();
            stack.pop();
            if (!vd[k]) {
                step2(k);
                cnt++;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (sc[i] == sc[i + n]) {
                System.out.print("YES");
                System.exit(0);
            }
        }
        System.out.print("NO");
        System.exit(0);
    }

    public static void main(String[] args) {
        up.add(new ArrayList<Integer>());
        down.add(new ArrayList<Integer>());
        Scanner scanner = new Scanner(System.in);
        String f1[] = scanner.nextLine().split(" ");
        int m = Integer.parseInt(f1[1]);
        int n = Integer.parseInt(f1[0]);
        int a[] = new int[m];
        int b[] = new int[m];
        for (int i = 0; i < 100000; i++) {
            up.add(new ArrayList<Integer>());
            down.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < m; i++) {
            String s[] = scanner.nextLine().split(" ");
            a[i] = Integer.parseInt(s[0]);
            b[i] = Integer.parseInt(s[1]);
        }
        Solver(n, m, a, b);
    }
}
