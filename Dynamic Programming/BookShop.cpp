#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 1005;
int n, x, dp[MAX][100005], a[MAX], b[MAX];

void process() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 1; i <= x; i++){
        if (i >= a[0]) dp[0][i] = b[0];
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if (a[i] <= j) dp[i][j] = max(dp[i][j], dp[i-1][j - a[i]] + b[i]);
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