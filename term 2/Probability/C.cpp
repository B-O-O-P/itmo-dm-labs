    #include <iostream>

using namespace std;

int main() {
    freopen("lottery.in", "r", stdin);
    freopen("lottery.out", "w", stdout);
    int n, m;
    cin >> n;
    cin >> m;
    int *b = new int[m + 1];
    double *a = new double[m + 1];
    b[0] = 0;
    a[0] = 1;
    new int[m + 1];
    double math = 0;
    double ai;
    for (int i = 1; i <= m; i++) {
        cin >> ai;
        a[i]=1/ai;
        cin >> b[i];
    }
    double pos = 1;
    for (int i = 0; i < m; i++) {
        pos *= a[i];
        math += b[i] * pos * (1 - a[i + 1]);
    }
    cout << n - (math + b[m] * pos * a[m]);
    return 0;
}