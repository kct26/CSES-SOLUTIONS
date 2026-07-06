#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
ll n;

void process() {
    cin >> n;
    for (ll i = 1; i <= n; i++){
        ll ans = i*i*(i*i-1)/2;
        ans -= 4*(i-1)*(i-2);
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