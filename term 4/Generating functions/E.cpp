#include <iostream>
#include <vector>

const long long MOD = 998244353;

size_t k, n;
std::vector<std::vector<long long>> C;

void setPositive(long long& a) {
    while (a < 0) {
        a += MOD;
    }
}

void calcC() {
    for (int n = 0; n < C.size(); ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k) {
            C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD;
            setPositive(C[n][k]);
        }
    }
}


struct GeneratingFunc {

    GeneratingFunc() {
        size = 0;
        coefs = std::vector<long long>();
    }

    GeneratingFunc(int size) : size(size) {
        for (int i = 0; i < size; ++i) {
            coefs.push_back(0);
        }
    }

    GeneratingFunc(GeneratingFunc& other) = default;

    GeneratingFunc(const GeneratingFunc& other) = default;

    long long getCoef(int i) const {
        if (i >= size) {
            return 0;
        } else {
            return coefs[i];
        }
    }

    void addCoef(long long coef) {
        coefs.push_back(coef);
        size++;
    }

    std::vector<long long> coefs;
    int size;
};

GeneratingFunc multiply(const GeneratingFunc& A, const GeneratingFunc& B) {
    GeneratingFunc res;
    res.size = A.size + B.size;
    for (int i = 0; i < res.size; ++i) {
        long long mul = 0;
        for (int j = 0; j <= i; ++j) {
            mul = (mul + A.getCoef(j) * B.getCoef(i - j)) % MOD;

            setPositive(mul);
        }
        res.coefs.push_back(mul);
    }
    return res;
}

GeneratingFunc A, B, InvB;


int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

    std::cin >> k >> n;

    C.assign(k + 1, std::vector<long long>(k + 1));
    calcC();

    int sizeA = (((k - 1) % 2 == 0) ? ((k - 1) / 2) : ((k - 1) / 2 + 1));
    int sizeB = ((k % 2 == 0) ? (k / 2) : (k / 2 + 1));

    for (int i = 0; i < sizeA; i++) {
        A.addCoef(C[k - 1 - i - 1][i] * (i % 2 == 0 ? 1 : -1));
    }

    for (int i = 0; i < sizeB; i++) {
        B.addCoef(C[k - i - 1][i] * (i % 2 == 0 ? 1 : -1));
    }

    //finding ratio
    //InvB
    InvB.addCoef(1 / B.getCoef(0));

    for (int i = 1; i <= n; i++) {
        long long coef = 0;
        for (int j = 1; j <= i; j++) {
            coef = (coef + B.getCoef(j) * InvB.getCoef(i - j)) % MOD;
            while (coef < 0)
                coef += MOD;
        }
        InvB.addCoef((-coef / InvB.getCoef(0) + MOD) % MOD);

        setPositive(InvB.coefs[InvB.size - 1]);
    }

    //A * InvB
    GeneratingFunc res = multiply(A, InvB);

    for (int i = 0; i < n; ++i) {
        std::cout << res.coefs[i] << "\n";
    }
}