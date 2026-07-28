#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;
 
const int MOD = 1000000007;
const int MAX = 100005;
ll dp[MAX][105], a[MAX], n, m, ans;
 
void process() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (a[0] == 0) for (int i = 1; i <= m; i++) dp[0][i] = 1;
    else dp[0][a[0]] = 1;
    for (int i = 1; i < n; i++){
        if (a[i] != 0){
            dp[i][a[i]] += (dp[i-1][a[i]-1] + dp[i-1][a[i]+1] + dp[i-1][a[i]]) % MOD;
            dp[i][a[i]] %= MOD;
        }
        else{
            for (int j = 1; j <= m; j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) ans = (ans + dp[n-1][i]) % MOD;
    cout << ans;
    
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