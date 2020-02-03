#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Task {
    int d, w;
};
int n;
vector<Task> tasks;
set<int> time;

bool compare(const Task& first, const Task& second) {
    return first.w > second.w;
}

int main() {
    freopen("schedule.in", "r", stdin);
    freopen("schedule.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int d, w;
        cin >> d >> w;
        tasks.push_back({d, w});
    }
    for (int i = 0; i < n; ++i) {
        time.insert(i + 1);
    }
    sort(tasks.begin(), tasks.end(), compare);

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int deadline = tasks[i].d;
        auto tmp = time.lower_bound(deadline);
        tmp--;
        if (tmp == time.end()) {
            time.erase(time.end());
        } else {
            time.erase(tmp);
            res += tasks[i].w;
        }
    }
    cout << res;

    return 0;
}