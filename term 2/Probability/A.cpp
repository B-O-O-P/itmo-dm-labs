#include <iostream>

using namespace std;

int main() {
    freopen("exam.in", "r", stdin);
    freopen("exam.out", "w", stdout);
    double k, n, p, m;
    double res = 0;
    cin >> k;
    cin >> n;
    for (int i = 0; i < k; i++) {
        cin >> p;
        cin >> m;
        double p1 = p/n;
        res += p1 * m * 0.01;
    }
    cout.precision(5);
    cout << res;
    return 0;
}