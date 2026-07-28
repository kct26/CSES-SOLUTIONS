#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 5005;
int dp[MAX][MAX];
string m,n;

void process() {
    cin >> m >> n;
    int r = (int) m.size();
    int c = (int) n.size();
    for (int i = 0; i <= c; i++) dp[0][i] = i;
    for (int i = 0; i <= r; i++) dp[i][0] = i;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            if (m[i-1] == n[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min ({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    cout << dp[r][c];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    // cin >> test;
    while (test--) {
        process();
    }
    return 0;
}