#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 100005;
int n,m;
int inDegree[MAX];
vector<vector<int>> adj;

void kahn(){
    vector<int> topo;
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int &v : adj[u]){
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(v);
        }
    }
    if ((int) topo.size() != n){
        cout << "IMPOSSIBLE";
        return;
    }
    for (int &v : topo) cout << v << " ";

}

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        inDegree[v]++;
        adj[u].push_back(v);
    }
    kahn();
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