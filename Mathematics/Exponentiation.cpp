#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;

ll cal(ll a, ll exp){
    ll ans = 1;
    a %= MOD;
    while (exp > 0){
        if (exp & 1) ans = ans * a % MOD;
        a = (a * a) % MOD;
        exp >>= 1;
    }
    return ans;
}

void process() {
    ll a,b; cin >> a >> b;
    ll ans = cal(a, b);
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
        process();
    }
    return 0;
}