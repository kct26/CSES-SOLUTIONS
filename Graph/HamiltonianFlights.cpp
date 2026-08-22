#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 20;
int n,m;
ll dp[1 << MAX][MAX];
vector<vector<int>> adj;

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
    }
    // base case 
    dp[1 << 0][0] = 1;
    for (int mask = 0; mask < 1 << n; mask++){
        if (!(mask & 1)) continue;
        for (int u = 0; u < n; u++){
            if (!(mask & (1 << u))) continue; 
            if (dp[mask][u] == 0) continue;
            for (int v : adj[u]){
                if (mask & (1 << v)) continue;
                int new_mask = mask | (1 << v);
                dp[new_mask][v] = (dp[new_mask][v] + dp[mask][u]) % MOD;
            } 
        }
    }
    cout << dp[(1 << n) - 1][n-1] % MOD;
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