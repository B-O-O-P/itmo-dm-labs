#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n1, m1, k1, n2, m2, k2;
vector<vector<int>> aut1;
vector<vector<int>> aut2;
vector<int> finalstates1, finalstates2;
vector<bool> visited1, visited2;

void addTransition(vector<vector<int>> &v, int a, int b, char c) {
    v[a][c - 'a'] = b;
}


bool BFS(queue<pair<int, int>> Q) {
    pair<int, int> temp = make_pair(1, 1);
    Q.push(temp);
    while (!Q.empty()) {
        pair<int, int> curr = Q.front();
        if (curr.first != 0) {
            visited1[curr.first] = true;
        }
        if (curr.second != 0) {
            visited2[curr.second] = true;
        }
        Q.pop();
        if (finalstates1[curr.first] != finalstates2[curr.second])
            return false;
        for (int i = 0; i < 26; i++) {
            int u = aut1[curr.first][i];
            int v = aut2[curr.second][i];
            if (!visited1[u] || !visited2[v]) {
                if (v != 0 || u != 0) {
                    Q.push(make_pair(u, v));
                }
            }
        }
    }
    return true;
}

int main() {
    freopen("equivalence.in", "r", stdin);
    freopen("equivalence.out", "w", stdout);
    cin >> n1 >> m1 >> k1;
    n1++;
    finalstates1.resize((unsigned) n1);
    aut1.resize((unsigned) n1);
    visited1.resize((unsigned) n1);
    for (int i = 0; i < n1; i++) {
        aut1[i].resize(26);
    }
    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        finalstates1[x] = true;
    }
    int a, b;
    char c;
    for (int i = 0; i < m1; i++) {
        cin >> a >> b >> c;
        addTransition(aut1, a, b, c);
    }


    cin >> n2 >> m2 >> k2;
    n2++;
    finalstates2.resize((unsigned) n2);
    aut2.resize((unsigned) n2);
    visited2.resize((unsigned) n2);
    for (int i = 0; i < n2; i++) {
        aut2[i].resize(26);
    }
    for (int i = 0; i < k2; i++) {
        int x;
        cin >> x;
        finalstates2[x] = true;
    }
    for (int i = 0; i < m2; i++) {
        cin >> a >> b >> c;
        addTransition(aut2, a, b, c);
    }
    queue<pair<int, int>> Q;
    string ans = BFS(Q) ? "YES" : "NO";
    cout << ans;
    return 0;
}