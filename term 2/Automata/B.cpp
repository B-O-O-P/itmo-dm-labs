#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

int n, m, k;
vector<char> s;
unordered_set<int> curstates;

struct State {
    vector<vector<int>> transitions;
};

vector<State> states;
vector<bool> finalstates;

void addTransition(int number, int transition, char c) {
    states[number].transitions[c - 'a'].push_back(transition);
}

bool checkString() {
    for (int i = 0; i < s.size(); i++) {
        unordered_set<int> tstate;
        for (auto j = curstates.begin(); j != curstates.end(); j++) {
            for (int k = 0; k < states[*j].transitions[s[i] - 'a'].size(); k++) {
                tstate.emplace(states[*j].transitions[s[i] - 'a'][k]);
            }
        }
        curstates = tstate;
    }
    for (auto i = curstates.begin();i!=curstates.end();i++){
        if (finalstates[*i]){
            return true;
        }
    }
}

void printState() {
    for (int i = 0; i < states.size(); i++) {
        printf("State %d: ", i + 1);
        for (int j = 0; j < states[i].transitions.size(); j++) {
            for (int e = 0; e < states[i].transitions[j].size(); e++) {
                printf("(%c , %d)", j + 'a', states[i].transitions[j][e] + 1);
            }
        }
        printf("\n");
    }
}

int main() {
    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);
    curstates.emplace(0);
    int x, a, b;
    char c, d;
    scanf("%c", &d);
    while (d != '\n') {
        s.push_back(d);
        scanf("%c", &d);
    }
    scanf("%d %d %d", &n, &m, &k);
    states.resize((unsigned) n);
    finalstates.resize((unsigned) n);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        finalstates[x - 1] = true;
    }
    for (int i = 0; i < n; i++) {
        states[i].transitions.resize('z' - 'a' + 1);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %c", &a, &b, &c);
        addTransition(a - 1, b - 1, c);
    }
    //  printState();
    printf("%s", checkString() ? "Accepts" : "Rejects");
    return 0;
}