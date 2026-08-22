#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n,m;
int compo[MAX];
bool visited[MAX];
vector<vector<int>> adj, radj;
vector<int> path;
vector<char> ans;

// a or b <-> !a -> b or !b -> a
// topping 1 : 0, 1
// topping 2 : 2, 3
// .. 
// topping n: 2 * n - 2, 2 * n - 1

int convert(char ch , int x){
    x--;
    if (ch == '+') return 2 * x + 1;
    return 2 * x;
}

int neg(int x){
    return x^1;
    // flip the last bit ( - 1 or + 1)
}

void dfs1(int u){
    visited[u] = true;
    for (int &v : adj[u]){
        if (!visited[v]) dfs1(v);
    }
    path.push_back(u);
}

void dfs2(int u){
    visited[u] = true;
    for (int &v : radj[u]){
        if (!visited[v]) {
            compo[v] = compo[u];
            dfs2(v);
        }
    }
}

void process() {
    cin >> n >> m;
    adj.resize(2*m+5);
    radj.resize(2*m+5);
    ans.resize(m);
    for (int i = 0; i < n; i++){
        char a,b;
        int x1,x2;
        cin >> a >> x1 >> b >> x2;
        int nodeA = convert(a,x1);
        int nodeB = convert(b,x2);
        adj[neg(nodeA)].push_back(nodeB);
        adj[neg(nodeB)].push_back(nodeA);
        radj[nodeB].push_back(neg(nodeA));
        radj[nodeA].push_back(neg(nodeB));
    }
    for (int i = 0; i < 2 * m; i++){
        if (!visited[i]) dfs1(i);
    }
    reverse(path.begin(), path.end());
    memset(visited, false, sizeof visited);
    int id = 0;
    for (int &u : path){
        if (!visited[u]) {
            id++;
            compo[u] = id;
            dfs2(u);
        }
    }
    for (int i = 0; i < m; i++){
        if (compo[2 * i] == compo[2 * i + 1]) {
            cout << "IMPOSSIBLE";
            return;
        }
        ans[i] = (compo[2 * i] < compo[2 * i + 1] ? '+' : '-');
    }
    for (int i = 0; i < m; i++) cout << ans[i] << " ";


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