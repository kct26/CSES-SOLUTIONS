#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 505;
int n,m,a[MAX][MAX], ans[MAX][MAX];

// A,B,C,D -> 1,2,3,4

bool isValid (int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool dfs(int x, int y){
    if (x == n) return true;
    vector<bool> remain(5,true);
    remain[a[x][y]] = false;
    if (isValid(x,y-1)) remain[ans[x][y-1]] = false;
    if (isValid(x-1,y)) remain[ans[x-1][y]] = false;
    for (int k = 1; k <= 4; k++) {
        if (remain[k]) {
            ans[x][y] = k;
            if (y + 1 == m) return dfs(x + 1, 0);
            else return dfs(x, y + 1);
        }
    }
    return false;
}
void process() {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char tmp; cin >> tmp;
            if (tmp == 'A') a[i][j] = 1;
            else if (tmp == 'B') a[i][j] = 2;
            else if (tmp == 'C') a[i][j] = 3;
            else a[i][j] = 4;
        }
    }
    bool check = dfs(0,0);
    if (!check){
        cout << "IMPOSSIBLE";
        return;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (ans[i][j] == 1) cout << "A";
            else if (ans[i][j] == 2) cout << "B";
            else if (ans[i][j] == 3) cout << "C";
            else if (ans[i][j] == 4) cout << "D";
        }
        cout << "\n";
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