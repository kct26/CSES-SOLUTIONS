#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;
ll n,s;
void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        ll tmp; cin >> tmp;
        s += tmp;
    }
    ll ans = n*(n+1)/2 - s;
    cout << ans;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}