#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int mod = 1000000007;
const int MAX = 200005;
ll a[MAX];
int n;
 
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i < n; i++){
        if (a[i] < a[i-1]) {
            ans += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
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