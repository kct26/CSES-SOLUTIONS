#include <bits/stdc++.h>
using namespace std;
using int = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 1000005;
int n, x, a[MAX], dp[105][MAX];

void process() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= x; i += a[0]) dp[0][i] = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if (j - a[i] >= 0) dp[i][j] += dp[i][j-a[i]];
            dp[i][j] %= MOD;
        }
    }    
    cout << dp[n-1][x];
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