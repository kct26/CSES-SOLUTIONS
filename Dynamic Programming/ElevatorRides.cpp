#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 25;

ll w, a[MAX];
int n;
pair<int,int> dp[1 << MAX];


void process() {
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> a[i];
    fill (dp, dp + (1 << n), make_pair(1e9, 1e9));
    dp[0] = {1, 0};
    for (int bitmask = 0; bitmask < (1 << n); bitmask++){
        for (int j = 0; j < n; j++){
            if ((1 << j) & bitmask) continue;
            int next_mask = bitmask | (1 << j);
            if (dp[bitmask].second + a[j] <= w){
                dp[next_mask] = min(dp[next_mask], {dp[bitmask].first, dp[bitmask].second + a[j]});
            }
            else dp[next_mask] = min(dp[next_mask], {dp[bitmask].first + 1, a[j]});
        }
    }
    cout << dp[(1 << n) - 1].first;
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