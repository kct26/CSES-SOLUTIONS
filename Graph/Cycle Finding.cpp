#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

struct Edge{
    int u,v;
    ll w;
};

const ll INF = 1e18;
const int MAX = 2505;
int n,m, par[MAX];
vector<Edge> e;
ll dist[MAX];

void bellman_ford(){
    int update = - 1;
    for (int i = 1; i <= n; i++){
        update = -1;
        for (Edge &a : e){
            int u = a.u, v = a.v;
            ll w = a.w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
                update = v;
            }
        }
        if (update == -1) {
            cout << "NO";
            return;
        }
    }
    cout << "YES" << "\n";
    for (int i = 1; i <= n; i++){
        update = par[update];
    }
    vector<int> cycle;
    cycle.push_back(update);
    int cur = par[update];
    while (cur != update){
        cycle.push_back(cur);
        cur = par[cur];
    }
    cycle.push_back(update);
    reverse(cycle.begin(), cycle.end());
    for (int &s : cycle){
        cout << s << " ";
    }
    return;
}

void process() {
    cin >> n >> m;
    e.resize(m);
    for (int i = 0; i < m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    bellman_ford();
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