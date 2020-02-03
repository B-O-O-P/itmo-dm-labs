#include<string>
#include <vector>
#include <iostream>

using namespace std;

int n;
vector<vector<int>> graph;

bool notFound(int w, int u) {
    for (auto g : graph[u]) {
        if (g == w) {
            return false;
        }
    }
    return true;
}

bool checkPlanarity() {
    if (graph.size() < 5)
        return true;
    else if (graph.size() == 5) {
        for (int i = 0; i < 5; i++) {
            if (graph[i].size() != 4)
                return true;
        }
        return false;
    } else {
        int count1 = 0;
        for (int i = 0; i < 6; ++i) {
            count1 = 0;
            for (int j = 0; j < 6; ++j) {
                int num = 0;
                if (j != i) {
                    for (auto v : graph[j]) {
                        if (v != i)
                            num++;
                    }
                    if (num > 3)
                        count1++;
                }
            }
            if (count1 > 4)
                return false;
        }

        vector<vector<int>> homoK33(6, vector<int>(6, 0));
        for (int i = 0; i < 6; i++) {
            for (auto v : graph[i]) {
                homoK33[i][v] = 1;
                homoK33[v][i] = 1;
            }
        }

        int count2 = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = i + 1; j < 6; j++) {
                for (int k = j + 1; k < 6; k++) {
                    count2 = 0;
                    for (int t = 0; t < 6; t++) {
                        if (homoK33[i][t] && homoK33[j][t] && homoK33[k][t]) {
                            count2++;
                        }
                    }
                    if (count2 > 2)
                        return false;
                }
            }
        }

        int count3 = 0;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                for (int k = j + 1; k < graph[i].size(); ++k) {
                    int u = graph[i][j];
                    int w = graph[i][k];
                    if (notFound(u, w)) {
                        count3 = 0;
                        for (int e = 0; e < 6; e++) {
                            if (e != i) {
                                int num = 0;
                                if (e == w || e == u)
                                    num++;
                                for (auto v : graph[e]) {
                                    if (v != i) {
                                        num++;
                                    }
                                }
                                if (num > 3) count3++;
                            }
                        }
                        if (count3 > 4) return false;
                    }
                }
            }
        }
        return true;
    }
}


int main() {
    freopen("planaritycheck.in", "r", stdin);
    freopen("planaritycheck.out", "w", stdout);
    cin >> n;
    cin.get();
    string g;

    for (int i = 0; i < n; i++) {
        char c[255];
        cin.getline(c, 255);
        g = c;
        int m = 1;
        while (m * (m - 1) / 2 != g.length()) {
            m++;
        }
        if (m < 5) {
            cout << "YES" << endl;
        } else {
            graph = vector<vector<int>>(m);
            int index = 0;
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < j; ++k) {
                    if (g[index] == '1') {
                        graph[j].push_back(k);
                        graph[k].push_back(j);
                    }
                    index++;
                }
            }
            cout << (checkPlanarity() ? "YES" : "NO") << endl;
        }

    }
}