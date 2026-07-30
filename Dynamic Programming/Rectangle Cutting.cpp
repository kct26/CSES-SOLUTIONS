#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 505;
const int INF = INT_MAX;
int a, b, dp[MAX][MAX];

int dfs (int a, int b){
    if (a == b) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    int check = INF;
    for (int i = 1; i < a; i++) check = min(check, dfs(a - i, b) + dfs(i, b));
    for (int j = 1; j < b; j++) check = min(check, dfs(a, b - j) + dfs(a, j));
    dp[a][b] = check + 1;
    return dp[a][b];
}


void process() {
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    int ans = dfs(a,b);
    cout << ans;
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