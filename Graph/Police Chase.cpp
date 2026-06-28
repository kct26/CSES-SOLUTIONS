#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 505;
const ll INF = 4e18;
int n,m;
ll totalFlow;

struct Edge{
    int forward,rev;
    ll cap;
};

vector<pair<int,int>> vEdge;
vector<vector<Edge>> adj;
int level[MAX], ptr[MAX];
bool reachable[MAX];

bool bfs(int src, int dst){
    memset(level, -1, sizeof level);
    queue<int> q;
    q.push(src);
    level[src] = 0;
    while (!q.empty()){
        int tmp = q.front();
        q.pop();
        for (Edge &e : adj[tmp]){
            if (level[e.forward] != -1 || e.cap == 0) continue;
            level[e.forward] = level[tmp] + 1;
            q.push(e.forward);
        }
    }
    return level[dst] != -1;
}

ll dfs(int src, int dst, ll pushed){
    if (pushed == 0) return 0;
    if (src == dst) return pushed;
    for (int &i = ptr[src]; i < (int) adj[src].size(); i++){
        Edge &e = adj[src][i];
        if (e.cap == 0 || level[e.forward] != level[src] + 1) continue;
        ll flow = dfs(e.forward, dst, min(pushed, e.cap));
        if (flow == 0) continue;
        e.cap -= flow;
        adj[e.forward][e.rev].cap += flow;
        return flow;
    }
    return 0;
}

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        Edge f = {v, (int)adj[v].size(), 1};
        Edge r = {u, (int)adj[u].size(), 1};
        adj[u].push_back(f);
        adj[v].push_back(r);
        vEdge.push_back({u,v});
    }
    int src = 1;
    int dst = n;
    while (bfs(src,dst)){
        fill (ptr, ptr + n + 1, 0);
        while (ll flow = dfs(src, dst, INF)){
            totalFlow += flow;
        }
    }
    cout << totalFlow << "\n";
    queue<int> q;
    q.push(src);
    reachable[src] = true;
    while (!q.empty()){
        int tmp = q.front();
        q.pop();
        for (Edge& e : adj[tmp]){
            if (e.cap == 0 || reachable[e.forward] == true) continue; 
            reachable[e.forward] = true;
            q.push(e.forward);
        }
    }
    for (auto &[u,v] : vEdge){
        if (reachable[u] != reachable[v]){
            cout << u << " " << v << "\n";
            totalFlow --;
            if (totalFlow == 0) return;
        }
    }
    return;
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