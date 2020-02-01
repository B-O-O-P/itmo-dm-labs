#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> products;
bool eps[161];
size_t n;
char start;

void countEps() {
    bool checked = true;
    while (checked) {
        checked = false;
        for (int i = 0; i < products.size(); i++) {
            bool res = products[i].size() >= 5 && !eps[products[i][0]];
            for (int j = 5; j < products[i].size() && !eps[products[i][0]]; j++) {
                res = res & eps[products[i][j]];
                if (!res)
                    break;
            }
            if (res)
                eps[products[i][0]] = true;
            checked = checked | res;
        }
    }
}

int main() {
    freopen("epsilon.in", "r", stdin);
    freopen("epsilon.out", "w", stdout);
    scanf("%d %c\n", &n, &start);
    string input;
    for (int i = 0; i < n; i++) {
        string s;
        products.push_back(s);
        getline(cin, input);
        products.push_back(input);
        if (input.size() == 4)
            eps[input[0]] = true;
    }
    countEps();
    for (int i = 45; i < 92; i++) {
        if (eps[i])
            printf("%c ", i);
    }
    return 0;
}

/*#include<vector>
#include<string>
#include<iostream>


std::vector<std::string> rules;

bool svalka[160];

int main() {
    std::freopen("epsilon.in", "r", stdin);
    std::freopen("epsilon.out", "w", stdout);
    for (int i = 0; i < 160; ++i)
        svalka[i] = 0;
    int n;
    char s;
    scanf("%d %c\n", &n, &s);
    char str_prev[256];
    for (int i = 0; i < n; ++i) {
        std::string s;
        rules.push_back(s);
        scanf("%255[^\n]\n", &str_prev);
        for (int j = 0; str_prev[j] != '\0' && j < 256; ++j)
            rules.back().push_back(str_prev[j]);
        if (rules.back().size() == 4)
            svalka[(int) str_prev[0]] = 1;
    }
    bool flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i < rules.size(); ++i) {
            bool result = rules[i].size() >= 5 && !svalka[(int) rules[i][0]];
            for (int j = 5; j < rules[i].size() && !svalka[(int) rules[i][0]]; ++j) {
                result = result & svalka[(int) rules[i][j]];
                if (!result)
                    break;
            }
            if (result)
                svalka[(int) rules[i][0]] = 1;
            flag = flag | result;
        }
    }
    for (int i = 45; i < 92; ++i) {
        if (svalka[i]) {
            printf("%c ", i);
        }
    }
    return 0;
}*/