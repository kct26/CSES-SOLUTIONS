#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 505;
const ll INF = 4e18;

struct Edge{
    int rev,forward;
    ll cap;
    bool og = false;
};

int level[MAX], tmp[MAX];
int n,m;
vector<vector<Edge>> adj;
bool visited[MAX];
bool og[MAX][MAX];

bool bfs(int src, int dst){
    memset(level, -1, sizeof level);
    level[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (Edge &e : adj[cur]){
            if (e.cap == 0 || level[e.forward] != -1) continue;
            level[e.forward] = level[cur] + 1;
            q.push(e.forward);
        }
    }
    return level[dst] != -1;
}

ll dfs(int src, int dst, ll pushed){
    if (pushed == 0) return 0;
    if (src == dst) return pushed;
    for (int &i = tmp[src]; i < (int) adj[src].size(); i++){
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

bool dfsPath(int cur, int dst, vector<int> &path){
    if (cur == dst) return true;
    visited[cur] = true;
    for (Edge &e : adj[cur]){
        if (e.cap != 0 || visited[e.forward] || !e.og) continue;
        path.push_back(e.forward);
        e.cap = 1;
        if (dfsPath(e.forward, dst, path)){
            return true;
        }
        path.pop_back();
        e.cap = 0;
    }
    return false;
}

void addEdge(int src, int dst, int c){
    Edge a = {(int)adj[dst].size(), dst, c, true};
    Edge b = {(int)adj[src].size(), src, 0, false};
    adj[src].push_back(a);
    adj[dst].push_back(b);
}

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        addEdge(u,v,1);
        
    }
    int src = 1;
    int dst = n;
    ll totalFlow = 0;
    while (bfs(src, dst)){
        fill (tmp, tmp + n + 1, 0);
        while (ll flow = dfs(src, dst, INF)){
            totalFlow += flow;
        }
    }
    cout << totalFlow << "\n";
    for (int i = 0; i < totalFlow; i++){
        memset(visited, false, sizeof visited);
        vector<int> path = {1};
        if (dfsPath(1, n, path)){
            cout << (int) path.size() << "\n";
            for (int& v : path) cout << v << " ";
            cout << "\n";
        }
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