#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 1005;
int a[MAX], b[MAX], dp[MAX][MAX];
int n, m;

void process() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << "\n";
    vector<int> ans;
    while (n > 0 && m > 0){
        if (a[n-1] == b[m-1]){
            ans.push_back(a[n-1]);
            n--;
            m--;
        }
        else if (dp[n-1][m] > dp[n][m-1]) n--;
        else m--;
    }
    for (int i = (int) ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
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