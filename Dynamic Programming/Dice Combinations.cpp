#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const ll MOD = 1000000007;
const int MAX = 1000005;
int n;
ll dp[MAX];


void process() {
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            if (i - j >= 0) {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n];
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