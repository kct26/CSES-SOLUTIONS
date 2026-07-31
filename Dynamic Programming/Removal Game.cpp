#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 5005;
int n;
ll a[MAX], pref[MAX], cache[MAX][MAX];

ll sum(int left, int right){
    return pref[right] - pref[left] + a[left];
}

ll dfs(int left, int right){
    if (left > right) return 0;
    if (left == right){
        return a[left];
    }
    if (cache[left][right] < 4e18) return cache[left][right];
    ll pick_left = a[left] + sum(left + 1, right) - dfs(left + 1, right);
    ll pick_right = a[right] + sum(left, right - 1) - dfs(left, right - 1);
    cache[left][right] = max(pick_left, pick_right);
    return cache[left][right];
}


void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    pref[0] = a[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i-1] + a[i];
    memset(cache, 0x3f, sizeof cache);
    ll ans = dfs(0, n - 1);
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