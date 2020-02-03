#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n, m;
vector<pair<int, int>> edges;
vector<vector<int>> edgeGraph;
vector<int> coord;
vector<char> parts;

bool intersectionOfEdges(pair<int, int>& first,
                         pair<int, int>& second) {
    return (coord[first.first] < coord[second.second] &&
            coord[first.second] > coord[second.second] &&
            coord[first.first] > coord[second.first]) ||
           (coord[second.first] < coord[first.second] &&
            coord[second.second] > coord[first.second] &&
            coord[first.first] < coord[second.first]);
}

void makeEdgeGraph() {
    for (int i = 0; i < edges.size(); ++i) {
        if (coord[edges[i].second] < coord[edges[i].first]) {
            swap(edges[i].first, edges[i].second);
        }

        for (int i = 0; i < edgeGraph.size(); ++i) {
            for (int j = 0; j < edgeGraph.size(); ++j) {
                if (i != j) {
                    if (intersectionOfEdges(edges[i], edges[j])) {
                        edgeGraph[i].push_back(j);
                    }
                }
            }
        }
    }
}

bool checkGraph() {
    bool graphIsBipartite = true;
    parts.resize(edgeGraph.size());
    parts.assign(edgeGraph.size(), 0);
    for (int i = 0; i < edgeGraph.size(); ++i) {
        if (parts[i] == 0) {
            queue<int> queue1;
            queue1.push(i);
            parts[i] = 1;

            while (!queue1.empty()) {
                int u = queue1.front();
                queue1.pop();
                for (int j = 0; j < edgeGraph[u].size(); ++j) {
                    int v = edgeGraph[u][j];
                    if (parts[v] != 0) {
                        graphIsBipartite = graphIsBipartite & (parts[u] != parts[v]);
                    } else {
                        parts[v] = parts[u] * (-1);
                        queue1.push(v);
                    }
                }
            }
        };
    }
    return graphIsBipartite;
}

int main() {
    cin >> n >> m;

    coord.resize(n);
    edgeGraph.resize(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges.push_back(make_pair(u, v));
    }

    for (int i = 0; i < n; ++i) {
        int cord;
        cin >> cord;
        cord--;
        coord[cord] = i;
    }

    makeEdgeGraph();

    if (!checkGraph()) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int i = 0; i < coord.size(); ++i) {
            cout << 2 * coord[i] << " " << "0" << " ";
        }
        cout << "\n";
        for (int i = 0; i < edgeGraph.size(); ++i) {
            double ans1 = (coord[edges[i].first] + coord[edges[i].second]);
            cout << ans1 << " ";
            double ans2 = abs(coord[edges[i].first] - coord[edges[i].second]) * parts[i];
            cout << ans2 << "\n";
        }
    }

}