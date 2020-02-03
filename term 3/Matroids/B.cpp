#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

size_t n, m;
uint64_t s;

struct Edge {
    int u, v, number;
    long long w;
    bool isUsed = false;
};
vector<Edge> edges;
vector<int> parent, size;


bool operator<(const Edge& first, const Edge& second) {
    return first.w > second.w;
}

bool order(const Edge& first, const Edge& second) {
    return first.number < second.number;
}

int getDSU(int v) {
    if (v != parent[v]) {
        parent[v] = getDSU(parent[v]);
    }
    return parent[v];
}

void uniteDsu(int x, int y) {
    x = getDSU(x);
    y = getDSU(y);

    if (size[x] < size[y]) {
        x = x + y;
        y = x - y;
        x = x - y;
    }
    parent[y] = x;
    size[x] += size[y];

}

long long maxKruskal() {

    sort(edges.begin(), edges.end());
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = i;
    }

    long long res = 0;
    for (int i = 0; i < m; ++i) {
        int v = edges[i].v;
        int u = edges[i].u;
        long long w = edges[i].w;
        if (getDSU(v) != getDSU(u)) {
            edges[i].isUsed = true;
            res += w;
            uniteDsu(u, v);
        }
    }
    return res;
};

int main() {
    freopen("destroy.in", "r", stdin);
    freopen("destroy.out", "w", stdout);

    cin >> n >> m >> s;
    edges.resize(m);
    parent.resize(n);
    size.resize(n);

    long long sumOfEdges = 0;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
        edges[i].number = i + 1;
        sumOfEdges += edges[i].w;
    }

    long long maxSpTree = maxKruskal();

    vector<Edge> res;
    int cur = 0;

    while (maxSpTree + s < sumOfEdges) {
        if (!edges[cur].isUsed) {
            edges[cur].isUsed = true;
            maxSpTree += edges[cur].w;
        }
        cur++;
    }

    for (int i = 0; i < m; ++i) {
        if (!edges[i].isUsed) {
            res.push_back(edges[i]);
        }
    }

    sort(res.begin(), res.end(), order);

    cout << res.size() << "\n";

    for (auto& r : res) {
        cout << r.number << " ";
    }

    return 0;
}