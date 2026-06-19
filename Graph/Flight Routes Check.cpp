#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;
 
const int MOD = 1000000007;
const int MAX = 100005;
int n,m;
vector<vector<int>> adj, radj;
bool visited[MAX];
vector<int> fi,se;
 
void dfs(int u, vector<vector<int>> &a, vector<int> &ans){
    visited[u] = true;
    for (int &v : a[u]){
        if (!visited[v]) dfs(v, a, ans);
    }
    ans.push_back(u);
}
 
void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    radj.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]) dfs (i, adj, fi);
    }
    memset(visited, false, sizeof visited);
    for (int i  = (int)fi.size() - 1; i >= 0; i--){
        int u = fi[i];
        if (!visited[u]) {
            dfs(u, radj, se);
            for (int i = 1; i <= n; i++){
                if (!visited[i]){
                    cout << "NO \n";
                    cout << i << " " << u;
                    return;
                }
            }
        }
    }
    cout << "YES";
 
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