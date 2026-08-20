#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;

ll a[MAX], prefixSum[MAX];
int n, q;

void process() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) prefixSum[i] = prefixSum[i-1] ^ a[i-1];
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << (prefixSum[r] ^ prefixSum[l - 1]) << "\n";
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