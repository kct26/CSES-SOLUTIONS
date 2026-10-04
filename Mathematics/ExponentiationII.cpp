#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;

ll power(ll a, ll b, ll mod){
    ll res = 1;
    a %= mod;
    while (b){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll expo = power(b, c, MOD - 1);
    ll ans = power(a, expo, MOD);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}