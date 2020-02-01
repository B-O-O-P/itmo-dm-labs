#include <iostream>
#include <vector>

/*
........................................................
.........................(@@@&,.........................
.....................#@@@@@@@@@@@@*.....................
.................&@@@@@@@@@@@@@@@@@@@@(.................
............,&@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.............
........*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&.........
......@@@@@  &@@@&  @@@@@@@@@@@@@@@# ,@@@@, %@@@@#......
......@@@@@@@.    *@@@@@@@@@@@@@@@@@&     #@@@@@@&......
......@@@@@%        @@@@@@@@@@@@@@@(        @@@@@&......
......@@@@@         .@@@@@@@@@@@@@@         ,@@@@&......
......@( ,%          % .@@@@@@@@  &          @  @&......
......@@@@@         /@@@@@@@@@@@@@@         .@@@@&......
......@@@@@*       ,@@@@@@@@@@@@@@@@        @@@@@&......
......@@@@@@@     &@@@@@@@@@@@@@@@@@@(    ,@@@@@@&......
......@@@@@/ #@@@&  @@@@@@@@@@@@@@@( .@@@@  @@@@@%......
.......*@@@@@@@@@@@@@@@@@#    @@@@@@@@@@@@@@@@@%........
...........,@* .@@@@@@@@@@@@@@@@@@@@@@@%  @#............
................@@@@%@@@@@@@@@@@@@&@@@@#................
................@@@@ %@@@ @@@&*@@@.(@@@(................
.................../ %@@@ @@@(,@@@.,,...................
.......................(& @@@(.&........................
........................................................
 */

using namespace std;

const int MOD = 1000000007;
size_t n;
char start;
vector<vector<vector<long long>>> dp(26);
vector<pair<char, string>> strs;
vector<pair<char, char>> l;

void dpBuild(string &x) {
    for (int i = 0; i < 26; i++) {
        dp[i].resize(x.size());
        for (int j = 0; j < x.size(); j++) {
            dp[i][j].resize(x.size());
        }
    }

    for (int i = 0; i < x.size(); i++) {
        for (auto j = l.begin(); j != l.end(); j++) {
            if (j->second == x[i]) {
                char xx = j->first - 'A';
                dp[xx][i][i] = true;
            }
        }
    }

    for (int i = 1; i < x.size(); i++) {
        for (int j = 0; j < x.size() - i; j++) {
            for (auto k = strs.begin(); k != strs.end(); k++) {
                for (int l = 0; l < i; l++) {
                    char fir = k->first - 'A';
                    char sec0 = k->second[0] - 'A';
                    char sec1 = k->second[1] - 'A';
                    dp[fir][j][j + i] = (dp[fir][j][j + i] +
                                         dp[sec0][j][j + l] *
                                         dp[sec1][j + l + 1][j + i]) % MOD;
                }
            }
        }
    }
}

int main() {
    freopen("nfc.in", "r", stdin);
    freopen("nfc.out", "w", stdout);
    cin >> n >> start;
    start -= 'A';

    for (int i = 0; i < n; i++) {
        char from;
        string to, useless;
        cin >> from >> useless >> to;
        if (to.size() == 2) {
            strs.emplace_back(make_pair(from, to));
        } else l.emplace_back(make_pair(from, to[0]));
    }
    string x;
    cin >> x;
    dpBuild(x);
    cout << dp[start][0][x.size() - 1] % MOD;
    return 0;
}