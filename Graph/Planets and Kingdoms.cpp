#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 100005;
vector<vector<int>> adj, radj;
int kingdom[MAX];
int n, m, compo;
bool visited[MAX];
vector<int> temp;

void dfs1(int u){
    visited[u] = true;
    for (int &v : adj[u]){
        if (!visited[v]) dfs1(v);
    }
    temp.push_back(u);
}

void dfs2(int u, int src){
    visited[u] = true;
    for (int &v : radj[u]){
        if (!visited[v]) {
            dfs2(v,src);
        }
    }
    kingdom[u] = src;
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
        if (!visited[i]) dfs1(i);
    }
    memset(visited, false, sizeof visited);
    for (int i = (int) temp.size() - 1; i >= 0; i--){
        int u = temp[i];
        if (!visited[u]) {
            compo++;
            kingdom[u] = compo;
            dfs2(u,compo);
        }
    }
    cout << compo << "\n";
    for (int i = 1; i <= n; i++){
        cout << kingdom[i] << " ";
    }
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