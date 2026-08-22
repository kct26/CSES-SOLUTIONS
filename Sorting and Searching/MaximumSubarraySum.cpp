#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n;
ll a[MAX];

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = a[0];
    ll cur = a[0];
    for (int i = 1; i < n; i++){
        if (cur + a[i] < a[i]) cur = 0;
        cur += a[i];
        ans = max(cur,ans);
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