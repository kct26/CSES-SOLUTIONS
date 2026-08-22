#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 25;

ll n, a[MAX];

ll solve(ll idx, ll sum1, ll sum2){
    if (idx == n) return abs(sum1 - sum2);
    return min(solve (idx + 1, sum1 + a[idx], sum2),
               solve (idx + 1, sum1, sum2 + a[idx]));
}

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = solve(0,0,0);
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