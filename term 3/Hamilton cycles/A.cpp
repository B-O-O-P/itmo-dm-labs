#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<vector<bool>> graph;

void reverseSubQueue(deque<int>& queue, int v, int i) {
    for (int j = 0; v + j < i - j; ++j) {
        int temp = queue[v + j];
        queue[v + j] = queue[i - j];
        queue[i - j] = temp;
    }
}

void findHamiltonianCycle() {
    deque<int> queue;

    for (int i = 0; i < n; ++i) {
        queue.push_back(i);
    }

    for (int i = 0; i < n * (n - 1); ++i) {
        int first = queue[0];
        int second = queue[1];
        if (!graph[first][second]) {
            i = 2;
            while (!graph[first][queue[i]] || !graph[second][queue[i + 1]]) {
                i++;
            }
            reverseSubQueue(queue, 1, i);
        }
        queue.push_back(queue.front());
        queue.pop_front();
    }
    while (!queue.empty()) {
        cout << queue.front() + 1 << " ";
        queue.pop_front();
    }
}


int main() {
    freopen("fullham.in", "r", stdin);
    freopen("fullham.out", "w", stdout);
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; ++i) {
        graph[i].resize(n);
    }

    for (int i = 1; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0, k = 0; j < i; ++j, ++k) {
            graph[i][j] = (s[k] == '1');
            graph[j][i] = graph[i][j];
        }
    }

    findHamiltonianCycle();
    return 0;
}