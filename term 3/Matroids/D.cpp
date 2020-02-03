#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

size_t n, m;
unordered_map<int, vector<int>> sets;
bool hasEmptySet;

bool checkFirstAxiom() {
    return hasEmptySet;
};

bool checkSecondAxiom() {
    int fullSet = 1 << n;
    vector<bool> subSet(fullSet, true);

    for (int i = 0; i < fullSet; ++i) {
        subSet[i] = (sets.find(i) != sets.end());
        for (int j = 0; (1 << j) <= i; j++) {
            subSet[i] = subSet[(i & (~(1 << j)))] & subSet[i];
        }
    }
    for (auto i = sets.begin(); i != sets.end(); ++i) {
        if (!subSet[i->first]) {
            return false;
        }
    }
    return true;
}

bool checkThirdAxiom() {
    for (auto A = sets.begin(); A != sets.end(); ++A) {
        for (auto B = A; B != sets.end(); ++B) {
            if (A->second.size() != B->second.size()) {
                if (A->second.size() < B->second.size()) {
                    swap(A, B);
                }
                vector<int> BnotA(n);
                bool existsY = false;
                for (int i : A->second) {
                    BnotA[i] = true;
                }
                for (int i : B->second) {
                    BnotA[i] = false;
                }

                for (int i = 0; i < n; ++i) {
                    if (BnotA[i]) {
                        existsY = existsY | (sets.find(B->first | (1 << i)) != sets.end());
                    }
                }

                if (!existsY) {
                    return false;
                }
            }
        }
    }
    return true;

}

int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        int set = 0;
        vector<int> bitsOfSet;

        if (k == 0) {
            hasEmptySet = true;
        }

        for (int j = 0; j < k; j++) {
            int nextSet;
            cin >> nextSet;
            nextSet--;
            set = set | (1 << nextSet);
            bitsOfSet.push_back(nextSet);
        }

        sets.insert({set, bitsOfSet});
    }

    if (checkFirstAxiom() && checkSecondAxiom() && checkThirdAxiom()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}