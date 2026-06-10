#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 100005;
int n,m;
int inDegree[MAX], visited[MAX], par[MAX];
vector<vector<int>> adj;
vector<int> ans;

bool dfs(int u){
    visited[u] = 1;
    for (int &v : adj[u]){
        if (visited[v] == 2) continue;
        if (visited[v] == 1){
            ans.push_back(v);
            int cur = u;
            while (cur != v){
                ans.push_back(cur);
                cur = par[cur];
            }
            ans.push_back(v);
            reverse(ans.begin(), ans.end());
            return true;
        }
        par[v] = u;
        bool check = dfs(v);
        if (check) return true;
    }
    visited[u] = 2;
    return false;
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
        if (visited[i] == 2) continue;
        bool valid = dfs(i);
        if (valid) {
            cout << (int) ans.size() << "\n";
            for (int &a : ans) cout << a << " ";
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