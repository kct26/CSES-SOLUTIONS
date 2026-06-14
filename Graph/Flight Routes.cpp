#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 100005;
int n,m,k;
priority_queue<ll> dist[MAX];
vector<vector<pair<ll,int>>> adj;

void dijkstra(int source){
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, source});
    dist[source].push(0);
    while (!pq.empty()){
        pair<ll,int> a = pq.top();
        pq.pop();
        ll cost = a.first;
        int src = a.second;
        if (cost > dist[src].top()) continue;
        for (pair<ll,int> &p : adj[src]){
            ll new_cost = p.first + cost;
            int dst = p.second;

            if ((int)dist[dst].size() < k){
                dist[dst].push(new_cost);
                pq.push({new_cost, dst});
            }
            else if (new_cost < dist[dst].top()){
                dist[dst].pop();
                dist[dst].push(new_cost);
                pq.push({new_cost,dst});
            }
        }
    }
}

void process() {
    cin >> n >> m >> k;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    dijkstra(1);
    vector<ll> ans;
    priority_queue<ll> d = dist[n];
    while (!d.empty()){
        ans.push_back(d.top());
        d.pop();
    }
    reverse(ans.begin(), ans.end());
    for (ll& u : ans) cout << u << " ";

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