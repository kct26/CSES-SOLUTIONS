#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 100005;
int n,m,compo;
ll total;
int sz[MAX],par[MAX];
priority_queue<pair<ll,pair<int,int>>, vector<pair<ll,pair<int,int>>>, greater<pair<ll,pair<int,int>>>> pq;

void DSU(){
    compo = n;
    for (int i = 1; i <= n; i++){
        sz[i] = 1;
        par[i] = i;
    }
}

int find_set(int u){
    if (u == par[u]) return u;
    return par[u] = find_set(par[u]);
}

bool union_set(int u, int v){
    int x = find_set(u);
    int y = find_set(v);
    if (x == y) return false;
    if (sz[x] >= sz[y]){
        par[y] = x;
        sz[x] += sz[y];
    }
    else {
        par[x] = y;
        sz[y] += sz[x];
    }
    compo--;
    return true;
}

void process() {
    cin >> n >> m;
    DSU();
    for (int i = 0; i < m; i++){
        int u,v; ll w;
        cin >> u >> v >> w;
        pq.push({w,{u,v}});
    }

    while (!pq.empty()){
        auto x = pq.top();
        pq.pop();
        ll cost = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if (union_set(u,v)){
            total += cost;
            if (compo == 1){
                cout << total;
                return;
            }
        }
    }
    if (compo > 1) cout << "IMPOSSIBLE";
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