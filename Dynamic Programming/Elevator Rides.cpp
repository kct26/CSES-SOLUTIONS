#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 23;
int n;
ll x, a[MAX];
pair<int, ll> dp[1 << MAX]; // dp[bitmask] = {minimum rides, current weight}

void process() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    fill(dp, dp + (1 << n), make_pair(n + 1, 0LL));
    dp[0] = {1, 0};
    for (int bitmask = 0; bitmask < 1 << n; bitmask++){
        for (int j = 0; j < n; j++){
            if (bitmask & (1 << j)) continue; // have  included this person
            pair<int,ll> p = dp[bitmask];
            int min_ride = p.first, current_weight = p.second;
            if (current_weight + a[j] <= x) current_weight += a[j];
            else {
                min_ride++;
                current_weight = a[j];
            }
            int next_mask = bitmask | (1 << j);
            dp[next_mask] = min(dp[next_mask], {min_ride, current_weight});
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