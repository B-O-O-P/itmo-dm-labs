#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> automata[26][26];
size_t n, m;
char start;

bool isNonTerminal(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool findd(vector<char> &a, char x) {
    auto res = find(a.begin(), a.end(), x);
    return res != a.end();
}

bool checkString(string s, char state = start, int number = 0) {
    if (number < s.size() - 1) {
        if (state == '0')return false;
        if (!automata[state - 'A'][s[number] - 'a'].empty()) {
            bool res = false;
            for (int i = 0; i < automata[state - 'A'][s[number] - 'a'].size(); i++) {
                res = res || checkString(s, automata[state - 'A'][s[number] - 'a'][i], number + 1);
            }
            return res;
        } else return false;
    } else return findd(automata[state-'A'][s[number]-'a'],'0');
}

int main() {
    freopen("automaton.in", "r", stdin);
    freopen("automaton.out", "w", stdout);
    scanf("%d %c\n", &n, &start);
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);
        if (input.size() > 6) {
            automata[input[0] - 'A'][input[5] - 'a'].push_back(input[6]);
        } else {
            automata[input[0] - 'A'][input[5] - 'a'].push_back('0');
        }
    }
    scanf("%d", &m);
    string x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        printf("%s\n", checkString(x) ? "yes" : "no");
    }
    return 0;
}