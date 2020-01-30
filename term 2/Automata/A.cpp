#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, m, k;
int number = 1;
vector<char> s;

struct State {
    map<char, int> transitions;

};

vector<State> states;
vector<int> finalstates;

void addTransition(int transition, char c) {
    states[number].transitions.insert(pair<char, int>(c, transition));
};

bool checkString() {
    number = 1;
    int id = 0;
    while (id < s.size()) {
        map<char, int>::iterator it;
        it = states[number].transitions.find(s[id]);
        if (it != states[number].transitions.end())
            number = it->second;
        else
            return false;
        id++;
    }
    return finalstates[number] == 1;
}

void printState(vector<State> a) {
    for (int i = 1; i < a.size(); i++) {
        printf("State %d:", i);
        for (auto j = a[i].transitions.begin(); j != a[i].transitions.end(); j++) {
            printf("(%c , %d)", j->first, j->second);
        }
        printf("\n");
    }
}

int main() {
    freopen("problem1.in", "r", stdin);
    freopen("problem1.out", "w", stdout);
    int x;
    int a, b;
    char c, d;
    scanf("%c", &d);
    while (d != '\n') {
        s.push_back(d);
        scanf("%c", &d);
    }
    scanf("%d %d %d", &n, &m, &k);
    states.resize((unsigned) n + 1);
    finalstates.resize((unsigned) n + 1);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        finalstates[x] = 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %c", &a, &b, &c);
        number = a;
        addTransition(b, c);
    }
    printf("%s", checkString() ? "Accepts" : "Rejects");
    return 0;
}