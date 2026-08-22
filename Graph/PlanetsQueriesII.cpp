#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
const int LOG = 20;
int n, q, visited[MAX], cycle;
int up[LOG][MAX],cycle_id[MAX],cycle_size[MAX],cycle_pos[MAX],depth[MAX],pos[MAX];
vector<int> path;

// up : binary lifting that access 2^j ancestor in O(1)
// cycle_id: store the cycle that the node contains or leading to
// cycle_size: store the cycle that the node is in or leading to
// cycle_pos: store the position in the cycle
// pos: store the position in path 
// depth: the number of step to reach the start of the cycle


void dfs(int u){
    visited[u] = 1;
    pos[u] = path.size();
    path.push_back(u);
    int v = up[0][u];
    if (visited[v] == 0) dfs(v);
    else if (visited[v] == 1){
        cycle++;
        int start = pos[v];
        int cycle_len = (int)path.size() - start;
        for (int i = start; i < (int) path.size(); i++){
            cycle_pos[path[i]] = i - start;
            cycle_size[path[i]] = cycle_len;
            cycle_id[path[i]] = cycle;
            depth[path[i]] = 0;
        }
    }
    if (cycle_id[u] == 0){
        cycle_id[u] = cycle_id[v];
        depth[u] = depth[v] + 1;
        cycle_size[u] = cycle_size[v];
    }
    path.pop_back();
    visited[u] = 2;
}

void binary_lifting(){
    for (int i = 1; i < LOG; i++){
        for (int j = 1; j <= n; j++){
            up[i][j] = up[i-1][up[i-1][j]];
        }
    }
}

int jump(int k, int u){
    for (int i = 0; i < LOG; i++){
        if ((1 << i) & k){
            u = up[i][u];
        }
    }
    return u;
}

void process() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> up[0][i];
    }   
    binary_lifting();
    for (int i = 1; i <= n; i++){
        if (visited[i] == 0) dfs(i);
    }
    while (q--){
        int u,v;
        cin >> u >> v;
        if (cycle_id[u] != cycle_id[v]){
            cout << -1 << "\n";
        }
        else{
            int ans = -1;
            if (depth[v] == 0 && depth[u] != 0){
                ans = depth[u] - depth[v];
                u = jump(depth[u] - depth[v], u);
                ans += (cycle_pos[v] - cycle_pos[u] + cycle_size[u]) % cycle_size[u];
            }
            else if (depth[v] != 0 && depth[u] == 0){
                ans = -1;
            }
            else if (depth[u] != 0 && depth[v] != 0){
                int dif = depth[u] - depth[v];
                if (dif < 0) ans = -1;
                else{
                    u = jump(dif, u);
                    ans = (u == v ? dif : -1);
                }
            }
            else{
                ans = (cycle_pos[v] - cycle_pos[u] + cycle_size[u]) % cycle_size[u];
            }
            cout << ans << "\n";
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