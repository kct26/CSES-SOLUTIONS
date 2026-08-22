#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const ll INF = LLONG_MAX;
const ll MAX = (ll) 1e5+7;
ll dist[MAX],n,m;
vector<vector<pair<ll,ll>>> adj;

void dijkstra(ll src){
    dist[src] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto [cur_dist, u] = pq.top();
        pq.pop();
        if (dist[u] < cur_dist) continue;
        for (auto &[w,v] : adj[u]){
            ll new_dist = dist[u] + w;
            if (new_dist < dist[v]){
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }
}

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    fill(dist, dist + n + 1, INF);
    for (ll i = 0; i < m; i++){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    dijkstra(1);
    for (ll i = 1; i <= n; i++){
        cout << dist[i] << " ";
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