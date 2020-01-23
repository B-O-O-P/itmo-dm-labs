package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
    public static class BulFU {
        int kol;
        int[] val;

        BulFU(int x, int[] y) {
            this.kol = x;
            this.val = y;
        }


    }

    public static boolean Nullik(BulFU[] a) {
        boolean nullik = true;
        for (int i = 0; i < a.length; i++) {
            int first = Integer.parseInt(String.valueOf(a[i].val[0]));
            if (first != 0) {
                nullik = false;
                break;
            }
        }
        return nullik;
    }

    public static boolean Edinichka(BulFU[] a) {
        boolean edin = true;
        for (int i = 0; i < a.length; i++) {
            int last = (a[i].val[a[i].val.length - 1]);
            if (last != 1) {
                edin = false;
                break;
            }
        }
        return edin;
    }

    public static boolean IaSam(BulFU[] a) {
        boolean sam = true;
        for (int i = 0; i < a.length; i++) {
            int l = a[i].val.length;
            for (int j = 0; j < l; j++) {
                if (a[i].val[j] == a[i].val[l - j - 1]) {
                    sam = false;
                    break;
                }
            }
            if (!sam) {
                break;
            }

        }
        return sam;
    }

    public static boolean MonoMoon(int a[]) {
        if (a.length == 1) {
            return true;
        }
        int s = a.length / 2;
        for (int i = 0; i < s; i++) {
            if (a[i] > a[i + s]) {
                return false;
            }
        }
        int[] l = new int[s];
        int[] r = new int[s];
        for (int i = 0; i < s; i++) {
            l[i] = a[i];
            r[i] = a[a.length - s + i];
        }
        return (MonoMoon(l) && MonoMoon(r));
    }

    public static boolean MonoTONNA(BulFU[] a) {
        boolean mon = true;
        for (int i = 0; i < a.length; i++) {
            if (!MonoMoon(a[i].val)) {
                mon = false;
                break;
            }
        }
        return mon;
    }

    public static boolean Lineechka(BulFU[] a) {
        for (int i = 0; i < a.length; i++) {
            List<Integer> polka = new ArrayList<Integer>(Polinomchik(a[i]));
            int ind = 0;
            for (int j = 0; j < polka.size(); j++) {
                int cur = polka.get(j);

                if (cur == 1) {
                    if (j != ind) {
                        return false;
                    }
                    if (ind == 0) {
                        ind = 1;
                    } else {
                        ind = ind * 2;
                    }
                }
                if (j == ind) {
                    if (ind == 0) {
                        ind = 1;
                    } else {
                        ind = ind * 2;
                    }
                }
            }
        }
        return true;
    }

    public static List<Integer> Polinomchik(BulFU a) {
        List<Integer> pref = new ArrayList<Integer>();
        for (int i = 0; i < a.val.length; i++) {
            pref.add(a.val[i]);
        }

        List<Integer> caef = new ArrayList<Integer>();
        List<Integer> n;

        while (pref.size() > 1) {
            caef.add(pref.get(0));
            n = new ArrayList<Integer>();

            for (int i = 0; i < pref.size() - 1; i++) {
                n.add(pref.get(i) ^ pref.get(i + 1));
            }
            pref = new ArrayList<Integer>(n);
        }
        caef.add(pref.get(0));
        return caef;
    }

    public static void main(String[] args) {


        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        BulFU a[] = new BulFU[n];
        for (int i = 0; i < n; i++) {
            String s[] = scanner.nextLine().split(" ");
            int si = Integer.parseInt(s[0]);
            int b[] = new int[(int) Math.pow(2, si)];
            for (int j = 0; j < b.length; j++) {
                b[j] = Integer.parseInt(String.valueOf(s[1].charAt(j)));
            }
            a[i] = new BulFU(si, b);
        }
        if ((Nullik(a))) {
            System.out.print("NO");
            System.exit(0);
        }
        if ((Edinichka(a))) {
            System.out.print("NO");
            System.exit(0);
        }
        if (IaSam(a)) {
            System.out.print("NO");
            System.exit(0);
        }
        if (MonoTONNA(a)) {
            System.out.print("NO");
            System.exit(0);
        }
        if (Lineechka(a)) {
            System.out.print("NO");
            System.exit(0);
        }
        System.out.print("YES");
    }
}
