#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 505;
const ll INF = 4e18;

struct Edge{
    int forward,rev;
    ll cap;
};

vector<vector<Edge>> adj;
int n,m;
int level[MAX], ptr[MAX];

bool bfs(int src, int dst){
    memset(level, -1, sizeof level);
    level[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (Edge &e : adj[u]){
            if (e.cap == 0 || level[e.forward] != -1) continue;
            level[e.forward] = level[u] + 1;
            q.push(e.forward);
        }
    }
    return level[dst] != -1;
}

ll dfs(int src, int dst, ll pushed){
    if (pushed == 0) return 0;
    if (src == dst) return pushed;
    for (int &i = ptr[src]; i < (int)adj[src].size(); i++){
        Edge& cur = adj[src][i];
        if (cur.cap == 0 || level[cur.forward] != level[src] + 1) continue;
        ll flow = dfs(cur.forward, dst, min(cur.cap,pushed));
        if (flow == 0) continue;
        adj[cur.forward][cur.rev].cap += flow;
        cur.cap -= flow; 
        return flow;
    }
    return 0;
}

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v;
        ll cap;
        cin >> u >> v >> cap;
        Edge f= {v,(int)adj[v].size(),cap};
        Edge r = {u,(int)adj[u].size(),0};
        adj[u].push_back(f);
        adj[v].push_back(r);
    }
    int src = 1, dst = n;
    ll totalFlow = 0;
    while (bfs(src,dst)){
        fill(ptr, ptr + n + 1, 0);
        while (ll flow = dfs(src, dst, INF)){
            totalFlow += flow;
        }
    }
    cout << totalFlow;
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