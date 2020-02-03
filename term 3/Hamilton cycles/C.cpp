#include <iostream>
#include <algorithm>
#include <list>


using namespace std;

int n;
list<int> lamps;

bool compareLamps(int i, int j) {
    cout << 1 << " " << i << " " << j << "\n";
    string answer;
    cin >> answer;
    return (answer[0] == 'Y');
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        lamps.push_back(i + 1);

    }
    lamps.sort(compareLamps);
    cout << 0 << " ";
    while (!lamps.empty()) {
        cout << lamps.front() << " ";
        lamps.pop_front();
    }
    return 0;
}