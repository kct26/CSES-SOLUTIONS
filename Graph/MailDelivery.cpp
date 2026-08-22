#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
vector<vector<pair<int,int>>> adj;
vector<int> route;
int degree[MAX];
bool used[MAX];
int n,m;

void dfs(int start){
    stack<int> st;
    st.push(start);
    while (!st.empty()){
        int cur = st.top();
        while (!adj[cur].empty() && used[adj[cur].back().second]) {
            adj[cur].pop_back();
        }
        if (adj[cur].empty()){
            route.push_back(cur);
            st.pop();
        }
        else{
            st.push(adj[cur].back().first);
            used[adj[cur].back().second] = true;
            adj[cur].pop_back();
        }
    }
}

void process() {
    cin >> n >> m;
    adj.resize(n + 1);
    int id = 0;
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        id++;
        adj[u].push_back({v,id});
        adj[v].push_back({u,id});
        degree[u]++;
        degree[v]++;
    }
    for (int i = 1; i <= n; i++){
        if (degree[i] % 2 != 0) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    dfs(1);
    if ((int) route.size() != m + 1){
        cout << "IMPOSSIBLE";
        return;
    }
    reverse(route.begin(), route.end());
    for (int &u : route) cout << u << " ";


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