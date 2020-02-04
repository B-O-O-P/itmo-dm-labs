#include <iostream>
#include <vector>

const long long MOD = 998244353;
size_t n, m;

struct GeneratingFunc {

    GeneratingFunc() {
        size = 0;
        coefs = std::vector<long long>();
    }

    GeneratingFunc(int size) : size(size) {
        for (int i = 0; i <= size; ++i) {
            coefs.push_back(0);
        }
    }

    GeneratingFunc(GeneratingFunc& other) = default;

    GeneratingFunc(const GeneratingFunc& other) = default;

    long long getCoef(int i) const {
        if (i > size) {
            return 0;
        } else {
            return coefs[i];
        }
    }

    std::vector<long long> coefs;
    int size;
};

std::vector<GeneratingFunc> PPows;

GeneratingFunc addition(const GeneratingFunc& A, const GeneratingFunc& B) {
    GeneratingFunc res;
    res.size = std::max(A.size, B.size);

    for (int i = 0; i <= res.size; ++i) {
        long long coef = 0;
        coef = (A.getCoef(i) + B.getCoef(i)) % MOD;
        res.coefs.push_back(coef);
    }

    return res;
}

GeneratingFunc multiply(const GeneratingFunc& A, const GeneratingFunc& B) {
    GeneratingFunc res;
    res.size = A.size + B.size;
    for (int i = 0; i <= res.size; ++i) {
        long long mul = 0;
        for (int j = 0; j <= i; ++j) {
            mul = (mul + A.getCoef(j) * B.getCoef(i - j)) % MOD;
        }
        res.coefs.push_back(mul);
    }
    return res;
}

GeneratingFunc P, Q, InvQ;


int main() {
    std::cin >> n >> m;

    P.size = n;
    for (int i = 0; i <= n; ++i) {
        long long coef;
        std::cin >> coef;
        P.coefs.push_back(coef);
    }

    Q.size = m;
    for (int i = 0; i <= m; ++i) {
        long long coef;
        std::cin >> coef;
        Q.coefs.push_back(coef);
    }

    InvQ.size = 1000;
    InvQ.coefs.push_back(1 / Q.getCoef(0));
    for (int i = 1; i <= InvQ.size; ++i) {
        long long coef = 0;
        for (int j = 1; j <= i; ++j) {
            coef = (coef + Q.getCoef(j) * InvQ.getCoef(i - j) + MOD) % MOD;
        }
        InvQ.coefs.push_back((-coef / InvQ.getCoef(0) + MOD) % MOD);
    }

    GeneratingFunc PPQ = addition(P, Q);
    std::cout << PPQ.size << "\n";
    for (int i = 0; i <= PPQ.size; ++i) {
        std::cout << PPQ.getCoef(i) << " ";
    }
    std::cout << "\n";

    GeneratingFunc PQ = multiply(P, Q);
    std::cout << PQ.size << "\n";
    for (int i = 0; i <= PQ.size; ++i) {
        std::cout << PQ.getCoef(i) << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < InvQ.size; ++i) {
        long long div = 0;
        for (int j = 0; j <= i; j++) {
            div = (div + P.getCoef(j) * InvQ.getCoef(i - j)) % MOD;
        }
        std::cout << div << " ";
    }

    return 0;
}