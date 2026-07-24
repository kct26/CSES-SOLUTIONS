#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 1000005;
const ll INF = 4e18;
ll dp[MAX], a[MAX], n , k;

void process() {
    cin >> n >> k;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }
    dp[0] = 1;
    for (int i = 1; i <= k; i++){
        for (int j = 0; j < n; j++){
            if (i - a[j] >= 0) dp[i] = min(dp[i], dp[i - a[j]] + 1); 
        }
    }
    cout << (dp[k] >= INF ? -1 : dp[k]);
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