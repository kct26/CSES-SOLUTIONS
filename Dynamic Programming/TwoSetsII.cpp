#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 505;
ll dp[MAX][125251], n;

void process() {
    cin >> n;
    ll target = n * (n + 1) / 2;
    if (target % 2 != 0) {
        cout << 0;
        return;
    }
    target /= 2;
    dp[0][0] = 1;
    for (ll i = 1; i <= n - 1; i++){
        for (ll j = 0; j <= target; j++){
            dp[i][j] = dp[i-1][j];
            if (j - i >= 0) dp[i][j] += dp[i-1][j - i];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n - 1][target];
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