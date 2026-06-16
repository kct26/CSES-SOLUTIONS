#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MAX = 200005;
const int MOD = 1000000007;
int n, m, nxt[MAX], visited[MAX], pos[MAX];
vector<int> path, ans;

void dfs(int u){
    visited[u] = 1;
    pos[u] = path.size();
    path.push_back(u);
    int v = nxt[u];
    if (visited[v] == 0) dfs(v);
    else if (visited[v] == 1){
        int cycle_size = pos[u] - pos[v] + 1;
        int cur_pos = (int) path.size() - 1;
        while (cur_pos >= pos[v]){
            ans[path[cur_pos]] = cycle_size;
            cur_pos--;
        }
        int k = 1;
        while (cur_pos >= 0){
            ans[path[cur_pos]] = cycle_size + k;
            cur_pos--;
            k++;
        }
    }
    else{
        int cycle_size = ans[v];
        int cur_pos = (int) path.size() - 1;
        int k = 1;
        while (cur_pos >= 0){
            ans[path[cur_pos]] = cycle_size + k;
            k++;
            cur_pos--;
        }
    }
    visited[u] = 2;
    path.pop_back();
}

void process() {
    cin >> n;
    ans.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> nxt[i];
    }
    for (int i = 1; i <= n; i++){
        if (visited[i] == 0) dfs(i);
    }
    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
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