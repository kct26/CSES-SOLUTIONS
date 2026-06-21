#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 100005;

bool visited[MAX];
int n,m,compo, component[MAX];
ll profit[MAX], final_profit[MAX], dp[MAX];
vector<int> temp, topo;
vector<vector<int>> adj, radj, fadj;
vector<pair<int,int>> edges;

void dfs1(int u){
    visited[u] = true;
    for (int &v : adj[u]){
        if (!visited[v]) dfs1(v);
    }
    temp.push_back(u);
}

void dfs2(int u){
    visited[u] = true;
    for (int &v : radj[u]){
        if (!visited[v]) {
            component[v] = component[u];
            dfs2(v);
        }
    }
}

void dfs3(int u){
    visited[u] = true;
    for (int &v : fadj[u]){
        if (!visited[v]) dfs3(v);
    }
    topo.push_back(u);

}

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    radj.resize(n + 1);
    fadj.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> profit[i];
    }
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
        edges.push_back({u,v});
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]) dfs1(i);
    }
    memset(visited, false, sizeof visited);
    for (int i = n - 1; i >= 0; i--){
        int u = temp[i];
        if (!visited[u]) {
            compo++;
            component[u] = compo;
            dfs2(u);
        }
    }
    for (int i = 1; i <= n; i++){
        dp[component[i]] += profit[i];
        final_profit[component[i]] += profit[i];
    }
    for (pair<int,int> &p : edges){
        int u = p.first;
        int v = p.second;
        if (component[u] != component[v]){
            fadj[component[u]].push_back(component[v]);
        }
    }
    memset(visited, false, sizeof visited);
    for (int i = 1; i <= compo; i++){
        if (!visited[i]) dfs3(i);
    }
    reverse(topo.begin(), topo.end());
    for (int &u : topo){
        for (int &v : fadj[u]){
           dp[v] = max(dp[v], dp[u] + final_profit[v]);
        }
    }
    ll ans = *max_element(dp, dp + compo + 1);
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