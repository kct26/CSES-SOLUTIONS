#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 100005;
int n,m;
vector<vector<int>> adj;
vector<int> topo;
bool visited[MAX],path[MAX];

bool dfs(int u){
    visited[u] = true;
    path[u] = true;
    for (int &v : adj[u]){
        if (path[v]) return false;
        if (visited[v]) continue;
        bool valid = dfs(v);
        if (!valid) return false;
    }
    topo.push_back(u);
    path[u] = false;
    return true;
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
        if (!visited[i]){
            bool check = dfs(i);
            if (!check){
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }
    reverse(topo.begin(), topo.end());
    for (int &course : topo) cout << course << " ";
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