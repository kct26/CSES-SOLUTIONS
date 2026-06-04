#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 100005;
int n,m;
int par[MAX], ra[MAX];

void dsu(int s){
    for (int i = 1; i <= s; i++){
        ra[i] = 1;
        par[i] = i;
    }
}

int find(int u){
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}

void union_set(int u, int v){
    int x = find(u);
    int y = find(v);
    if (x == y) return;
    if (ra[x] < ra[y]) par[x] = y;
    else if (ra[y] < ra[x]) par[y] = x;
    else{
        par[x] = y;
        ra[y]++;
    }
}

void process() {
    cin >> n >> m;
    dsu(n);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        union_set(u,v);
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++){
        if (par[i] == i){
            cnt++;
            ans.push_back(i);
        }
    }
    cout << cnt - 1 << "\n";
    for (int i = 1; i < cnt; i++){
        cout << ans[i-1] << " " << ans[i] << "\n";
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