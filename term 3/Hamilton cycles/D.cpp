#include <iostream>
#include <vector>


using namespace std;


int n;
vector<vector<bool>> graph;
vector<int> path, cycle;


void getHamPath() {
    for (int i = 0; i < n; ++i) {
        if (path.empty()) {
            path.push_back(i);
        } else {
            auto item = path.begin();
            while (item != path.end() && graph[*item][i]) {
                ++item;
            }
            path.insert(item, i);
        }
    }
}

void getHamCycle() {
    int st = path[0];
    int pos = 0;
    for (int i = path.size() - 1; i >= 2; --i) {
        if (graph[path[i]][st]) {
            pos = i;
            break;
        }
    }
    cycle.insert(cycle.begin(), path.begin(), path.begin() + pos + 1);
    path.erase(path.begin(), path.begin() + pos + 1);
}

void PathIntoCycle() {
    for (auto st = path.begin(); st != path.end();) {
        auto item = cycle.begin();
        while (item != cycle.end() && graph[*item][*st]) {
            item++;
        }
        if (item != cycle.end()) {
            cycle.insert(item, path.begin(), st + 1);
            path.erase(path.begin(), st + 1);
            st = path.begin();
        } else {
            st++;
        }
    }
}


int main() {
    freopen("guyaury.in", "r", stdin);
    freopen("guyaury.out", "w", stdout);
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; ++i) {
        graph[i].resize(n);
    }

    for (int i = 1; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0, k = 0; j < i; ++j, ++k) {
            if (s[k] == '1') {
                graph[i][j] = true;
            } else {
                graph[j][i] = true;
            }
        }
    }

    getHamPath();
    getHamCycle();
    PathIntoCycle();
    for (int i = 0; i < cycle.size(); i++) {
        cout << cycle[i] + 1 << " ";
    }
    return 0;
}