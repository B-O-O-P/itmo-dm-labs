#include <iostream>

using namespace std;

int main() {
    freopen("shooter.in", "r", stdin);
    freopen("shooter.out", "w", stdout);
    int n, m, k;
    double p, a = 1, b = 0;
    cin >> n;
    cin >> m;
    cin >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        p = 1 - p;
        double temp = 1;
        for (int j = 0; j < m; j++) temp *= p;
        if (i == k) { a = temp; }
        b += temp;
    }
    cout.precision(13);
    cout << a / b;
    return 0;
}