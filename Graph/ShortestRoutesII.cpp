#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const ll INF = (ll) 1e12;
const ll MAX = 505;
ll n,m,q;
ll dist[MAX][MAX];

void process() {
    cin >> n >> m >> q;
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= n; j++){
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for (ll i = 0; i < m; i++){
        ll u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v],w);
        dist[v][u] = min(dist[v][u],w);
    }
    for (ll k = 1; k <= n; k++){
        for (ll i = 1; i <= n; i++){
            for (ll j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (q--){
        ll u,v;
        cin >> u >> v;
        cout << (dist[u][v] >= INF ? -1 : dist[u][v]);
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin >> test;
    while (test--) {
        process();
    }
    return 0;
}