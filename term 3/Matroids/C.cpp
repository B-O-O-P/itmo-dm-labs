#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

size_t n;
vector<vector<int>> graph;
vector<int> match, backMatch;
vector<bool> used;

struct Vertex {
    int v, w;
};

bool operator<(const Vertex& first, const Vertex& second) {
    return first.w > second.w;
}

vector<Vertex> order;

bool kuhnAlgo(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];
        if (match[to] == -1 || kuhnAlgo(match[to])) {
            match[to] = v;
            backMatch[v] = to;
            return true;
        }
    }
    return false;

}

void findGreedyMatching() {
    for (int i = 0; i < n; ++i) {
        int v = order[i].v;
        used.assign(n, false);
        kuhnAlgo(v);
    }
}

int main() {
    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);

    cin >> n;
    graph.resize(n);
    match.assign(n, -1);
    backMatch.assign(n, -1);
    used.resize(n);

    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        order.push_back({i, w});
    }


    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u;
        for (int j = 0; j < u; ++j) {
            int v;
            cin >> v;
            v--;
            graph[i].push_back(v);
        }
    }

    sort(order.begin(), order.end());
    findGreedyMatching();
    for (int i = 0; i < n; ++i) {
        cout << backMatch[i] + 1 << " ";
    }

    return 0;
}