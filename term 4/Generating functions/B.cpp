#include <iostream>
#include <vector>

const long long MOD = 998244353LL;
const int SIZE = 101;

size_t n, m;

std::vector<long long> expCoefs;
std::vector<long long> logCoefs;
std::vector<long long> sqrtCoefs;

long long gcdex(long long a, long long b, long long& x, long long& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcdex(b % a, a, x1, y1);
    x = (y1 - ((b / a) * x1));
    y = x1;
    return d;
}

long long reverseElement(long long a, long long M) {
    long long x, y, d;
    d = gcdex(a, M, x, y);
    if (d != 1) {
        return 1;
    } else {
        return (x % M + M) % M;

    }
}

long long getInversed(long long a) {
    return reverseElement(a, MOD);
}


void calcExpCoefs() {
    expCoefs.resize(SIZE + 1);
    expCoefs[0] = 1;

    for (int i = 1; i <= 100; i++) {
        expCoefs[i] = expCoefs[i - 1];
        expCoefs[i] *= getInversed(i);
        expCoefs[i] %= MOD;
    }
}

void calcLogCoefs() {
    logCoefs.resize(SIZE + 1);
    logCoefs[1] = 1;
    for (int i = 2; i <= 100; i++) {
        logCoefs[i] = -logCoefs[i - 1] + MOD;
        logCoefs[i] %= MOD;
        logCoefs[i] *= (i - 1);
        logCoefs[i] %= MOD;
        logCoefs[i] *= getInversed(i);
        logCoefs[i] %= MOD;
    }
}

void calcSqrtCoefs() {
    sqrtCoefs.resize(SIZE + 1);
    sqrtCoefs[0] = 1;

    for (int i = 1; i <= 100; i++) {
        sqrtCoefs[i] = -sqrtCoefs[i - 1] + MOD;
        sqrtCoefs[i] %= MOD;
        sqrtCoefs[i] *= ((2 * i - 1) * (2 * i) * (3 - 2 * i) + MOD) % MOD;
        sqrtCoefs[i] %= MOD;
        sqrtCoefs[i] *= getInversed((i * i * 4 * (1 - 2 * i) + MOD) % MOD);
        sqrtCoefs[i] %= MOD;
    }
}


std::vector<std::vector<long long>> PPows;


std::vector<long long> multiply(const std::vector<long long>& A, const std::vector<long long>& B) {
    std::vector<long long> res(SIZE);
    for (int i = 0; i < res.size(); ++i) {
        long long mul = 0;
        for (int j = 0; j <= i; ++j) {
            mul = (mul + (A[j] * B[i - j] % MOD)) % MOD;
        }
        res[i] = mul;
    }
    return res;
}

void calcPow(const std::vector<long long>& A) {
    for (int i = 2; i <= 100; ++i) {
        PPows.push_back(multiply(A, PPows[i - 1]));
    }
}

void exp(int size) {

    for (int i = 0; i < size; ++i) {
        long long coef = 0;
        for (int j = 0; j < size; ++j) {
            long long coefJI = expCoefs[j] * PPows[j][i];
            coefJI %= MOD;
            coef += coefJI;
            coef %= MOD;
        }
        std::cout << coef << " ";
    }
}

void log(int size) {

    for (int i = 0; i < size; ++i) {
        long long coef = 0;
        for (int j = 0; j < size; ++j) {
            long long coefJI = logCoefs[j] * PPows[j][i];
            coefJI %= MOD;
            coef += coefJI;
            coef %= MOD;
        }
        std::cout << coef << " ";
    }
}

void sqrt(int size) {

    for (int i = 0; i < size; ++i) {
        long long coef = 0;
        for (int j = 0; j < size; ++j) {
            long long coefJI = sqrtCoefs[j] * PPows[j][i];
            coefJI %= MOD;
            coef += coefJI;
            coef %= MOD;
        }
        std::cout << coef << " ";
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    std::cin >> n >> m;
    calcExpCoefs();
    calcLogCoefs();
    calcSqrtCoefs();

    std::vector<long long> P(SIZE);
    std::vector<long long> E(SIZE);
    E[0] = 1;

    for (int i = 0; i <= n; ++i) {
        long long coef;
        std::cin >> coef;
        P[i] = coef;
    }


    PPows.push_back(E);
    PPows.push_back(P);
    calcPow(P);

    sqrt(m);
    std::cout << "\n";

    exp(m);
    std::cout << "\n";

    log(m);
    std::cout << "\n";

    return 0;
}