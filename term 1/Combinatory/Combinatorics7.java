package ru.itmo.chizhikov;

import java.io.IOException;

public class Combinatorics7 {

    static void reverse(int a[], int i, int j) {
        while (i != j && i < j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    static int[] nextPermutation(int a[], int n) {
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                int min = i + 1;
                for (int j = i + 1; j < n; j++) {
                    if ((a[j] < a[min]) && (a[j] > a[i])) {
                        min = j;
                    }
                }
                int tmp = a[min];
                a[min] = a[i];
                a[i] = tmp;
                reverse(a, i + 1, n - 1);
                return a;
            }
        }
        return null;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner=new Scanner(new File("permutations.in"));
        FileWriter fileWriter=new FileWriter(new File("permutations.out"));
        int n=scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            m = m * (i);
        }
        int PERM[] = new int[n];
        for (int i = 0; i < n; i++) {
            PERM[i] = i + 1;
        }
        for (int j = 0; j < n; j++) {
            System.out.print(PERM[j] + " ");
        }
        System.out.print("\n");
        int cur[] = nextPermutation(PERM, n);
        int cnt = 1;
        for (int i = 0; i < m - 1; i++) {
            if (cur == null) {
                break;
            }
            for (int j = 0; j < n; j++) {
                System.out.print(cur[j] + " ");
            }
            System.out.print("\n");
            cur = nextPermutation(PERM, n);
        }
    }
}
