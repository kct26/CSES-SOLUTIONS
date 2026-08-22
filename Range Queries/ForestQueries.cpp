#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 1005;
int a[MAX][MAX], pref[MAX][MAX];
int n, q;

void process() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
        char tmp; cin >> tmp;
        if (tmp == '*') a[i][j]++;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i-1][j-1];
        }
    }
    while (q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = pref[x2][y2] - pref[x2][y1-1] - pref[x1 - 1][y2] + pref[x1-1][y1-1];
        cout << ans << "\n";
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