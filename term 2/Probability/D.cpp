#include <iostream>

using namespace std;


int main() {
    freopen("markchain.in", "r", stdin);
    freopen("markchain.out", "w", stdout);
    int n;
    cin >> n;
    double Q[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Q[i][j];
        }
    }
    for (int m = 0; m < 15; m++) {
        double c[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)c[i][j] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c[i][j] += Q[i][k] * Q[k][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Q[i][j] = c[i][j];
            }
        }
    }


    double p[n];
    double res[n];
    for (int i = 0; i < n; i++) {
        p[i] = 1 / (double) n;
        res[i] = 0;
    }

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            res[j] += p[k] * Q[k][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i];
        cout << endl;
    }
    return 0;
}