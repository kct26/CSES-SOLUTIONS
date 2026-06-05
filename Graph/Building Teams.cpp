#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 100005;
int n,m,color[MAX];
vector<vector<int>> adj;

bool bfs(int source){
    queue<int> q;
    q.push(source);
    color[source] = 1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int &v : adj[u]){
            if (color[v] == 0){
                color[v] = 3 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u]) return false;
        }
    }
    return true;
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
        if (color[i] == 0){
            if (!bfs(i)){
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << color[i] << " ";
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