#include <iostream>
#include <vector>

const long long MOD = 1000000007;

size_t k, m;

struct GeneratingFunc {
    long long getCoef(int i) {
        if (i > size) {
            return 0;
        } else {
            return coefs[i];
        }
    }

    std::vector<long long> coefs;
    int size;
};

GeneratingFunc trees;
std::vector<char> nodes;

int main() {
    std::cin >> k >> m;

    nodes = std::vector<char>(m + 1, false);
    trees.size = m + 1;
    trees.coefs = std::vector<long long>(trees.size);

    for (int i = 0; i < k; ++i) {
        int node;
        std::cin >> node;
        nodes[node] = 1;
    }

    trees.coefs[0] = 1;
    std::vector<long long> pref(m + 1);
    pref[0] = 1;

    for (int i = 1; i < trees.size; ++i) {
        long long sum = 0;
        for (int j = 1; j <= i; ++j) {
            if (nodes[j]) {
                sum += pref[i - j] % MOD;
            }
        }
        trees.coefs[i] = sum % MOD;

        for (int j = 0; j <= i; ++j) {
            pref[i] = (pref[i] + trees.coefs[j] * trees.coefs[i - j]) % MOD;
        }

        std::cout << trees.coefs[i] << " ";
    }
    return 0;
}