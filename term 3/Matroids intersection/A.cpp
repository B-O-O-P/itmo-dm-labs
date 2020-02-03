#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

class Edge {
public:
    int u, v, c;

    Edge(int u, int v, int c) : u(u), v(v), c(c) {};
};


size_t n, m;
std::vector<Edge> edges;
std::vector<int> bp;
std::vector<std::vector<int>> graph;
std::set<int> multiForest;


int getDSU(int v, std::vector<int>& p) {
    return (v == p[v]) ? v : (p[v] = getDSU(p[v], p));
}

void uniteDSU(int x, int y, std::vector<int>& p) {
    x = getDSU(x, p);
    y = getDSU(y, p);

    if (rand() & 1) {
        std::swap(x, y);
    }

    if (x != y) {
        p[x] = y;
    }

}

std::set<int> bfs(int start, std::vector<bool>& graphic, std::vector<std::vector<int>>& graph) {
    size_t n = graph.size();
    std::vector<bool> used(n);
    std::vector<int> parent(n);
    std::queue<int> q;
    std::set<int> result;

    used[start] = true;
    parent[start] = -1;
    q.push(start);
    int res = -1;
    bool f = false;

    while (!q.empty() && !f) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < graph[v].size(); ++i) {
            int u = graph[v][i];

            if (!used[u]) {
                used[u] = true;
                q.push(u);
                parent[u] = v;
            }

            if (graphic[u]) {
                f = true;
                res = u;
                break;
            }
        }
    }

    for (int v = res; v != -1; v = parent[v]) {
        result.insert(v);
    }
    return result;
}

int main() {
    freopen("rainbow.in", "r", stdin);
    freopen("rainbow.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        bp.push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        u--;
        v--;
        c--;

        edges.emplace_back(u, v, c);
    }

    multiForest.insert(0);
    bool allUsed = false;
    while (!allUsed) {
        std::vector<int> independent, dependent;
        std::vector<bool> used(100, false);

        auto s = multiForest.begin();

        for (int i = 0; i < m; ++i) {
            if (s != multiForest.end() && i == *s) {
                independent.push_back(i);
                used[edges[i].c] = true;
                s++;
            } else {
                dependent.push_back(i);
            }
        }

        graph = std::vector<std::vector<int>>(m + 1);
        std::vector<bool> intersect(m, false);

        for (int x : dependent) {
            if (!used[edges[x].c]) {
                graph[m].push_back(x);
            }
            for (int y : independent) {
                if (edges[y].c == edges[x].c || !used[edges[x].c]) {
                    graph[y].push_back(x);
                }
            }
        }

        for (int i = 0; i < independent.size(); ++i) {
            int y = independent[i];

            std::vector<int> parent = std::vector<int>(bp.cbegin(), bp.cend());

            for (int ny : independent) {
                if (ny != y) {
                    uniteDSU(edges[ny].v, edges[ny].u, parent);
                }
            }

            for (int x : dependent) {
                if (getDSU(edges[x].v, parent) != getDSU(edges[x].u, parent)) {
                    graph[x].push_back(y);
                }
            }

            uniteDSU(edges[y].v, edges[y].u, parent);

            for (int x : dependent) {
                if (getDSU(edges[x].v, parent) != getDSU(edges[x].u, parent)) {
                    intersect[x] = true;
                }
            }

        }

        std::set<int> path = bfs(m, intersect, graph);
        path.erase(m);

        if (path.empty()) {
            allUsed = true;
        } else {
            std::vector<int> mp(multiForest.size() + path.size());

            auto it = std::set_symmetric_difference(multiForest.begin(), multiForest.end(), path.begin(),
                                                    path.end(), mp.begin());
            multiForest = std::set<int>(mp.begin(), it);
        }
    }

    std::cout << multiForest.size() << "\n";
    for (int i : multiForest) {
        std::cout << i + 1 << " ";
    }
    return 0;
}