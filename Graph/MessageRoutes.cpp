#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 100005;
int n,m,step;
bool visited[MAX];
int par[MAX];
vector<vector<int>> adj;

bool bfs(int u){
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int sz = (int) q.size();
        for (int i = 0; i < sz; i++){
            int current = q.front();
            q.pop();
            if (current == n) {
                return true;
            }
            for (int &v : adj[current]){
                if (!visited[v]) {
                    q.push(v);
                    par[v] = current;
                    visited[v] = true;
                }
            }
        }
        step++;
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
    bool valid = bfs(1);
    if (!valid) cout << "IMPOSSIBLE";
    else{
        cout << step + 1 << "\n";
        vector<int> ans;
        while (n != 1){
            ans.push_back(n);
            n = par[n];
        }
        ans.push_back(1);
        for (int i = (int) ans.size() - 1; i >= 0; i--){
            cout << ans[i] << " ";
        }
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