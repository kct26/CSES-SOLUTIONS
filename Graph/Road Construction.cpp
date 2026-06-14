#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 100005;
int n,m,compo,current_max;
int sz[MAX],par[MAX];

void DSU(){
    compo = n;
    current_max = 1;
    for (int i = 1; i <= n; i++){
        sz[i] = 1;
        par[i] = i;
    }
}

int find_set(int u){
    if (u == par[u]) return u;
    return par[u] = find_set(par[u]);
}

void union_set(int u, int v){
    int x = find_set(u);
    int y = find_set(v);
    if (x == y) return;
    if (sz[x] >= sz[y]){
        par[y] = x;
        sz[x] += sz[y];
        current_max = max(current_max, sz[x]);
    }
    else {
        par[x] = y;
        sz[y] += sz[x];
        current_max = max(current_max, sz[y]);
    }
    compo--;
    return;
}

void process() {
    cin >> n >> m;
    DSU();
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        union_set(u,v);
        cout << compo << " " << current_max << "\n";
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