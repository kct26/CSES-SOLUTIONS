#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
ll dp[1 << 10][2];
ll n, m;

void process() {
    cin >> n >> m;
    dp[0][0] = 1;
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            for (int mask = 0; mask < (1 << n); mask++){
                dp[mask][1] = dp[mask ^ (1 << i)][0];
                if (i > 0 && !(mask & (1 << i)) && !(mask & (1 << (i - 1)))){
                    dp[mask][1] += dp[mask ^ (1 << (i - 1))][0];
                }
                dp[mask][1] %= MOD;
            }
            for (int mask = 0; mask < (1 << n); mask++){
                dp[mask][0] = dp[mask][1];
            }
        }
    }
    cout << dp[0][0];
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