#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 100005;
int n,m,dp[MAX],par[MAX];
vector<vector<int>> adj;
vector<int> topo, ans;
bool visited[MAX];

void dfs(int u){
    visited[u] = true;
    for (int &v : adj[u]){
        if (visited[v]) continue;
        dfs(v);
    }
    topo.push_back(u);
    return;
}

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());
    dp[1] = 1;
    for (int &u : topo){
        if (dp[u] == 0) continue;
        for (int &v : adj[u]){
            if (dp[v] < dp[u] + 1){
                par[v] = u;
                dp[v] = dp[u] + 1;
            }
        }
    }
    if (dp[n] == 0) {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << dp[n] << "\n";
    int cur = n;
    while (cur != 1) {
        ans.push_back(cur);
        cur = par[cur];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for (int &v : ans) cout << v << " ";
    return;

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