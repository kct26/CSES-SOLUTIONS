#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007


const int MAX = 2 * (int) 1e5 + 5;
int n;
bool visited[MAX];
int par[MAX];
vector<vector<int>> adj;
vector<int> topo;

void process() {
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    visited[1] = true;
    par[1] = 1;
    q.push(1);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for (int &v : adj[cur]){
            if (!visited[v]){
                q.push(v);
                visited[v] = true;
                par[v] = cur;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    int ans = 0;
    for (int i = (int) topo.size() - 1; i >= 0; i--){
        if (topo[i] == 1) continue;
        if (!visited[topo[i]] && !visited[par[topo[i]]]){
            ans++;
            visited[topo[i]] = true;
            visited[par[topo[i]]] = true;
        }
    }
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