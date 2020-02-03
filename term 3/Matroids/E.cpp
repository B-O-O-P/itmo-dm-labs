#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

size_t n, m;
vector<bool> S;
vector<pair<int, int>> weights;
queue<int> bases;

bool compare(const pair<int,int>& first, const pair<int,int>& second){
    return first.first > second.first;
}

void computeBases() {
    while (!bases.empty()) {
        int current = bases.front();
        bases.pop();
        for (int i = 0; i < n; ++i) {
            if ((current & (1 << i)) == 0) {
                current = current | (1 << i);
                if (!S[current]) {
                    S[current] = !S[current];
                    bases.push(current);
                }
                current &= ~(1 << i);
            }
        }
    }
}

int main() {
    freopen("cycles.in", "r", stdin);
    freopen("cycles.out", "w", stdout);
    cin >> n >> m;
    S.assign((unsigned) 1 << n, false);
    weights.resize(n);

    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        weights[i] = {w, i};
    }

    for (int i = 0; i < m; ++i) {
        int cur = 0;
        int size;

        cin >> size;
        for (int j = 0; j < size; ++j) {
            int s;
            cin >> s;
            s--;
            cur = cur | (1 << s);
        }
        S[cur] = true;
        bases.push(cur);
    }

    computeBases();
    sort(weights.begin(), weights.end(), compare);

    long long cur = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        if (!S[cur | (1 << weights[i].second)]) {
            cur = cur | (1 << weights[i].second);
            res = res + weights[i].first;
        }
    }
    cout << res;
    return 0;
}