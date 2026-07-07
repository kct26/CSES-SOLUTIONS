#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 25;
const ll INF = 4e18;
int n;
ll a[MAX], dp[1 << MAX];
ll total, ans;

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    ans = INF;
    for (int bitmask = 0; bitmask < (1 << n); bitmask++){
        for (int i = 0; i < n; i++) {
            if ((bitmask & (1 << i)) == 0) continue;
            dp[bitmask] += a[i];
        }
        ll remain = total - dp[bitmask];
        ll dif = abs(remain - dp[bitmask]);
        ans = min(ans, dif);
    }
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