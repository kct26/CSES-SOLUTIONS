#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
vector<vector<pair<int,int>>> adj;
vector<int> route;
int indegree[MAX], outdegree[MAX];
bool used[MAX];
int n,m;

void dfs(int start){
    stack<int> st;
    st.push(start);
    while (!st.empty()){
        int cur = st.top();
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
        indegree[v]++;
        outdegree[u]++;
    }
    for (int i = 2; i <= n - 1; i++){
        if (indegree[i] != outdegree[i]){
            cout << "IMPOSSIBLE";
            return;
        }
    }
    if (indegree[1] + 1 != outdegree[1] || indegree[n] != outdegree[n] + 1){
        cout << "IMPOSSIBLE";
        return;
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