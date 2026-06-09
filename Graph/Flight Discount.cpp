#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

struct Edge{
    int u,v; ll w;
};

int n,m;
const ll INF = 1e18;
const int MAX = 100005;
ll dist1[MAX], dist2[MAX];
vector<vector<pair<ll,int>>> adj,radj;
vector<Edge> e;

void dijkstra(int source, ll dist[], vector<vector<pair<ll,int>>> &graph){
    fill(dist, dist + n + 1, INF);
    dist[source] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, source});
    while (!pq.empty()){
        auto [cost, u] = pq.top();
        pq.pop();
        if (dist[u] < cost) continue;
        for (auto &[w,v] : graph[u]){
            ll new_cost = dist[u] + w;
            if (new_cost < dist[v]){
                dist[v] = new_cost;
                pq.push({dist[v], v});
            }
        }
    }
}

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    radj.resize(n + 1);
    e.resize(m + 1);
    for (int i = 0; i < m; i++){
        int u,v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        radj[v].push_back({w,u});
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
    }
    dijkstra(1,dist1,adj);
    dijkstra(n,dist2,radj);

    // dist[1][u] + cost[u][v]/2 + dist[v][n]
    
    ll ans = INF;

    for (Edge &a : e){
        int src = a.u;
        int dst = a.v;
        int cost = a.w;
        ans = min(ans, dist1[src] + cost/2 + dist2[dst]);
    }
    cout << ans;

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