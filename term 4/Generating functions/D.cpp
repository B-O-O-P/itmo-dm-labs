#include <iostream>
#include <vector>

const int SIZE = 7;
std::string input;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

long long coef(long long n, long long k) {
    long long res = 1;
    for (long long i = n - k + 1; i <= n; ++i) {
        res *= i;
    }
    for (long long j = 2; j <= k; ++j) {
        res /= j;
    }
    return res;
}

size_t pos = 0;

std::vector<long long> parseObject() {
    std::vector<long long> left, right;
    std::vector<long long> result(SIZE);

    char current = input[pos];

    switch (current) {
        case 'B': {
            for (int i = 0; i < result.size(); ++i) {
                if (i != 1) {
                    result[i] = 0;
                } else {
                    result[i] = 1;
                }
            }
            pos++;
            break;
        }
        case 'L': {
            pos += 2;
            left = parseObject();
            pos++;
            result[0] = 1;

            for (int i = 1; i < SIZE; ++i) {
                long long sum = 0;
                for (int j = 1; j <= i; ++j) {
                    sum += left[j] * result[i - j];
                }
                result[i] = sum;
            }
            break;
        }
        case 'S': {
            pos += 2;
            left = parseObject();
            pos++;

            std::vector<std::vector<long long>> matrix(SIZE, std::vector<long long>(SIZE));
            matrix[0][0] = 1;

            for (int i = 1; i < matrix.size(); i++) {
                matrix[0][i] = 1;
                matrix[i][0] = 0;
            }

            result[0] = 1;
            for (int i = 1; i < SIZE; ++i) {
                for (int j = 1; j < SIZE; ++j) {
                    long long sum = 0;
                    for (int k = 0; k <= i / j; ++k) {
                        long long maxx = std::max(left[j] + k - 1, 0LL);
                        sum += coef(maxx, k) * matrix[i - k * j][j - 1];
                    }
                    matrix[i][j] = sum;
                }
                result[i] = matrix[i][i];
            }

            break;
        }

        case 'C': {
            pos += 2;
            left = parseObject();
            pos++;

            std::vector<std::vector<long long>> c(SIZE, std::vector<long long>(SIZE));
            for (int i = 0; i < SIZE; ++i) {
                c[i][1] = left[i];
                c[i][0] = 0;
                c[0][i] = 0;
            }

            for (int i = 1; i < SIZE; ++i) {
                for (int j = 2; j < SIZE; ++j) {
                    long long sum = 0;
                    for (int k = 1; k < i; ++k) {
                        sum += left[k] * c[i - k][j - 1];
                    }
                    c[i][j] = sum;
                }
            }

            result[0] = 0;

            for (int i = 1; i < SIZE; ++i) {
                long long sum = 0;
                for (int j = 1; j <= i; ++j) {
                    long long push = 0;
                    for (int k = 0; k <= j - 1; ++k) {
                        int g = gcd(j, k);
                        long long s = (i % (j / g)) != 0 ? 0 : c[(i * g) / j][g];
                        push += s;
                    }
                    sum += push / j;
                }
                result[i] = sum;
            }
            break;
        }
        case 'P': {
            pos += 2;
            left = parseObject();
            pos++;
            right = parseObject();
            pos++;
            for (int i = 0; i < SIZE; ++i) {
                long long sum = 0;
                for (int j = 0; j <= i; ++j) {
                    sum += left[j] * right[i - j];
                }

                result[i] = sum;
            }
            break;
        }
        default:
            break;
    }

    return result;
}

int main() {
    std::getline(std::cin, input);
    std::vector<long long> result = parseObject();

    for (long long i : result) {
        std::cout << i << " ";
    }
    return 0;
}