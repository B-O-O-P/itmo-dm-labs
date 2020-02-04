#include <iostream>
#include <vector>

const long long MOD = 104857601;

size_t k;
long long n;
std::vector<long long> A;
std::vector<long long> Q;

void getNegative(std::vector<long long>& Q, std::vector<long long>& negativeQ) {
    for (int i = 0; i < Q.size(); ++i) {
        negativeQ[i] = (i % 2 == 0 ? Q[i] : (-Q[i] + MOD) % MOD);
    }
}

void filter(std::vector<long long>& A) {
    int freeI = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (i % 2 == n % 2) {
            A[freeI] = A[i];
            freeI++;
        }
    }
}

long long getNth(std::vector<long long>& A, std::vector<long long>& Q) {
    std::vector<long long> R(k + 1);
    std::vector<long long> negativeQ(k + 1);

    while (n >= k) {
        for (int i = k; i < A.size(); ++i) {
            A[i] = 0;
            for (int j = 1; j < Q.size(); ++j) {
                A[i] = (A[i] - Q[j] * A[i - j]) % MOD;

                while (A[i] < 0) {
                    A[i] += MOD;
                }
            }
        }

        getNegative(Q, negativeQ);

        for (int i = 0; i <= 2 * k; i += 2) {
            long long coefR = 0;
            for (int j = 0; j <= i; ++j) {
                long long qq = (j > k ? 0 : Q[j]);
                long long neq = (i - j > k ? 0 : negativeQ[i - j]);

                coefR = (coefR + qq * neq + MOD) % MOD;
            }
            R[i / 2] = coefR;
        }

        Q = R;
        filter(A);

        n = n / 2;
    }
    return A[n];
}

int main() {
    //freopen("test.in", "R", stdin);
    //freopen("test.out", "w", stdout);
    std::cin >> k >> n;
    n--;

    A.resize(2 * k);
    Q.resize(k + 1);

    for (int i = 0; i < A.size() / 2; ++i) {
        long long a;
        std::cin >> a;
        A[i] = a;
    }

    Q[0] = 1;
    for (int i = 1; i < Q.size(); ++i) {
        long long c;
        std::cin >> c;
        Q[i] = (-c + MOD);
        Q[i] %= MOD;
    }

    std::cout << getNth(A, Q);
    return 0;
}