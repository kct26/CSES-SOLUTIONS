#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 1000005;
ll a[MAX], b[MAX], n;

void precal(){
    a[1] = 1; // placing one 2x1 block at top
    b[1] = 1; // placing two 1x1 block at top
    for (int i = 2; i < MAX; i++){
        a[i] = (b[i-1] + 2 * a[i-1]) % MOD; // extend or place new
        b[i] = (a[i-1] + 4 * b[i-1]) % MOD;
    }
}

void process() {
    cin >> n;
    ll ans = (a[n] + b[n]) % MOD;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    precal();
    int test = 1;
    cin >> test;
    while (test--) {
        process();
    }
    return 0;
}