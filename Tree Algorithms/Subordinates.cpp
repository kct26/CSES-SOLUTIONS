#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 200005;
int n, sz[MAX];
vector<vector<int>> adj;


void dfs(int root){
    if (adj[root].size() == 0) return;
    for (int &v : adj[root]){
        dfs(v);
        sz[root] += sz[v];
    }
    return;
}

void process() {
    cin >> n;
    adj.resize(n + 1);
    fill(sz, sz + n + 1, 1);
    for (int i = 2; i <= n; i++){
        int boss; cin >> boss;
        adj[boss].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++){
        cout << (sz[i] == 1 ? 0 : sz[i] - 1) << " ";
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