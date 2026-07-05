#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;
const int MAX = 1005;
const ll INF = 4e18;

struct Edge{
    int forward,rev;
    ll cap;
};

vector<vector<Edge>> adj;
int n,m,k;
int level[MAX], ptr[MAX];
bool canReach[MAX];

bool bfs(int src, int dst){
    memset(level, -1, sizeof level);
    queue<int> q;
    q.push(src);
    level[src] = 0;
    while (!q.empty()){
        int tmp = q.front();
        q.pop();
        for (Edge &e : adj[tmp]){
            if (e.cap == 0 || level[e.forward] != -1) continue;
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

void solve() {
    cin >> n >> m >> k;
    adj.resize(MAX);
    int g = 500, s = 0, t = 1002;
    for (int i = 0; i < k; i++){
        int u,v;
        cin >> u >> v;
        v += g;
        Edge e = {v, (int)adj[v].size(),1};
        Edge r = {u, (int)adj[u].size(),0};
        adj[u].push_back(e);
        adj[v].push_back(r);
    }
    for (int i = 1; i <= n; i++){
        Edge sb = {i, (int)adj[i].size(),1};
        Edge bs = {s, (int)adj[s].size(),0};
        adj[s].push_back(sb);
        adj[i].push_back(bs);
    }
    for (int i = 1 + g; i <= m + g; i++){
        Edge gt = {t, (int)adj[t].size(),1};
        Edge tg = {i, (int)adj[i].size(),0};
        adj[i].push_back(gt);
        adj[t].push_back(tg);
    }
    ll totalFlow = 0;
    while (bfs(s, t)){
        fill (ptr, ptr + MAX, 0);
        while (ll flow = dfs(s,t,INF)){
            totalFlow += flow;
        }
    }
    cout << totalFlow << "\n";

    for (int boy = 1; boy <= n; boy++){
        for (Edge &e : adj[boy]){
            if (e.cap == 0 && e.forward >= g + 1) {
                cout << boy << " " << e.forward - g << '\n';
            }
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}