#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 100005;
const ll INF = (ll) 1e15;
ll dist[MAX], dist_count[MAX], minF[MAX], maxF[MAX];
vector<vector<pair<ll,int>>> adj;
int n,m;

void dijkstra(int source){
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    for (int i = 1; i <= n; i++){
        dist[i] = INF;
        minF[i] = INF;
        maxF[i] = 0;
    }
    minF[source] = 0;
    maxF[source] = 0;
    dist[source] = 0;
    dist_count[source] = 1;
    pq.push({0, source});
    while (!pq.empty()){
        pair<ll,int> a = pq.top();
        pq.pop();
        ll cost = a.first; 
        ll u = a.second;
        if (cost > dist[u]) continue;
        for (pair<ll,int> &p : adj[u]){
            ll new_cost = p.first + cost; 
            ll v = p.second;
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                minF[v] = minF[u] + 1;
                maxF[v] = maxF[u] + 1;
                dist_count[v] = dist_count[u];
                dist_count[v] %= MOD;
                pq.push({new_cost, v});
            }
            else if (new_cost == dist[v]) {
                dist_count[v] = (dist_count[v] + dist_count[u]) % MOD;
                minF[v] = min(minF[v], minF[u] + 1);
                maxF[v] = max(maxF[v], maxF[u] + 1);
            }
        }
    }
}

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    dijkstra(1);
    cout << dist[n] << " " << dist_count[n] << " " << minF[n] << " " << maxF[n];
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