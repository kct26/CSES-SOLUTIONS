#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 100005;
int n,m,par[MAX];
bool visited[MAX];
vector<vector<int>> adj;
vector<int> ans;

bool dfs(int u){
    visited[u] = true;
    for (int &v : adj[u]){
        if (v == par[u]) continue;
        if (visited[v]){
            ans.push_back(v);
            while (u != v){
                ans.push_back(u);
                u = par[u];
            }
            ans.push_back(u);
            return true;
        }
        par[v] = u;
        if (dfs(v)) return true;
    }
    return false;
}

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i] && dfs(i)){
            cout << (int) ans.size() << "\n";
            for (int& u : ans) cout << u << " ";
            return;
        }
    }
    cout << "IMPOSSIBLE";
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