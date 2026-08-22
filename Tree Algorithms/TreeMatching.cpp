#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 200005;
bool visited[MAX];
int par[MAX], n, cnt;
vector<vector<int>> adj;

void dfs(int u, int par){
    if (adj[u].size() == 0) return;
    for (int &v : adj[u]){
        if (v == par) continue;
        dfs(v,u);
    }
    if (u == 1) return;
    if (!visited[u] && !visited[par]) {
        cnt++;
        visited[u] = true;
        visited[par] = true;
    }
}

void process() {
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1] = 1;
    dfs(1,1);
    cout << cnt;
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