#include <iostream>
#include <vector>

int n, m, k;
std::vector<int> aut[100001];
std::vector<int> autr[100001];
bool finalstates[100001];
bool visited[100001];
bool used[100001];

long long counter(int v) {
    if (!used[v])
        return 0;
    long long int res = finalstates[v] ? 1 : 0;
    for (long long int i = 0; i < aut[v].size(); ++i) {
        res = (res + counter(aut[v][i])) % 1000000007;
    }
    return res;
}

void dfs(int v) {
    if (used[v] || visited[v])
        return;
    visited[v] = true;
    used[v] = true;
    for (int i = 0; i < autr[v].size(); ++i)
        dfs(autr[v][i]);
    visited[v] = false;
}

bool findCycle(int v) {
    if (!used[v])
        return false;
    if (visited[v])
        return true;
    visited[v] = true;
    for (int i = 0; i < aut[v].size(); ++i) {
        if (findCycle(aut[v][i])) {
            visited[v] = false;
            return true;
        }
    }
    visited[v] = false;
    return false;
}

void addTransition(int a, int b) {
    aut[a].push_back(b);
    autr[b].push_back(a);
}

int main() {
    freopen("problem3.in", "r", stdin);
    freopen("problem3.out", "w", stdout);
    std::vector<int> tstates;
    int x;
    scanf("%d %d %d", &n, &m, &k);
    n++;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        finalstates[x] = true;
        tstates.push_back(x);
    }
    int a, b;
    char c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %c", &a, &b, &c);
        addTransition(a, b);
    }
    for (int i : tstates) {
        dfs(i);
    }
    findCycle(1) ? printf("-1") : printf("%lld", counter(1));
    return 0;
}

