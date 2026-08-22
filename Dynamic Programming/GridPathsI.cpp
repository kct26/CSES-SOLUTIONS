#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 1005;
int n, dp[MAX][MAX];
char a[MAX][MAX];

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    if (a[0][0] == '*' || a[n-1][n-1] == '*') {
        cout << 0;
        return;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == '*') continue;
            if (i - 1 >= 0) dp[i][j] += dp[i-1][j];
            if (j - 1 >= 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n-1][n-1];
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